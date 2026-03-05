// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from xsens_mti_ros2_driver:msg/XsStatusWord.idl
// generated code does not contain a copyright notice

#include "xsens_mti_ros2_driver/msg/detail/xs_status_word__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_xsens_mti_ros2_driver
const rosidl_type_hash_t *
xsens_mti_ros2_driver__msg__XsStatusWord__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x7a, 0x21, 0xf8, 0x1c, 0xe2, 0x43, 0x5b, 0x30,
      0x55, 0x85, 0x50, 0x8f, 0x8a, 0x79, 0x70, 0x77,
      0xd5, 0x6c, 0xe9, 0x57, 0xe9, 0xe7, 0x61, 0x96,
      0x56, 0xeb, 0x57, 0xaf, 0x91, 0xc8, 0xa8, 0x00,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types

// Hashes for external referenced types
#ifndef NDEBUG
#endif

static char xsens_mti_ros2_driver__msg__XsStatusWord__TYPE_NAME[] = "xsens_mti_ros2_driver/msg/XsStatusWord";

// Define type names, field names, and default values
static char xsens_mti_ros2_driver__msg__XsStatusWord__FIELD_NAME__selftest[] = "selftest";
static char xsens_mti_ros2_driver__msg__XsStatusWord__FIELD_NAME__filter_valid[] = "filter_valid";
static char xsens_mti_ros2_driver__msg__XsStatusWord__FIELD_NAME__gnss_fix[] = "gnss_fix";
static char xsens_mti_ros2_driver__msg__XsStatusWord__FIELD_NAME__no_rotation_update_status[] = "no_rotation_update_status";
static char xsens_mti_ros2_driver__msg__XsStatusWord__FIELD_NAME__representative_motion[] = "representative_motion";
static char xsens_mti_ros2_driver__msg__XsStatusWord__FIELD_NAME__clock_bias_estimation[] = "clock_bias_estimation";
static char xsens_mti_ros2_driver__msg__XsStatusWord__FIELD_NAME__clipflag_acc_x[] = "clipflag_acc_x";
static char xsens_mti_ros2_driver__msg__XsStatusWord__FIELD_NAME__clipflag_acc_y[] = "clipflag_acc_y";
static char xsens_mti_ros2_driver__msg__XsStatusWord__FIELD_NAME__clipflag_acc_z[] = "clipflag_acc_z";
static char xsens_mti_ros2_driver__msg__XsStatusWord__FIELD_NAME__clipflag_gyr_x[] = "clipflag_gyr_x";
static char xsens_mti_ros2_driver__msg__XsStatusWord__FIELD_NAME__clipflag_gyr_y[] = "clipflag_gyr_y";
static char xsens_mti_ros2_driver__msg__XsStatusWord__FIELD_NAME__clipflag_gyr_z[] = "clipflag_gyr_z";
static char xsens_mti_ros2_driver__msg__XsStatusWord__FIELD_NAME__clipflag_mag_x[] = "clipflag_mag_x";
static char xsens_mti_ros2_driver__msg__XsStatusWord__FIELD_NAME__clipflag_mag_y[] = "clipflag_mag_y";
static char xsens_mti_ros2_driver__msg__XsStatusWord__FIELD_NAME__clipflag_mag_z[] = "clipflag_mag_z";
static char xsens_mti_ros2_driver__msg__XsStatusWord__FIELD_NAME__clipping_indication[] = "clipping_indication";
static char xsens_mti_ros2_driver__msg__XsStatusWord__FIELD_NAME__syncin_marker[] = "syncin_marker";
static char xsens_mti_ros2_driver__msg__XsStatusWord__FIELD_NAME__syncout_marker[] = "syncout_marker";
static char xsens_mti_ros2_driver__msg__XsStatusWord__FIELD_NAME__filter_mode[] = "filter_mode";
static char xsens_mti_ros2_driver__msg__XsStatusWord__FIELD_NAME__have_gnss_time_pulse[] = "have_gnss_time_pulse";
static char xsens_mti_ros2_driver__msg__XsStatusWord__FIELD_NAME__rtk_status[] = "rtk_status";

