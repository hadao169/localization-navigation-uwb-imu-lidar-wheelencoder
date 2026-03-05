import os
from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, IncludeLaunchDescription
from launch.substitutions import LaunchConfiguration, PythonExpression
from launch_ros.actions import Node
from launch.launch_description_sources import PythonLaunchDescriptionSource

def generate_launch_description():
    use_sim_time = LaunchConfiguration('use_sim_time')
    simulation = LaunchConfiguration('simulation')
    use_dual_ekf = LaunchConfiguration('use_dual_ekf')

    colcon_prefix_path = os.getenv('COLCON_PREFIX_PATH').split("/install")[0]
    config_path = os.path.join(colcon_prefix_path, 'config')
    params_yaml = os.path.join(config_path, 'params.yaml')
    urdf_file = os.path.join(config_path, 'robot.urdf')

    with open(urdf_file, 'r') as infp:
        robot_desc = infp.read()

    pkg_localization_path = get_package_share_directory('sebot_localization')

    # Sử dụng __import__('os') để tránh lỗi name 'os' is not defined
    ekf_launch_path = PythonExpression([
        "__import__('os').path.join('", pkg_localization_path, "', 'launch', ",
        "'ekf_dual.launch.py' if '", use_dual_ekf, "' == 'true' else 'ekf.launch.py')"
    ])  

    xsens_launch = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(
            os.path.join(get_package_share_directory(
                'xsens_mti_ros2_driver'), 'launch', 'xsens_mti_node.launch.py')
        )
    )

    ekf_launch = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(ekf_launch_path)
    )

    uwb_launch = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(
            os.path.join(get_package_share_directory(
                'uwb_tracking_ros2'), 'launch', 'uwb_tracking_dwm1001.launch.py')
        )
    )

    return LaunchDescription([
        DeclareLaunchArgument('use_sim_time', default_value='false'),
        DeclareLaunchArgument('simulation', default_value='true'),
        DeclareLaunchArgument('use_dual_ekf', default_value='false'),

        Node(
            package='robot_state_publisher',
            executable='robot_state_publisher',
            name='robot_state_publisher',
            output='screen',
            parameters=[{'use_sim_time': use_sim_time,
                         'robot_description': robot_desc}]
        ),

        Node(
            package='rviz2',
            executable='rviz2',
            name='rviz2',
            output='screen',
            arguments=[
                '-d', os.path.join(get_package_share_directory('diffdrive'), 'rviz')],
            parameters=[{'use_sim_time': use_sim_time}]
        ),

        Node(
            package='motordriver',
            executable='motordriver',
            name='motordriver_node',
            output='screen',
            parameters=[params_yaml]
        ),

        Node(
            package='diffdrive',
            executable='odom',
            name='odom_node',
            output='screen',
            parameters=[params_yaml]
        ),

        Node(
            package='diffdrive',
            executable='odom_origin',
            name='odom_origin_node',
            output='screen',
            parameters=[params_yaml]
        ),

        # Node(
        #     package='diffdrive',
        #     executable='odom_imu',
        #     name='odom_imu_node',
        #     output='screen',
        #     parameters=[params_yaml]
        # ),

        Node(
            package='diffdrive',
            executable='cmd_vel',
            name='cmd_vel_node',
            output='screen',
            parameters=[params_yaml]
        ),

        xsens_launch,
        uwb_launch,
        ekf_launch,

        # Node(
        #     package='diffdrive',
        #     executable='DataLogger',
        #     name='DataLogger',
        #     output='screen',
        #     parameters=[params_yaml]
        # ),
    ])