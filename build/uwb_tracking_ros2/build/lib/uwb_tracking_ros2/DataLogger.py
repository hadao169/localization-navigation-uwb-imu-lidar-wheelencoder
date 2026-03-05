import rclpy
from rclpy.node import Node
from nav_msgs.msg import Odometry
from geometry_msgs.msg import PoseStamped, Vector3Stamped
import math, csv, numpy as np
from datetime import datetime

class DataLoggerNode(Node):
    def __init__(self):
        super().__init__('data_logger_node')
        self.enc_sub = self.create_subscription(Odometry, "/ekf_odom", self.enc_cb, 10)
        self.uwb_sub = self.create_subscription(PoseStamped, "/dwm1001/id_DW878F/pose", self.uwb_cb, 10)
        self.imu_sub = self.create_subscription(Vector3Stamped, "/imu/data", self.imu_cb, 10)

        self.enc_x, self.enc_y, self.uwb_x, self.uwb_y = 0.0, 0.0, 0.0, 0.0
        self.yaw, self.yaw_offset = 0.0, None
        self.Tx, self.Ty = 1.36, 2.0
               
        self.filename = f'pos_data_{datetime.now().strftime("%Y%m%d_%H%M%S")}.csv'
        with open(self.filename, mode='w', newline='') as f:
            csv.writer(f).writerow(['Timestamp', 'Enc_XT', 'Enc_YT', 'UWB_X', 'UWB_Y', 'Error'])

    def imu_cb(self, msg):
        # Lay Yaw truc tiep tu truc Z cua Vector3
        raw_yaw = msg.vector.z 
        if self.yaw_offset is None:
            self.yaw_offset = raw_yaw
        self.yaw = raw_yaw - self.yaw_offset

    def enc_cb(self, msg):
        self.enc_x, self.enc_y = msg.pose.pose.position.x, msg.pose.pose.position.y

    def uwb_cb(self, msg):
        self.uwb_x, self.uwb_y = msg.pose.position.x, msg.pose.position.y
        self.log_to_file()

    def log_to_file(self):
        c, s = np.cos(self.yaw), np.sin(self.yaw)
        tx = c * self.enc_x - s * self.enc_y + self.Tx
        ty = s * self.enc_x + c * self.enc_y + self.Ty
        dist = math.sqrt((tx - self.uwb_x)**2 + (ty - self.uwb_y)**2)

        with open(self.filename, mode='a', newline='') as f:
            csv.writer(f).writerow([self.get_clock().now().to_msg().sec, tx, ty, self.uwb_x, self.uwb_y, dist])

def main():
    rclpy.init()
    node = DataLoggerNode()
    try: rclpy.spin(node)
    except KeyboardInterrupt: pass
    finally:
        node.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()