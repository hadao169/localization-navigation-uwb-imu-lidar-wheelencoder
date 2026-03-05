import rclpy
from rclpy.node import Node
from nav_msgs.msg import Odometry
import csv
import math
import os
from datetime import datetime

class OptimalTrajectoryLogger(Node):
    def __init__(self):
        super().__init__('optimal_trajectory_logger')

        # 1. Khai báo các Subscription riêng biệt
        self.ekf_sub = self.create_subscription(Odometry, '/odometry/ekf_synced', self.ekf_callback, 10)
        self.uwb_sub = self.create_subscription(Odometry, '/odometry/uwb_data', self.uwb_callback, 10)
        self.wheel_sub = self.create_subscription(Odometry, '/wheel/odom', self.wheel_callback, 10)

        # 2. Khởi tạo các biến lưu trữ dữ liệu tạm thời
        self.ekf_x, self.ekf_y = 0.0, 0.0
        self.wheel_x, self.wheel_y = 0.0, 0.0
        self.t_ekf, self.t_wheel = 0.0, 0.0

        # 3. Khởi tạo file CSV
        time_str = datetime.now().strftime("%Y%m%d_%H%M%S")
        self.filename = f'optimal_callback_log_{time_str}.csv'
        
        with open(self.filename, mode='w', newline='') as f:
            writer = csv.writer(f)
            writer.writerow([
                'Timestamp_UWB', 
                'EKF_X', 'EKF_Y', 
                'UWB_X', 'UWB_Y', 
                'Wheel_X', 'Wheel_Y',
                'Error_EKF_UWB', 'Max_Time_Offset'
            ])

        self.get_logger().info(f'🚀 Logger (Subscribers) started: {self.filename}')

    def ekf_callback(self, msg):
        """Cập nhật dữ liệu EKF mới nhất"""
        self.ekf_x = msg.pose.pose.position.x
        self.ekf_y = msg.pose.pose.position.y
        self.t_ekf = msg.header.stamp.sec + msg.header.stamp.nanosec * 1e-9

    def wheel_callback(self, msg):
        """Cập nhật dữ liệu Wheel Odom mới nhất"""
        self.wheel_x = msg.pose.pose.position.x
        self.wheel_y = msg.pose.pose.position.y
        self.t_wheel = msg.header.stamp.sec + msg.header.stamp.nanosec * 1e-9

    def uwb_callback(self, msg):
        """Khi có dữ liệu UWB mới -> Thực hiện tính toán và ghi log"""
        ux = msg.pose.pose.position.x
        uy = msg.pose.pose.position.y
        t_uwb = msg.header.stamp.sec + msg.header.stamp.nanosec * 1e-9
        
        # Tính toán sai số giữa EKF hiện tại và UWB
        error = math.sqrt((self.ekf_x - ux)**2 + (self.ekf_y - uy)**2)
        
        # Tính độ lệch thời gian giữa tin nhắn UWB này và dữ liệu odom gần nhất
        # Giúp kiểm tra xem odom có bị quá cũ so với UWB không
        time_offset = max(abs(t_uwb - self.t_ekf), abs(t_uwb - self.t_wheel))

        # Ghi dữ liệu vào file
        with open(self.filename, mode='a', newline='') as f:
            writer = csv.writer(f)
            writer.writerow([
                t_uwb, 
                self.ekf_x, self.ekf_y, 
                ux, uy, 
                self.wheel_x, self.wheel_y, 
                error, 
                time_offset
            ])

def main(args=None):
    rclpy.init(args=args)
    node = OptimalTrajectoryLogger()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()