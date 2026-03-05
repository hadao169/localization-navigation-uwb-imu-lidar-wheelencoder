// #include <deque>
// #include <iostream>
// #include <memory>
// #include <string>
// #include <cmath>
// #include <numeric>
// #include "rclcpp/rclcpp.hpp"
// #include "tf2_ros/transform_listener.h"
// #include "tf2_ros/buffer.h"
// #include "tf2_geometry_msgs/tf2_geometry_msgs.hpp"
// #include "geometry_msgs/msg/pose_stamped.hpp"
// #include "sensor_msgs/msg/imu.hpp"
// #include "nav_msgs/msg/odometry.hpp"
// #include "tf2/utils.h"
// #include "Eigen/Dense"

// using std::placeholders::_1;

// class UwbTransformNode : public rclcpp::Node {
// public:
//     UwbTransformNode() : Node("uwb_transform_node") {
//         tf_buffer_ = std::make_unique<tf2_ros::Buffer>(this->get_clock());
//         tf_listener_ = std::make_unique<tf2_ros::TransformListener>(*tf_buffer_);

//         uwb_sub_ = this->create_subscription<geometry_msgs::msg::PoseStamped>(
//             "/dwm1001/id_DW878F/pose", 10, std::bind(&UwbTransformNode::uwbCallback, this, _1));
//         imu_sub_ = this->create_subscription<sensor_msgs::msg::Imu>(
//             "imu/data", 10, std::bind(&UwbTransformNode::imuCallback, this, _1));
        
//         uwb_pub_ = this->create_publisher<nav_msgs::msg::Odometry>("odometry/uwb_data", 10);

//         sample_count_ = 50;
//         count_yaw_ = 0; count_uwb_ = 0;
//         yaw_accum_ = 0.0; pos_accum_ = Eigen::Vector2d(0.0, 0.0);
//         has_yaw0_ = false; has_uwbPos0_ = false;
        
//         xy_covariance_ = 0.01; 
//         yaw_covariance_ = 0.05;

//         RCLCPP_INFO(this->get_logger(), "UWB Node Started. Noise handling enabled.");
//     }

// private:
//     void imuCallback(const sensor_msgs::msg::Imu::SharedPtr msg) {
//         imu_history_.push_back(*msg);
//         if (imu_history_.size() > 200) imu_history_.pop_front();

//         if (!has_yaw0_) {
//             double yaw = tf2::getYaw(msg->orientation);
//             yaw_accum_ += yaw;
//             count_yaw_++;
//             if (count_yaw_ >= sample_count_) {
//                 yaw0_ = yaw_accum_ / (double)sample_count_;
//                 has_yaw0_ = true;
//             }
//         }
//     }

//     bool getInterpolatedYaw(const rclcpp::Time& target_time, double& out_yaw) {
//         if (imu_history_.empty()) return false;
//         if (target_time > rclcpp::Time(imu_history_.back().header.stamp)) {
//             out_yaw = tf2::getYaw(imu_history_.back().orientation);
//             return true;
//         }
//         if (target_time < rclcpp::Time(imu_history_.front().header.stamp)) return false;

//         for (size_t i = 0; i < imu_history_.size() - 1; ++i) {
//             rclcpp::Time t1 = imu_history_[i].header.stamp;
//             rclcpp::Time t2 = imu_history_[i+1].header.stamp;
//             if (t1 <= target_time && target_time <= t2) {
//                 double yaw1 = tf2::getYaw(imu_history_[i].orientation);
//                 double yaw2 = tf2::getYaw(imu_history_[i+1].orientation);
//                 if (yaw2 - yaw1 > M_PI) yaw2 -= 2 * M_PI;
//                 if (yaw1 - yaw2 > M_PI) yaw1 -= 2 * M_PI;
//                 double ratio = (target_time - t1).seconds() / (t2 - t1).seconds();
//                 out_yaw = atan2(sin(yaw1 + ratio * (yaw2 - yaw1)), cos(yaw1 + ratio * (yaw2 - yaw1)));
//                 return true;
//             }
//         }
//         return false;
//     }

