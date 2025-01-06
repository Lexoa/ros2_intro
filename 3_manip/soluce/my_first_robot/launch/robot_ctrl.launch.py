import os
from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    urdf_file = os.path.join(get_package_share_directory('my_first_robot'), 'urdf', 'my_first_robot.urdf')
    controller_config = os.path.join(get_package_share_directory('my_first_robot'), 'config', 'my_first_robot_controllers.yaml')

    return LaunchDescription([
        Node(
            package='robot_state_publisher',
            executable='robot_state_publisher',
            output='screen',
            parameters=[{'robot_description': open(urdf_file).read()}]
        ),
        Node(
            package='controller_manager',
            executable='ros2_control_node',
            output='screen',
            parameters=[{'robot_description': open(urdf_file).read()}, controller_config],
            remappings=[('/joint_states', '/joint_state_broadcaster/joint_states')]
        ),
        Node(
            package='controller_manager',
            executable='spawner',
            arguments=['joint_state_broadcaster'],
            output='screen'
        ),
        Node(
            package='controller_manager',
            executable='spawner',
            arguments=['joint_trajectory_controller'],
            output='screen'
        )
    ])