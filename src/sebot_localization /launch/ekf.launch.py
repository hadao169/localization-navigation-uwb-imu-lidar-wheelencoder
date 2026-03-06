# single_ekf_custom.launch.py
from launch import LaunchDescription
from launch_ros.actions import Node
from launch.actions import DeclareLaunchArgument
from launch.substitutions import LaunchConfiguration

def generate_launch_description():
    use_sim_time = LaunchConfiguration('use_sim_time')

    return LaunchDescription([
        DeclareLaunchArgument(
            'use_sim_time',
            default_value='false',
            description='Use simulation (Gazebo) clock if true'),

        Node(
            package='sebot_localization',
            executable='uwb_transform_dual_ekf_node',
            name='uwb_transform_dual_ekf_node',
            output='screen',
            parameters=[{'use_sim_time': use_sim_time}],
        )
    ])