//     void uwbCallback(const geometry_msgs::msg::PoseStamped::SharedPtr msg) {
//         if (!has_uwbPos0_) {
//             pos_accum_(0) += msg->pose.position.x;
//             pos_accum_(1) += msg->pose.position.y;
//             count_uwb_++;
//             if (count_uwb_ >= sample_count_) {
//                 pos0_x_ = pos_accum_(0) / (double)sample_count_;
//                 pos0_y_ = pos_accum_(1) / (double)sample_count_;
//                 has_uwbPos0_ = true;
//             }
//             return;
//         }

//         if (has_yaw0_ && has_uwbPos0_) {
//             double current_yaw = 0.0;
//             if (!getInterpolatedYaw(msg->header.stamp, current_yaw)) return;

//             double dx = msg->pose.position.x - pos0_x_;
//             double dy = msg->pose.position.y - pos0_y_;

//             double cos_t = std::cos(yaw0_);
//             double sin_t = std::sin(yaw0_);
//             double map_x = dx * cos_t - dy * sin_t;
//             double map_y = dx * sin_t + dy * cos_t;

//             double robot_yaw_map = current_yaw - yaw0_;
//             tf2::Quaternion q_robot;
//             q_robot.setRPY(0, 0, robot_yaw_map);

//             Eigen::Vector2d robot_pos = removeSensorOffset(Eigen::Vector2d(map_x, map_y), q_robot);

//             nav_msgs::msg::Odometry out;
//             out.header.stamp = msg->header.stamp; 
//             out.header.frame_id = "map";
//             out.child_frame_id = "base_footprint";
//             out.pose.pose.position.x = robot_pos(0);
//             out.pose.pose.position.y = robot_pos(1);
//             out.pose.pose.position.z = 0.0;
//             out.pose.pose.orientation = tf2::toMsg(q_robot);

//             // Gán covariance cao để giảm trọng số của UWB trong bộ lọc EKF
//             std::fill(out.pose.covariance.begin(), out.pose.covariance.end(), 0.0);
//             out.pose.covariance[0] = xy_covariance_;  // X
//             out.pose.covariance[7] = xy_covariance_;  // Y
//             out.pose.covariance[14] = 9999.0;           // Z 
//             out.pose.covariance[35] = yaw_covariance_; // Yaw

//             uwb_pub_->publish(out);
//         }
//     }

//     Eigen::Vector2d removeSensorOffset(const Eigen::Vector2d &raw_pos, const tf2::Quaternion &robot_q) {
//         try {
//             auto t = tf_buffer_->lookupTransform("base_link", "uwb_link", tf2::TimePointZero);
//             tf2::Vector3 offset(t.transform.translation.x, t.transform.translation.y, 0.0);
//             tf2::Vector3 rotated_offset = tf2::quatRotate(robot_q, offset);
//             return Eigen::Vector2d(raw_pos(0) - rotated_offset.x(), raw_pos(1) - rotated_offset.y());
//         } catch (...) {
//             return raw_pos;
//         }
//     }

//     std::unique_ptr<tf2_ros::Buffer> tf_buffer_;
//     std::unique_ptr<tf2_ros::TransformListener> tf_listener_;
//     rclcpp::Subscription<geometry_msgs::msg::PoseStamped>::SharedPtr uwb_sub_;
//     rclcpp::Subscription<sensor_msgs::msg::Imu>::SharedPtr imu_sub_;
//     rclcpp::Publisher<nav_msgs::msg::Odometry>::SharedPtr uwb_pub_;
//     std::deque<sensor_msgs::msg::Imu> imu_history_; 
//     double yaw0_, pos0_x_, pos0_y_;
//     bool has_yaw0_, has_uwbPos0_;
//     size_t sample_count_, count_yaw_, count_uwb_;
//     double yaw_accum_;
//     Eigen::Vector2d pos_accum_;
//     double xy_covariance_, yaw_covariance_;
// };

// int main(int argc, char **argv) {
//     rclcpp::init(argc, argv);
//     rclcpp::spin(std::make_shared<UwbTransformNode>());
//     rclcpp::shutdown();
//     return 0;
// }


#include <deque>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <cmath>
#include "rclcpp/rclcpp.hpp"
#include "tf2_ros/transform_listener.h"
#include "tf2_ros/buffer.h"
#include "tf2_geometry_msgs/tf2_geometry_msgs.hpp"
#include "geometry_msgs/msg/pose_stamped.hpp"
#include "sensor_msgs/msg/imu.hpp"
#include "nav_msgs/msg/odometry.hpp"
#include "tf2/utils.h"
#include "Eigen/Dense"

