# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/home/ros2/ros2_ws/src/Xsens_MTi_ROS_Driver_and_Ntrip_Client/src/xsens_mti_ros2_driver/lib/xspublic"
  "/home/ros2/ros2_ws/build/xsens_mti_ros2_driver/xspublic/src/xspublic-build"
  "/home/ros2/ros2_ws/build/xsens_mti_ros2_driver/xspublic"
  "/home/ros2/ros2_ws/build/xsens_mti_ros2_driver/xspublic/tmp"
  "/home/ros2/ros2_ws/build/xsens_mti_ros2_driver/xspublic/src/xspublic-stamp"
  "/home/ros2/ros2_ws/build/xsens_mti_ros2_driver/xspublic/src"
  "/home/ros2/ros2_ws/build/xsens_mti_ros2_driver/xspublic/src/xspublic-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/home/ros2/ros2_ws/build/xsens_mti_ros2_driver/xspublic/src/xspublic-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/home/ros2/ros2_ws/build/xsens_mti_ros2_driver/xspublic/src/xspublic-stamp${cfgdir}") # cfgdir has leading slash
endif()
