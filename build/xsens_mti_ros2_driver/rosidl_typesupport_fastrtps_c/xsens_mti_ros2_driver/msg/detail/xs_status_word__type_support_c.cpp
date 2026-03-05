// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from xsens_mti_ros2_driver:msg/XsStatusWord.idl
// generated code does not contain a copyright notice
#include "xsens_mti_ros2_driver/msg/detail/xs_status_word__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <cstddef>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/serialization_helpers.hpp"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "xsens_mti_ros2_driver/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "xsens_mti_ros2_driver/msg/detail/xs_status_word__struct.h"
#include "xsens_mti_ros2_driver/msg/detail/xs_status_word__functions.h"
#include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif


// forward declare type support functions


using _XsStatusWord__ros_msg_type = xsens_mti_ros2_driver__msg__XsStatusWord;


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_xsens_mti_ros2_driver
bool cdr_serialize_xsens_mti_ros2_driver__msg__XsStatusWord(
  const xsens_mti_ros2_driver__msg__XsStatusWord * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: selftest
  {
    cdr << (ros_message->selftest ? true : false);
  }

  // Field name: filter_valid
  {
    cdr << (ros_message->filter_valid ? true : false);
  }

  // Field name: gnss_fix
  {
    cdr << (ros_message->gnss_fix ? true : false);
  }

  // Field name: no_rotation_update_status
  {
    cdr << ros_message->no_rotation_update_status;
  }

  // Field name: representative_motion
  {
    cdr << (ros_message->representative_motion ? true : false);
  }

  // Field name: clock_bias_estimation
  {
    cdr << (ros_message->clock_bias_estimation ? true : false);
  }

  // Field name: clipflag_acc_x
  {
    cdr << (ros_message->clipflag_acc_x ? true : false);
  }

  // Field name: clipflag_acc_y
  {
    cdr << (ros_message->clipflag_acc_y ? true : false);
  }

  // Field name: clipflag_acc_z
  {
    cdr << (ros_message->clipflag_acc_z ? true : false);
  }

  // Field name: clipflag_gyr_x
  {
    cdr << (ros_message->clipflag_gyr_x ? true : false);
  }

  // Field name: clipflag_gyr_y
  {
    cdr << (ros_message->clipflag_gyr_y ? true : false);
  }

  // Field name: clipflag_gyr_z
  {
    cdr << (ros_message->clipflag_gyr_z ? true : false);
  }

  // Field name: clipflag_mag_x
  {
    cdr << (ros_message->clipflag_mag_x ? true : false);
  }

  // Field name: clipflag_mag_y
  {
    cdr << (ros_message->clipflag_mag_y ? true : false);
  }

  // Field name: clipflag_mag_z
  {
    cdr << (ros_message->clipflag_mag_z ? true : false);
  }

  // Field name: clipping_indication
  {
    cdr << (ros_message->clipping_indication ? true : false);
  }

  // Field name: syncin_marker
  {
    cdr << (ros_message->syncin_marker ? true : false);
  }

  // Field name: syncout_marker
  {
    cdr << (ros_message->syncout_marker ? true : false);
  }

  // Field name: filter_mode
  {
    cdr << ros_message->filter_mode;
  }

  // Field name: have_gnss_time_pulse
  {
    cdr << (ros_message->have_gnss_time_pulse ? true : false);
  }

  // Field name: rtk_status
  {
    cdr << ros_message->rtk_status;
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_xsens_mti_ros2_driver
bool cdr_deserialize_xsens_mti_ros2_driver__msg__XsStatusWord(
  eprosima::fastcdr::Cdr & cdr,
  xsens_mti_ros2_driver__msg__XsStatusWord * ros_message)
{
  // Field name: selftest
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->selftest = tmp ? true : false;
  }

  // Field name: filter_valid
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->filter_valid = tmp ? true : false;
  }

  // Field name: gnss_fix
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->gnss_fix = tmp ? true : false;
  }

  // Field name: no_rotation_update_status
  {
    cdr >> ros_message->no_rotation_update_status;
  }

  // Field name: representative_motion
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->representative_motion = tmp ? true : false;
  }

  // Field name: clock_bias_estimation
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->clock_bias_estimation = tmp ? true : false;
  }

  // Field name: clipflag_acc_x
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->clipflag_acc_x = tmp ? true : false;
  }

  // Field name: clipflag_acc_y
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->clipflag_acc_y = tmp ? true : false;
  }

  // Field name: clipflag_acc_z
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->clipflag_acc_z = tmp ? true : false;
  }

  // Field name: clipflag_gyr_x
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->clipflag_gyr_x = tmp ? true : false;
  }

  // Field name: clipflag_gyr_y
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->clipflag_gyr_y = tmp ? true : false;
  }

  // Field name: clipflag_gyr_z
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->clipflag_gyr_z = tmp ? true : false;
  }

  // Field name: clipflag_mag_x
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->clipflag_mag_x = tmp ? true : false;
  }

  // Field name: clipflag_mag_y
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->clipflag_mag_y = tmp ? true : false;
  }

  // Field name: clipflag_mag_z
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->clipflag_mag_z = tmp ? true : false;
  }

  // Field name: clipping_indication
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->clipping_indication = tmp ? true : false;
  }

  // Field name: syncin_marker
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->syncin_marker = tmp ? true : false;
  }

  // Field name: syncout_marker
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->syncout_marker = tmp ? true : false;
  }

  // Field name: filter_mode
  {
    cdr >> ros_message->filter_mode;
  }

  // Field name: have_gnss_time_pulse
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->have_gnss_time_pulse = tmp ? true : false;
  }

  // Field name: rtk_status
  {
    cdr >> ros_message->rtk_status;
  }

  return true;
}  // NOLINT(readability/fn_size)


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_xsens_mti_ros2_driver
size_t get_serialized_size_xsens_mti_ros2_driver__msg__XsStatusWord(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _XsStatusWord__ros_msg_type * ros_message = static_cast<const _XsStatusWord__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: selftest
  {
    size_t item_size = sizeof(ros_message->selftest);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: filter_valid
  {
    size_t item_size = sizeof(ros_message->filter_valid);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: gnss_fix
  {
    size_t item_size = sizeof(ros_message->gnss_fix);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: no_rotation_update_status
  {
    size_t item_size = sizeof(ros_message->no_rotation_update_status);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: representative_motion
  {
    size_t item_size = sizeof(ros_message->representative_motion);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: clock_bias_estimation
  {
    size_t item_size = sizeof(ros_message->clock_bias_estimation);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: clipflag_acc_x
  {
    size_t item_size = sizeof(ros_message->clipflag_acc_x);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: clipflag_acc_y
  {
    size_t item_size = sizeof(ros_message->clipflag_acc_y);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: clipflag_acc_z
  {
    size_t item_size = sizeof(ros_message->clipflag_acc_z);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: clipflag_gyr_x
  {
    size_t item_size = sizeof(ros_message->clipflag_gyr_x);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: clipflag_gyr_y
  {
    size_t item_size = sizeof(ros_message->clipflag_gyr_y);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: clipflag_gyr_z
  {
    size_t item_size = sizeof(ros_message->clipflag_gyr_z);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: clipflag_mag_x
  {
    size_t item_size = sizeof(ros_message->clipflag_mag_x);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: clipflag_mag_y
  {
    size_t item_size = sizeof(ros_message->clipflag_mag_y);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: clipflag_mag_z
  {
    size_t item_size = sizeof(ros_message->clipflag_mag_z);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: clipping_indication
  {
    size_t item_size = sizeof(ros_message->clipping_indication);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: syncin_marker
  {
    size_t item_size = sizeof(ros_message->syncin_marker);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: syncout_marker
  {
    size_t item_size = sizeof(ros_message->syncout_marker);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: filter_mode
  {
    size_t item_size = sizeof(ros_message->filter_mode);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: have_gnss_time_pulse
  {
    size_t item_size = sizeof(ros_message->have_gnss_time_pulse);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: rtk_status
  {
    size_t item_size = sizeof(ros_message->rtk_status);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_xsens_mti_ros2_driver
size_t max_serialized_size_xsens_mti_ros2_driver__msg__XsStatusWord(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;

  // Field name: selftest
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: filter_valid
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: gnss_fix
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: no_rotation_update_status
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: representative_motion
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: clock_bias_estimation
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: clipflag_acc_x
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: clipflag_acc_y
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: clipflag_acc_z
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: clipflag_gyr_x
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: clipflag_gyr_y
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: clipflag_gyr_z
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: clipflag_mag_x
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: clipflag_mag_y
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: clipflag_mag_z
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: clipping_indication
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: syncin_marker
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: syncout_marker
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: filter_mode
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: have_gnss_time_pulse
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: rtk_status
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }


  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = xsens_mti_ros2_driver__msg__XsStatusWord;
    is_plain =
      (
      offsetof(DataType, rtk_status) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_xsens_mti_ros2_driver
bool cdr_serialize_key_xsens_mti_ros2_driver__msg__XsStatusWord(
  const xsens_mti_ros2_driver__msg__XsStatusWord * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: selftest
  {
    cdr << (ros_message->selftest ? true : false);
  }

  // Field name: filter_valid
  {
    cdr << (ros_message->filter_valid ? true : false);
  }

  // Field name: gnss_fix
  {
    cdr << (ros_message->gnss_fix ? true : false);
  }

  // Field name: no_rotation_update_status
  {
    cdr << ros_message->no_rotation_update_status;
  }

  // Field name: representative_motion
  {
    cdr << (ros_message->representative_motion ? true : false);
  }

  // Field name: clock_bias_estimation
  {
    cdr << (ros_message->clock_bias_estimation ? true : false);
  }

  // Field name: clipflag_acc_x
  {
    cdr << (ros_message->clipflag_acc_x ? true : false);
  }

  // Field name: clipflag_acc_y
  {
    cdr << (ros_message->clipflag_acc_y ? true : false);
  }

  // Field name: clipflag_acc_z
  {
    cdr << (ros_message->clipflag_acc_z ? true : false);
  }

  // Field name: clipflag_gyr_x
  {
    cdr << (ros_message->clipflag_gyr_x ? true : false);
  }

  // Field name: clipflag_gyr_y
  {
    cdr << (ros_message->clipflag_gyr_y ? true : false);
  }

  // Field name: clipflag_gyr_z
  {
    cdr << (ros_message->clipflag_gyr_z ? true : false);
  }

  // Field name: clipflag_mag_x
  {
    cdr << (ros_message->clipflag_mag_x ? true : false);
  }

  // Field name: clipflag_mag_y
  {
    cdr << (ros_message->clipflag_mag_y ? true : false);
  }

  // Field name: clipflag_mag_z
  {
    cdr << (ros_message->clipflag_mag_z ? true : false);
  }

  // Field name: clipping_indication
  {
    cdr << (ros_message->clipping_indication ? true : false);
  }

  // Field name: syncin_marker
  {
    cdr << (ros_message->syncin_marker ? true : false);
  }

  // Field name: syncout_marker
  {
    cdr << (ros_message->syncout_marker ? true : false);
  }

  // Field name: filter_mode
  {
    cdr << ros_message->filter_mode;
  }

  // Field name: have_gnss_time_pulse
  {
    cdr << (ros_message->have_gnss_time_pulse ? true : false);
  }

  // Field name: rtk_status
  {
    cdr << ros_message->rtk_status;
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_xsens_mti_ros2_driver
size_t get_serialized_size_key_xsens_mti_ros2_driver__msg__XsStatusWord(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _XsStatusWord__ros_msg_type * ros_message = static_cast<const _XsStatusWord__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;

  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: selftest
  {
    size_t item_size = sizeof(ros_message->selftest);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: filter_valid
  {
    size_t item_size = sizeof(ros_message->filter_valid);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: gnss_fix
  {
    size_t item_size = sizeof(ros_message->gnss_fix);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: no_rotation_update_status
  {
    size_t item_size = sizeof(ros_message->no_rotation_update_status);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: representative_motion
  {
    size_t item_size = sizeof(ros_message->representative_motion);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: clock_bias_estimation
  {
    size_t item_size = sizeof(ros_message->clock_bias_estimation);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: clipflag_acc_x
  {
    size_t item_size = sizeof(ros_message->clipflag_acc_x);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: clipflag_acc_y
  {
    size_t item_size = sizeof(ros_message->clipflag_acc_y);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: clipflag_acc_z
  {
    size_t item_size = sizeof(ros_message->clipflag_acc_z);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: clipflag_gyr_x
  {
    size_t item_size = sizeof(ros_message->clipflag_gyr_x);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: clipflag_gyr_y
  {
    size_t item_size = sizeof(ros_message->clipflag_gyr_y);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: clipflag_gyr_z
  {
    size_t item_size = sizeof(ros_message->clipflag_gyr_z);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: clipflag_mag_x
  {
    size_t item_size = sizeof(ros_message->clipflag_mag_x);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: clipflag_mag_y
  {
    size_t item_size = sizeof(ros_message->clipflag_mag_y);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: clipflag_mag_z
  {
    size_t item_size = sizeof(ros_message->clipflag_mag_z);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: clipping_indication
  {
    size_t item_size = sizeof(ros_message->clipping_indication);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: syncin_marker
  {
    size_t item_size = sizeof(ros_message->syncin_marker);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: syncout_marker
  {
    size_t item_size = sizeof(ros_message->syncout_marker);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: filter_mode
  {
    size_t item_size = sizeof(ros_message->filter_mode);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: have_gnss_time_pulse
  {
    size_t item_size = sizeof(ros_message->have_gnss_time_pulse);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: rtk_status
  {
    size_t item_size = sizeof(ros_message->rtk_status);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_xsens_mti_ros2_driver
size_t max_serialized_size_key_xsens_mti_ros2_driver__msg__XsStatusWord(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;
  // Field name: selftest
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: filter_valid
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: gnss_fix
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: no_rotation_update_status
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: representative_motion
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: clock_bias_estimation
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: clipflag_acc_x
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: clipflag_acc_y
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: clipflag_acc_z
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: clipflag_gyr_x
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: clipflag_gyr_y
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: clipflag_gyr_z
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: clipflag_mag_x
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: clipflag_mag_y
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: clipflag_mag_z
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: clipping_indication
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: syncin_marker
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: syncout_marker
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: filter_mode
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: have_gnss_time_pulse
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: rtk_status
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = xsens_mti_ros2_driver__msg__XsStatusWord;
    is_plain =
      (
      offsetof(DataType, rtk_status) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}


static bool _XsStatusWord__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const xsens_mti_ros2_driver__msg__XsStatusWord * ros_message = static_cast<const xsens_mti_ros2_driver__msg__XsStatusWord *>(untyped_ros_message);
  (void)ros_message;
  return cdr_serialize_xsens_mti_ros2_driver__msg__XsStatusWord(ros_message, cdr);
}

static bool _XsStatusWord__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  xsens_mti_ros2_driver__msg__XsStatusWord * ros_message = static_cast<xsens_mti_ros2_driver__msg__XsStatusWord *>(untyped_ros_message);
  (void)ros_message;
  return cdr_deserialize_xsens_mti_ros2_driver__msg__XsStatusWord(cdr, ros_message);
}

static uint32_t _XsStatusWord__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_xsens_mti_ros2_driver__msg__XsStatusWord(
      untyped_ros_message, 0));
}

static size_t _XsStatusWord__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_xsens_mti_ros2_driver__msg__XsStatusWord(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_XsStatusWord = {
  "xsens_mti_ros2_driver::msg",
  "XsStatusWord",
  _XsStatusWord__cdr_serialize,
  _XsStatusWord__cdr_deserialize,
  _XsStatusWord__get_serialized_size,
  _XsStatusWord__max_serialized_size,
  nullptr
};

static rosidl_message_type_support_t _XsStatusWord__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_XsStatusWord,
  get_message_typesupport_handle_function,
  &xsens_mti_ros2_driver__msg__XsStatusWord__get_type_hash,
  &xsens_mti_ros2_driver__msg__XsStatusWord__get_type_description,
  &xsens_mti_ros2_driver__msg__XsStatusWord__get_type_description_sources,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, xsens_mti_ros2_driver, msg, XsStatusWord)() {
  return &_XsStatusWord__type_support;
}

#if defined(__cplusplus)
}
#endif