using std::placeholders::_1;

class UwbTransformNode : public rclcpp::Node {
public:
    UwbTransformNode() : Node("uwb_transform_node"), 
                         world_frame_id_("map"),
                         base_link_frame_id_("base_link"),
                         sample_threshold_(30) {
        tf_buffer_ = std::make_unique<tf2_ros::Buffer>(this->get_clock());
        tf_listener_ = std::make_unique<tf2_ros::TransformListener>(*tf_buffer_);

        uwb_sub_ = this->create_subscription<geometry_msgs::msg::PoseStamped>(
            "/dwm1001/id_DW878F/pose", 10, std::bind(&UwbTransformNode::uwbCallback, this, _1));
        imu_sub_ = this->create_subscription<sensor_msgs::msg::Imu>(
            "imu/data", 10, std::bind(&UwbTransformNode::imuCallback, this, _1));
        transform_pub_ = this->create_publisher<nav_msgs::msg::Odometry>("odometry/uwb_data", 10);

        datum_set_ = false;
        uwb_count_ = 0;
        imu_count_ = 0;
        accum_uwb_x_ = 0.0; accum_uwb_y_ = 0.0;
        accum_imu_sin_ = 0.0; accum_imu_cos_ = 0.0;
        
        xy_variance_ = 5.0;
        z_variance_ = 9999.0;
        yaw_variance_ = 9999.0;
        first_uwb_after_datum_ = true;
        max_uwb_jump_ = 0.20; 
        last_valid_uwb_pos_ = Eigen::Vector2d::Zero();
    }

private:
    std::deque<sensor_msgs::msg::Imu> imu_history_;

    bool isOutlier(const Eigen::Vector2d& current_pos) {
        if (first_uwb_after_datum_) {
            last_valid_uwb_pos_ = current_pos;
            first_uwb_after_datum_ = false;
            return false;
        }

        double jump_distance = (current_pos - last_valid_uwb_pos_).norm();

        if (jump_distance > max_uwb_jump_) {
            RCLCPP_WARN(this->get_logger(), "Outlier rejected: Jump of %.3f m > %.3f m", 
                        jump_distance, max_uwb_jump_);
            return true;
        }

        last_valid_uwb_pos_ = current_pos;
        return false;
    }

    void imuCallback(const sensor_msgs::msg::Imu::SharedPtr msg) {
        imu_history_.push_back(*msg);
        if (imu_history_.size() > 200) {
            imu_history_.pop_front();
        }

        if (!datum_set_ && imu_count_ < sample_threshold_) {
            double yaw = tf2::getYaw(msg->orientation);
            accum_imu_sin_ += std::sin(yaw);
            accum_imu_cos_ += std::cos(yaw);
            imu_count_++;
        }
    }

    bool getInterpolatedYaw(const rclcpp::Time& target_time, double& out_yaw) {
        if (imu_history_.empty()) return false;

        if (target_time > rclcpp::Time(imu_history_.back().header.stamp)) {
            out_yaw = tf2::getYaw(imu_history_.back().orientation);
            return true;
        }

        if (target_time < rclcpp::Time(imu_history_.front().header.stamp)) {
            return false;
        }

        for (size_t i = 0; i < imu_history_.size() - 1; ++i) {
            rclcpp::Time t1 = imu_history_[i].header.stamp;
            rclcpp::Time t2 = imu_history_[i+1].header.stamp;

            if (t1 <= target_time && target_time <= t2) {
                double yaw1 = tf2::getYaw(imu_history_[i].orientation);
                double yaw2 = tf2::getYaw(imu_history_[i+1].orientation);
                
                if (yaw2 - yaw1 > M_PI) yaw2 -= 2 * M_PI;
                if (yaw1 - yaw2 > M_PI) yaw1 -= 2 * M_PI;

                double ratio = (target_time - t1).seconds() / (t2 - t1).seconds();
                out_yaw = yaw1 + ratio * (yaw2 - yaw1);
                return true;
            }
        }
        return false;
    }

