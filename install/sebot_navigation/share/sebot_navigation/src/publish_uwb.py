import rclpy
from rclpy.node import Node
from geometry_msgs.msg import PoseStamped
import math

class UwbFixedGoalPublisher(Node):
    def __init__(self):
        super().__init__('uwb_fixed_goal_publisher')
        
        self.publisher_ = self.create_publisher(PoseStamped, '/goal_pose', 10)

        self.STATIC_OFFSET_X = 1.25 
        self.STATIC_OFFSET_Y = 0.85  
        self.STATIC_YAW_OFFSET = 0.0 

        self.get_logger().info('Node Goal Pose với Gốc Cố Định đã sẵn sàng.')
        self.ask_for_goal()

    def publish_goal(self, target_uwb_x, target_uwb_y, target_yaw_deg):
        # 1. Tính toán khoảng cách tương đối so với Gốc Cố Định
        dx = target_uwb_x - self.STATIC_OFFSET_X
        dy = target_uwb_y - self.STATIC_OFFSET_Y

        # 2. Xoay tọa độ để khớp với hướng của bản đồ (Rotation Matrix)
        # Nếu trục UWB và Map đã thẳng hàng thì bước này ko đổi giá trị
        cos_t = math.cos(-self.STATIC_YAW_OFFSET)
        sin_t = math.sin(-self.STATIC_YAW_OFFSET)

        map_x = dx * cos_t - dy * sin_t
        map_y = dx * sin_t + dy * cos_t

        msg = PoseStamped()
        msg.header.stamp = self.get_clock().now().to_msg()
        msg.header.frame_id = 'map'
        
        msg.pose.position.x = map_x
        msg.pose.position.y = map_y
        
        yaw_rad = math.radians(target_yaw_deg) - self.STATIC_YAW_OFFSET
        q = self.euler_to_quaternion(0, 0, yaw_rad)
        msg.pose.orientation.x = q[0]
        msg.pose.orientation.y = q[1]
        msg.pose.orientation.z = q[2]
        msg.pose.orientation.w = q[3]

        self.publisher_.publish(msg)
        self.get_logger().info(f'Goal gửi đi: Map X={map_x:.2f}, Y={map_y:.2f}')

    def euler_to_quaternion(self, roll, pitch, yaw):
        qx = math.sin(roll/2) * math.cos(pitch/2) * math.cos(yaw/2) - math.cos(roll/2) * math.sin(pitch/2) * math.sin(yaw/2)
        qy = math.cos(roll/2) * math.sin(pitch/2) * math.cos(yaw/2) + math.sin(roll/2) * math.cos(pitch/2) * math.sin(yaw/2)
        qz = math.cos(roll/2) * math.cos(pitch/2) * math.sin(yaw/2) - math.sin(roll/2) * math.sin(pitch/2) * math.cos(yaw/2)
        qw = math.cos(roll/2) * math.cos(pitch/2) * math.cos(yaw/2) + math.sin(roll/2) * math.sin(pitch/2) * math.sin(yaw/2)
        return [qx, qy, qz, qw]

    def ask_for_goal(self):
        try:
            while rclpy.ok():
                print("\n--- ĐIỀU KHIỂN ROBOT THEO TỌA ĐỘ UWB ---")
                x = float(input("Đích X (0-4m): "))
                y = float(input("Đích Y (0-4m): "))
                self.publish_goal(x, y, 0.0)
        except EOFError: pass

def main():
    rclpy.init()
    node = UwbFixedGoalPublisher()
    rclpy.spin(node)
    rclpy.shutdown()

if __name__ == '__main__':
    main()