static rosidl_runtime_c__type_description__Field xsens_mti_ros2_driver__msg__XsStatusWord__FIELDS[] = {
  {
    {xsens_mti_ros2_driver__msg__XsStatusWord__FIELD_NAME__selftest, 8, 8},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOOLEAN,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {xsens_mti_ros2_driver__msg__XsStatusWord__FIELD_NAME__filter_valid, 12, 12},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOOLEAN,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {xsens_mti_ros2_driver__msg__XsStatusWord__FIELD_NAME__gnss_fix, 8, 8},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOOLEAN,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {xsens_mti_ros2_driver__msg__XsStatusWord__FIELD_NAME__no_rotation_update_status, 25, 25},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT8,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {xsens_mti_ros2_driver__msg__XsStatusWord__FIELD_NAME__representative_motion, 21, 21},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOOLEAN,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {xsens_mti_ros2_driver__msg__XsStatusWord__FIELD_NAME__clock_bias_estimation, 21, 21},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOOLEAN,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {xsens_mti_ros2_driver__msg__XsStatusWord__FIELD_NAME__clipflag_acc_x, 14, 14},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOOLEAN,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {xsens_mti_ros2_driver__msg__XsStatusWord__FIELD_NAME__clipflag_acc_y, 14, 14},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOOLEAN,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {xsens_mti_ros2_driver__msg__XsStatusWord__FIELD_NAME__clipflag_acc_z, 14, 14},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOOLEAN,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {xsens_mti_ros2_driver__msg__XsStatusWord__FIELD_NAME__clipflag_gyr_x, 14, 14},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOOLEAN,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {xsens_mti_ros2_driver__msg__XsStatusWord__FIELD_NAME__clipflag_gyr_y, 14, 14},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOOLEAN,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {xsens_mti_ros2_driver__msg__XsStatusWord__FIELD_NAME__clipflag_gyr_z, 14, 14},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOOLEAN,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {xsens_mti_ros2_driver__msg__XsStatusWord__FIELD_NAME__clipflag_mag_x, 14, 14},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOOLEAN,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {xsens_mti_ros2_driver__msg__XsStatusWord__FIELD_NAME__clipflag_mag_y, 14, 14},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOOLEAN,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {xsens_mti_ros2_driver__msg__XsStatusWord__FIELD_NAME__clipflag_mag_z, 14, 14},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOOLEAN,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {xsens_mti_ros2_driver__msg__XsStatusWord__FIELD_NAME__clipping_indication, 19, 19},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOOLEAN,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {xsens_mti_ros2_driver__msg__XsStatusWord__FIELD_NAME__syncin_marker, 13, 13},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOOLEAN,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {xsens_mti_ros2_driver__msg__XsStatusWord__FIELD_NAME__syncout_marker, 14, 14},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOOLEAN,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {xsens_mti_ros2_driver__msg__XsStatusWord__FIELD_NAME__filter_mode, 11, 11},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT8,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {xsens_mti_ros2_driver__msg__XsStatusWord__FIELD_NAME__have_gnss_time_pulse, 20, 20},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOOLEAN,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {xsens_mti_ros2_driver__msg__XsStatusWord__FIELD_NAME__rtk_status, 10, 10},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT8,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
xsens_mti_ros2_driver__msg__XsStatusWord__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {xsens_mti_ros2_driver__msg__XsStatusWord__TYPE_NAME, 38, 38},
      {xsens_mti_ros2_driver__msg__XsStatusWord__FIELDS, 21, 21},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "# Define the custom XsStatusWord message\n"
  "bool selftest\n"
  "bool filter_valid\n"
  "bool gnss_fix\n"
  "uint8 no_rotation_update_status ##0: not running, 2: aborted, 3:running\n"
  "bool representative_motion\n"
  "bool clock_bias_estimation\n"
  "#bool reserved1\n"
  "bool clipflag_acc_x\n"
  "bool clipflag_acc_y\n"
  "bool clipflag_acc_z\n"
  "bool clipflag_gyr_x\n"
  "bool clipflag_gyr_y\n"
  "bool clipflag_gyr_z\n"
  "bool clipflag_mag_x\n"
  "bool clipflag_mag_y\n"
  "bool clipflag_mag_z\n"
  "#uint8 reserved2\n"
  "bool clipping_indication\n"
  "#bool reserved3\n"
  "bool syncin_marker\n"
  "bool syncout_marker\n"
  "uint8 filter_mode ##0: Without GNSS, 1: Coasting, 3: With GNSS\n"
  "bool have_gnss_time_pulse\n"
  "uint8 rtk_status ##0: No RTK, 1: RTK Floating, 2: RTK Fix\n"
  "#uint8 reserved4\n"
  "\n"
  "########################\n"
  "####ref to MT Low Level Protocol Communication: https://mtidocs.xsens.com/messages\n"
  "####1) Bit 0: Selftest, This flag indicates if the MT passed the self-test according to eMTS(electronic Motion Tracker Specification).\n"
  "####2) Bit 1: Filter Valid, This flag indicates if input into the orientation filter is reliable and / or complete.\n"
  "####3) Bit 2: GNSS fix, This flag indicates if the GNSS unit has a proper fix. \n"
  "####4) Bit 3:4: NoRotationUpdate Status, This flag indicates the status of the no rotation update procedure in the filter after the SetNoRotation message has been sent. 11: Running with no rotation assumption; 10: Rotation detected, no gyro bias estimation (sticky); 00: Estimation complete, no errors.\n"
  "####5) Bit 5: Representative Motion (RepMo), Indicates if the MTi is in In-run Compass Calibration Representative Mode\n"
  "####6) Bit 6: Clock Bias Estimation (ClockSync), Indicates that the Clock Bias Estimation synchronization feature is active\n"
  "####7) Bit 7: Reserved, Reserved for future use\n"
  "####8) Bit 8: Clipflag Acc X, If set, an out of range acceleration on the X axis is detected\n"
  "####9) Bit 9: Clipflag Acc Y, If set, an out of range acceleration on the Y axis is detected\n"
  "####10) Bit 10: Clipflag Acc Z, If set, an out of range acceleration on the Z axis is detected\n"
  "####11) Bit 11: Clipflag Gyr X, If set, an out of range angular velocity on the X axis is detected\n"
  "####12) Bit 12: Clipflag Gyr Y, If set, an out of range angular velocity on the Y axis is detected\n"
  "####13) Bit 13: Clipflag Gyr Z, If set, an out of range angular velocity on the Z axis is detected\n"
  "####14) Bit 14: Clipflag Mag X, If set, an out of range magnetic field on the X axis is detected\n"
  "####15) Bit 15: Clipflag Mag Y, If set, an out of range magnetic field on the Y axis is detected\n"
  "####16) Bit 16: Clipflag Mag Z, If set, an out of range magnetic field on the Z axis is detected\n"
  "####17) Bit 17:18, Reserved, Reserved for future use\n"
  "####18) Bit 19, Clipping Indication, This flag indicates going out of range of one of the sensors (it is set when one or more bits from 8:16 are set)\n"
  "####19) Bit 20,  Reserved, Reserved for future use\n"
  "####20) Bit 21, SyncIn Marker, When a SyncIn is detected, this bit will rise to 1. \n"
  "####21) Bit 22, SyncOut Marker, When SyncOut is active, this bit will rise to 1.\n"
  "####22) Bit 23:25, Filter Mode, Indicates Filter Mode, currently only available for GNSS/INS devices:000: Without GNSS (filter profile is in VRU mode); 001: Coasting mode (GNSS has been lost <60 sec ago);011: With GNSS (default mode)\n"
  "####23) Bit 26, HaveGnssTimePulse, Indicates that the 1PPS GNSS time pulse is present\n"
  "####24) 27:28, RtkStatus, Indicates the availability and status of RTK: 00: No RTK; 01: RTK floating; 10: RTK fixed\n"
  "####25) 29:31, Reserved, Reserved for future use";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
xsens_mti_ros2_driver__msg__XsStatusWord__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {xsens_mti_ros2_driver__msg__XsStatusWord__TYPE_NAME, 38, 38},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 3477, 3477},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
xsens_mti_ros2_driver__msg__XsStatusWord__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *xsens_mti_ros2_driver__msg__XsStatusWord__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}
