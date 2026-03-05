import os
from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch_ros.actions import Node
from launch.substitutions import LaunchConfiguration
from launch.actions import DeclareLaunchArgument
def generate_launch_description():
    my_pkg_dir = get_package_share_directory('sebot_navigation')
    params_file = os.path.join(my_pkg_dir, 'config', 'nav2_params.yaml')
    map_config = os.path.expanduser("~/ros2_ws/map.yaml")
    
    use_sim_time = LaunchConfiguration('use_sim_time', default='false')

    return LaunchDescription([
        DeclareLaunchArgument(
            'use_sim_time',
            default_value='false',
            description='Use simulation clock if true'
        ),
        
        #    Node(package='nav2_amcl', executable='amcl', name='amcl',
        #         output='screen', parameters=[params_file]),

        Node(
            package='nav2_map_server',
            executable='map_server',
            name='map_server',
            output='screen',
            parameters=[{'yaml_filename': map_config}]
        ),

        Node(package='nav2_planner', executable='planner_server',
             name='planner_server', output='screen', parameters=[params_file]),

        Node(package='nav2_controller', executable='controller_server',
             name='controller_server', output='screen', parameters=[params_file]),

        Node(package='nav2_behaviors', executable='behavior_server',
             name='behavior_server', output='screen', parameters=[params_file]),

        Node(package='nav2_bt_navigator', executable='bt_navigator',
             name='bt_navigator', output='screen', parameters=[params_file]),

        # Node(package='nav2_waypoint_follower', executable='waypoint_follower',
        #      name='waypoint_follower', output='screen', parameters=[params_file]),

        Node(package='nav2_velocity_smoother', executable='velocity_smoother',
             name='velocity_smoother', output='screen', parameters=[params_file]),

        Node(package='nav2_smoother', executable='smoother_server',
             name='smoother_server', output='screen', parameters=[params_file]),

        Node(package='nav2_collision_monitor', executable='collision_monitor',
             name='collision_monitor', output='screen', parameters=[params_file]),

        Node(
            package='nav2_lifecycle_manager',
            executable='lifecycle_manager',
            name='lifecycle_manager_navigation',
            output='screen',
            parameters=[{'use_sim_time': False},
                        {'autostart': True},
                        {'node_names': ['map_server', 'planner_server', 'controller_server',
                                        'behavior_server', 'bt_navigator', 'velocity_smoother', 'smoother_server']}]
        ),
    ])
