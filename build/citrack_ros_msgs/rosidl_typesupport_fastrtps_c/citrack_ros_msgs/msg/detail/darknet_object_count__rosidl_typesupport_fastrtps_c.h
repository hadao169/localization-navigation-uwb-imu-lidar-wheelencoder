// generated from rosidl_typesupport_fastrtps_c/resource/idl__rosidl_typesupport_fastrtps_c.h.em
// with input from citrack_ros_msgs:msg/DarknetObjectCount.idl
// generated code does not contain a copyright notice
#ifndef CITRACK_ROS_MSGS__MSG__DETAIL__DARKNET_OBJECT_COUNT__ROSIDL_TYPESUPPORT_FASTRTPS_C_H_
#define CITRACK_ROS_MSGS__MSG__DETAIL__DARKNET_OBJECT_COUNT__ROSIDL_TYPESUPPORT_FASTRTPS_C_H_


#include <stddef.h>
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_interface/macros.h"
#include "citrack_ros_msgs/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "citrack_ros_msgs/msg/detail/darknet_object_count__struct.h"
#include "fastcdr/Cdr.h"

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_citrack_ros_msgs
bool cdr_serialize_citrack_ros_msgs__msg__DarknetObjectCount(
  const citrack_ros_msgs__msg__DarknetObjectCount * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_citrack_ros_msgs
bool cdr_deserialize_citrack_ros_msgs__msg__DarknetObjectCount(
  eprosima::fastcdr::Cdr &,
  citrack_ros_msgs__msg__DarknetObjectCount * ros_message);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_citrack_ros_msgs
size_t get_serialized_size_citrack_ros_msgs__msg__DarknetObjectCount(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_citrack_ros_msgs
size_t max_serialized_size_citrack_ros_msgs__msg__DarknetObjectCount(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_citrack_ros_msgs
bool cdr_serialize_key_citrack_ros_msgs__msg__DarknetObjectCount(
  const citrack_ros_msgs__msg__DarknetObjectCount * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_citrack_ros_msgs
size_t get_serialized_size_key_citrack_ros_msgs__msg__DarknetObjectCount(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_citrack_ros_msgs
size_t max_serialized_size_key_citrack_ros_msgs__msg__DarknetObjectCount(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_citrack_ros_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, citrack_ros_msgs, msg, DarknetObjectCount)();

#ifdef __cplusplus
}
#endif

#endif  // CITRACK_ROS_MSGS__MSG__DETAIL__DARKNET_OBJECT_COUNT__ROSIDL_TYPESUPPORT_FASTRTPS_C_H_