    void uwbCallback(const geometry_msgs::msg::PoseStamped::SharedPtr msg) {
        if (!datum_set_) {
            if (uwb_count_ < sample_threshold_) {
                accum_uwb_x_ += msg->pose.position.x;
                accum_uwb_y_ += msg->pose.position.y;
                uwb_count_++;
            }
            if (uwb_count_ >= sample_threshold_ && imu_count_ >= sample_threshold_) {
                pos0_uwb_ << (accum_uwb_x_ / uwb_count_), (accum_uwb_y_ / uwb_count_);
                yaw0_ = std::atan2(accum_imu_sin_ / imu_count_, accum_imu_cos_ / imu_count_);
                datum_set_ = true;
                RCLCPP_INFO(this->get_logger(), "DATUM SET");
            }
            return;
        }

        double interpolated_yaw = 0.0;
        if (!getInterpolatedYaw(msg->header.stamp, interpolated_yaw)) return;

        tf2::Quaternion q_interp;
        q_interp.setRPY(0, 0, interpolated_yaw);

        Eigen::Vector2d pos_sensor_world(msg->pose.position.x, msg->pose.position.y);
        Eigen::Vector2d offset_world = getOffsetInWorldFrame(q_interp);
        Eigen::Vector2d pos_robot_world = pos_sensor_world - offset_world;

        double dx = pos_robot_world.x() - pos0_uwb_.x();
        double dy = pos_robot_world.y() - pos0_uwb_.y();

        double cos_t = std::cos(-yaw0_);
        double sin_t = std::sin(-yaw0_);
        double map_x = dx * cos_t - dy * sin_t;
        double map_y = dx * sin_t + dy * cos_t;

        Eigen::Vector2d current_map_pos(map_x, map_y);

        // Remove outline data
        //if (isOutlier(current_map_pos)) return;
        
        nav_msgs::msg::Odometry out_msg;
        out_msg.header.stamp = msg->header.stamp;
        out_msg.header.frame_id = world_frame_id_;
        out_msg.child_frame_id = base_link_frame_id_;
        out_msg.pose.pose.position.x = current_map_pos.x();
        out_msg.pose.pose.position.y = current_map_pos.y();
        tf2::Quaternion q_map_frame;
        double final_yaw = interpolated_yaw - yaw0_;
        q_map_frame.setRPY(0, 0, final_yaw);
        out_msg.pose.pose.orientation = tf2::toMsg(q_map_frame);
        
        std::fill(out_msg.pose.covariance.begin(), out_msg.pose.covariance.end(), 0.0);
        out_msg.pose.covariance[0] = xy_variance_;
        out_msg.pose.covariance[7] = xy_variance_;
        out_msg.pose.covariance[14] = z_variance_;
        out_msg.pose.covariance[21] = 9999.0;
        out_msg.pose.covariance[28] = 9999.0;
        out_msg.pose.covariance[35] = yaw_variance_;

        transform_pub_->publish(out_msg);
    }

    Eigen::Vector2d getOffsetInWorldFrame(const tf2::Quaternion & robot_q) {
        try {
            auto t = tf_buffer_->lookupTransform(base_link_frame_id_, "uwb_link", tf2::TimePointZero);
            tf2::Vector3 offset_local(t.transform.translation.x, t.transform.translation.y, 0.0);
            tf2::Vector3 offset_world = tf2::quatRotate(robot_q, offset_local);
            return Eigen::Vector2d(offset_world.x(), offset_world.y());
        } catch (...) {
            return Eigen::Vector2d(0.0, 0.0);
        }
    }

    std::unique_ptr<tf2_ros::Buffer> tf_buffer_;
    std::unique_ptr<tf2_ros::TransformListener> tf_listener_;
    rclcpp::Subscription<geometry_msgs::msg::PoseStamped>::SharedPtr uwb_sub_;
    rclcpp::Subscription<sensor_msgs::msg::Imu>::SharedPtr imu_sub_;
    rclcpp::Publisher<nav_msgs::msg::Odometry>::SharedPtr transform_pub_;
    std::string world_frame_id_, base_link_frame_id_;
    bool datum_set_;
    size_t uwb_count_, imu_count_, sample_threshold_;
    double accum_uwb_x_, accum_uwb_y_, accum_imu_sin_, accum_imu_cos_, xy_variance_, z_variance_, yaw_variance_, yaw0_;
    Eigen::Vector2d pos0_uwb_;
    bool first_uwb_after_datum_;
    double max_uwb_jump_;
    Eigen::Vector2d last_valid_uwb_pos_;
};

int main(int argc, char **argv) {
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<UwbTransformNode>());
    rclcpp::shutdown();
    return 0;
}