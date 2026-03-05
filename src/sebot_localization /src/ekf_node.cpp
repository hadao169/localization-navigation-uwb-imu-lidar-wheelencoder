#include "rclcpp/rclcpp.hpp"
#include "sensor_msgs/msg/imu.hpp"
#include "nav_msgs/msg/odometry.hpp"
#include "tf2/utils.h"
#include "ekf.hpp"
#include "tf2_geometry_msgs/tf2_geometry_msgs.hpp"
#include <mutex>

using std::placeholders::_1;

class EkfNode : public rclcpp::Node
{
public:
    EkfNode() : Node("ekf_node")
    {
        // Initialize EKF with initial states (x, y, yaw, wz)
        ekf_ = std::make_unique<ExtendedKalmanFilter>(0.0, 0.0, 0.0, 0.0);

        ekf_pub_ = this->create_publisher<nav_msgs::msg::Odometry>("odometry/filtered", 10);

        wheel_sub_ = this->create_subscription<nav_msgs::msg::Odometry>(
            "wheel/odom", 10, std::bind(&EkfNode::wheelCallback, this, _1));
        
        imu_sub_ = this->create_subscription<sensor_msgs::msg::Imu>(
            "imu/data", 10, std::bind(&EkfNode::imuCallback, this, _1));
        
        uwb_sub_ = this->create_subscription<nav_msgs::msg::Odometry>(
            "odometry/uwb_data", 10, std::bind(&EkfNode::uwbCallback, this, _1));

        // Initialize 30Hz Timer (approx. 33.33ms per cycle)
        timer_ = this->create_wall_timer(
            std::chrono::milliseconds(33), std::bind(&EkfNode::timerCallback, this));

        current_v_ = 0.0;
        last_predict_time_ = this->now();
        initialized_ = false;
    }

private:
    std::unique_ptr<ExtendedKalmanFilter> ekf_;
    rclcpp::Publisher<nav_msgs::msg::Odometry>::SharedPtr ekf_pub_;    
    rclcpp::Subscription<nav_msgs::msg::Odometry>::SharedPtr wheel_sub_, uwb_sub_;
    rclcpp::Subscription<sensor_msgs::msg::Imu>::SharedPtr imu_sub_;
    rclcpp::TimerBase::SharedPtr timer_;

    rclcpp::Time last_predict_time_;
    double current_v_;
    bool initialized_;
    std::mutex ekf_mutex_; // Protect EKF data from race conditions between callbacks

    // Utility function to project state forward to time 'now'
    void predictStep(const rclcpp::Time & now)
    {
        double dt = (now - last_predict_time_).seconds();
        
        if (dt > 0) {
            // Limit max dt to prevent filter instability during network lag or system hang
            if (dt > 0.2) dt = 0.033; 
            
            ekf_->predict(current_v_, dt);
            last_predict_time_ = now;
        }
    }

    void wheelCallback(const nav_msgs::msg::Odometry::SharedPtr msg)
    {
        std::lock_guard<std::mutex> lock(ekf_mutex_);
        current_v_ = msg->twist.twist.linear.x;
        predictStep(msg->header.stamp);
        initialized_ = true;
    }

    void imuCallback(const sensor_msgs::msg::Imu::SharedPtr msg)
    {
        if (!initialized_) return;
        std::lock_guard<std::mutex> lock(ekf_mutex_);

        // Sync filter state to sensor timestamp before updating
        predictStep(msg->header.stamp);

        Eigen::VectorXd z(2);
        z << tf2::getYaw(msg->orientation), msg->angular_velocity.z;
        Eigen::VectorXi indices(2);
        indices << 2, 3; // Update Yaw (2) and Angular Velocity (3)
        ekf_->update(z, indices);
    }

    void uwbCallback(const nav_msgs::msg::Odometry::SharedPtr msg)
    {
        if (!initialized_) return;
        std::lock_guard<std::mutex> lock(ekf_mutex_);

        // Sync filter state to sensor timestamp before updating
        predictStep(msg->header.stamp);

        Eigen::VectorXd z(2);
        z << msg->pose.pose.position.x, msg->pose.pose.position.y;
        Eigen::VectorXi indices(2);
        indices << 0, 1; // Update X (0) and Y (1)
        ekf_->update(z, indices);
    }

    void timerCallback()
    {
        if (!initialized_) return;
        
        std::lock_guard<std::mutex> lock(ekf_mutex_);
        rclcpp::Time now = this->now();
        
        // Predict the small time gap from the last sensor update to current timer tick
        predictStep(now);

        Eigen::VectorXd state = ekf_->getState();
        Eigen::MatrixXd P = ekf_->getP();

        nav_msgs::msg::Odometry out_msg;
        out_msg.header.stamp = now;
        out_msg.header.frame_id = "map";
        out_msg.child_frame_id = "base_link";

        out_msg.pose.pose.position.x = state(0);
        out_msg.pose.pose.position.y = state(1);
        
        tf2::Quaternion q;
        q.setRPY(0, 0, state(2));
        out_msg.pose.pose.orientation = tf2::toMsg(q);

        // Map covariance matrix P (4x4) to Odometry covariance (6x6)
        // Helps Nav2 and Rviz understand measurement uncertainty
        std::fill(out_msg.pose.covariance.begin(), out_msg.pose.covariance.end(), 0.0);
        out_msg.pose.covariance[0] = P(0, 0);   // Var X
        out_msg.pose.covariance[7] = P(1, 1);   // Var Y
        out_msg.pose.covariance[35] = P(2, 2);  // Var Yaw

        ekf_pub_->publish(out_msg);
    }
};

int main(int argc, char **argv) {
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<EkfNode>());
    rclcpp::shutdown();
    return 0;
}