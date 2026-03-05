import rclpy
import time
import serial
import numpy as np

from rclpy.node import Node
from .dwm1001_apiCommands import DWM1001_API_COMMANDS
from .Helpers import get_tag_publisher, update_multitags_list, create_pose_stamped
from .LeastSquare import LeastSquare as ls
from .log_to_csv import CsvLogger
from citrack_ros_msgs.msg import CustomTag
from citrack_ros_msgs.msg import MultiTags


class dwm1001_localizer(Node):

    def __init__(self):
        Node.__init__(self, 'DWM1001_Listener_Mode')

        self.topics = {}
        self.topics_ls = {}
        self.ls_objects = {}
        self.logger = CsvLogger()

        self.multipleTags = MultiTags()
        self.pub_tags = self.create_publisher(
            MultiTags, "/dwm1001/multiTags", 100)

        self.multipleTags_kf = MultiTags()
        self.pub_tags_kf = self.create_publisher(
            MultiTags, "/dwm1001/multiTags_kf", 100)
        
        self.pub_tags_ls = self.create_publisher(
            MultiTags, "/dwm1001/multiTags_ls", 100)

        
        self.declare_parameter('port', '/dev/ttyACM10')
        self.declare_parameter('verbose', True)
        self.declare_parameter('read_rate', 10.0)
        self.declare_parameter('tag_id', 'DW878F')
        self.declare_parameter('mac_id', 'C4:22:04:B9:DE:53')
        self.declare_parameter('use_least_square', False)
        self.declare_parameter('least_square_max_iterations', 20)
        self.declare_parameter('least_square_tolerance', 0.001)

        self.dwm_port = self.get_parameter(
            'port').get_parameter_value().string_value
        self.verbose = self.get_parameter(
            'verbose').get_parameter_value().bool_value
        self.tag_id = self.get_parameter(
            'tag_id').get_parameter_value().string_value
        self.tag_macID = self.get_parameter(
            'mac_id').get_parameter_value().string_value
        self.read_rate = self.get_parameter(
            'read_rate').get_parameter_value().double_value
        self.use_least_square = self.get_parameter(
            'use_least_square').get_parameter_value().bool_value
        self.least_square_max_iterations = self.get_parameter(
            'least_square_max_iterations').get_parameter_value().integer_value
        self.least_square_tolerance = self.get_parameter(
            'least_square_tolerance').get_parameter_value().double_value

        timer_period = 1.0 / self.read_rate
        self.serialPortDWM1001 = serial.Serial(
            port=self.dwm_port,
            baudrate=115200,
            parity=serial.PARITY_NONE,
            bytesize=serial.EIGHTBITS,
            timeout=1.0
        )
        self.timer = self.create_timer(
            timer_period, self.serial_read_callback)

    def initialize_hardware(self):
        self.serialPortDWM1001.close()
        time.sleep(0.1)
        self.serialPortDWM1001.open()

        if (self.serialPortDWM1001.isOpen()):
            self.initializeDWM1001API()
            time.sleep(2)

            if self.use_least_square:
                self.serialPortDWM1001.write(DWM1001_API_COMMANDS.LES)
            else:
                self.serialPortDWM1001.write(DWM1001_API_COMMANDS.LEP)

            self.serialPortDWM1001.write(DWM1001_API_COMMANDS.SINGLE_ENTER)
            serialReadLine = self.serialPortDWM1001.read_until()
            # self.get_logger().info(serialReadLine)
        else:
            raise IOError("Serial Port Failed to Open")

    def shutdown_hardware(self):
        try:
            self.serialPortDWM1001.write(DWM1001_API_COMMANDS.RESET)
            self.serialPortDWM1001.write(DWM1001_API_COMMANDS.SINGLE_ENTER)
            time.sleep(0.5)
            self.serialPortDWM1001.read_until()

            if self.serialPortDWM1001.isOpen():
                self.serialPortDWM1001.close()

        except Exception:
            pass

    def initializeDWM1001API(self):
        self.serialPortDWM1001.write(DWM1001_API_COMMANDS.RESET)
        self.serialPortDWM1001.write(DWM1001_API_COMMANDS.SINGLE_ENTER)
        time.sleep(0.5)
        self.serialPortDWM1001.write(DWM1001_API_COMMANDS.SINGLE_ENTER)
        time.sleep(0.5)
        self.serialPortDWM1001.write(DWM1001_API_COMMANDS.SINGLE_ENTER)

    def _extract_pose_data(self, serialData) -> list | None:
        if not serialData:
            return None
        try:
            serialDataList = [x.strip()
                              for x in serialData.strip().split(b',')]
            if b"POS" not in serialDataList[0]:
                return None

            t_pose_x = float(serialDataList[1].decode('utf-8'))
            t_pose_y = float(serialDataList[2].decode('utf-8'))
            t_pose_z = float(serialDataList[3].decode('utf-8'))
            t_pose_list = [t_pose_x, t_pose_y, t_pose_z]

            if np.isnan(t_pose_list).any():
                return None

            return t_pose_list

        except (IndexError, ValueError):
            return None

    def serial_read_callback(self):
        try:
            serialReadLine = self.serialPortDWM1001.readline() # Input for "LEP" command
            # self.get_logger().info(serialReadLine.decode('UTF-8'))
            if not serialReadLine:
                return
            pose_data = self._extract_pose_data(serialReadLine) # Input for "LES" command
            if self.use_least_square:
                # self.get_logger().info("Using Least Square Positioning")    
                self.publishTagPoseLS(serialReadLine, pose_data)
            if pose_data and not self.use_least_square:
                self.publishTagPositions(pose_data)
        except Exception:
            pass

    def publishTagPoseLS(self, serialReadLine, pose_data):
        
        # For Least Square or get range measurements  
        serialReadLine_str = serialReadLine.decode('UTF-8', errors='ignore')
        raw_uwb_data = serialReadLine_str.strip().split() # ['A1[...]=...', 'A2[...]=...', ...]
        self.logger.log_raw(raw_uwb_data)
        tag_id = self.tag_id

        if tag_id not in self.ls_objects:
            self.ls_objects[tag_id] = ls()
        ls_object = self.ls_objects[tag_id]

        ls_object.process_uwb_data(raw_uwb_data)
        estimated_x, estimated_y = ls_object.estimate_position(
                max_iterations=self.least_square_max_iterations, tolerance=self.least_square_tolerance)
        # self.get_logger().info(f"[LS] Estimated: x={estimated_x}, y={estimated_y}")

        xyz = [estimated_x, estimated_y, 0.0]
        ps = create_pose_stamped(self, xyz, tag_id)
        pub = get_tag_publisher(self, self.topics_ls, self.tag_id , suffix="pose_ls")
        pub.publish(ps)

        tag = CustomTag()
        tag.header = ps.header
        tag.pose_x, tag.pose_y, tag.pose_z = xyz
        tag.orientation_w = ps.pose.orientation.w
        if not hasattr(self, "multipleTags_ls"):
            self.get_logger().info("[LS] Creating new MultiTags_ls")
            self.multipleTags_ls = MultiTags()
        update_multitags_list(self.multipleTags_ls, tag, tag_id)
        self.pub_tags_ls.publish(self.multipleTags_ls)
        
        # For EKF
        pos = ls_object.original_position
        ps_ekf = create_pose_stamped(self, pos, tag_id)
        pub_ekf = get_tag_publisher(
            self, self.topics, self.tag_id, suffix="pose")
        pub_ekf.publish(ps_ekf)

    def publishTagPositions(self, pose_data: list):
        """Publish raw pose data (Non-KF) to ROS."""

        tag_id = str(self.tag_id)
        tag_macID = self.tag_macID

        ps = create_pose_stamped(self, pose_data, tag_id)

        tag = CustomTag()
        tag.header = ps.header
        tag.pose_x = ps.pose.position.x
        tag.pose_y = ps.pose.position.y
        tag.pose_z = ps.pose.position.z
        tag.orientation_x = ps.pose.orientation.x
        tag.orientation_y = ps.pose.orientation.y
        tag.orientation_z = ps.pose.orientation.z
        tag.orientation_w = ps.pose.orientation.w

        pub = get_tag_publisher(
            self, self.topics, self.tag_id, suffix="pose")
        pub.publish(ps)

        update_multitags_list(self.multipleTags, tag, tag_macID)

        self.pub_tags.publish(self.multipleTags)


def main(args=None):
    rclpy.init(args=args)
    dwm1001 = dwm1001_localizer()
    try:
        dwm1001.initialize_hardware()
        rclpy.spin(dwm1001)
    except KeyboardInterrupt:
        pass
    except IOError:
        pass
    finally:
        dwm1001.shutdown_hardware()
        dwm1001.destroy_node()
        rclpy.shutdown()


if __name__ == '__main__':
    main()
