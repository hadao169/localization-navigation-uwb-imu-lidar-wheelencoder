// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from citrack_ros_msgs:msg/ViconPosition.idl
// generated code does not contain a copyright notice

#include "citrack_ros_msgs/msg/detail/vicon_position__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_citrack_ros_msgs
const rosidl_type_hash_t *
citrack_ros_msgs__msg__ViconPosition__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x2d, 0xfa, 0x64, 0xc4, 0x77, 0x09, 0x73, 0x31,
      0x70, 0xd2, 0x42, 0x2f, 0x59, 0x29, 0xba, 0xfc,
      0x82, 0xab, 0x82, 0x22, 0x81, 0x30, 0x0f, 0x4b,
      0xd7, 0x72, 0x6c, 0xe6, 0x65, 0xe0, 0x71, 0xca,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types

// Hashes for external referenced types
#ifndef NDEBUG
#endif

static char citrack_ros_msgs__msg__ViconPosition__TYPE_NAME[] = "citrack_ros_msgs/msg/ViconPosition";

// Define type names, field names, and default values
static char citrack_ros_msgs__msg__ViconPosition__FIELD_NAME__x_trans[] = "x_trans";
static char citrack_ros_msgs__msg__ViconPosition__FIELD_NAME__y_trans[] = "y_trans";
static char citrack_ros_msgs__msg__ViconPosition__FIELD_NAME__z_trans[] = "z_trans";
static char citrack_ros_msgs__msg__ViconPosition__FIELD_NAME__x_rot[] = "x_rot";
static char citrack_ros_msgs__msg__ViconPosition__FIELD_NAME__y_rot[] = "y_rot";
static char citrack_ros_msgs__msg__ViconPosition__FIELD_NAME__z_rot[] = "z_rot";
static char citrack_ros_msgs__msg__ViconPosition__FIELD_NAME__w[] = "w";
static char citrack_ros_msgs__msg__ViconPosition__FIELD_NAME__segment_name[] = "segment_name";
static char citrack_ros_msgs__msg__ViconPosition__FIELD_NAME__subject_name[] = "subject_name";
static char citrack_ros_msgs__msg__ViconPosition__FIELD_NAME__frame_number[] = "frame_number";
static char citrack_ros_msgs__msg__ViconPosition__FIELD_NAME__translation_type[] = "translation_type";

static rosidl_runtime_c__type_description__Field citrack_ros_msgs__msg__ViconPosition__FIELDS[] = {
  {
    {citrack_ros_msgs__msg__ViconPosition__FIELD_NAME__x_trans, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {citrack_ros_msgs__msg__ViconPosition__FIELD_NAME__y_trans, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {citrack_ros_msgs__msg__ViconPosition__FIELD_NAME__z_trans, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {citrack_ros_msgs__msg__ViconPosition__FIELD_NAME__x_rot, 5, 5},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {citrack_ros_msgs__msg__ViconPosition__FIELD_NAME__y_rot, 5, 5},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {citrack_ros_msgs__msg__ViconPosition__FIELD_NAME__z_rot, 5, 5},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {citrack_ros_msgs__msg__ViconPosition__FIELD_NAME__w, 1, 1},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {citrack_ros_msgs__msg__ViconPosition__FIELD_NAME__segment_name, 12, 12},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_STRING,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {citrack_ros_msgs__msg__ViconPosition__FIELD_NAME__subject_name, 12, 12},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_STRING,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {citrack_ros_msgs__msg__ViconPosition__FIELD_NAME__frame_number, 12, 12},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_INT32,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {citrack_ros_msgs__msg__ViconPosition__FIELD_NAME__translation_type, 16, 16},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_STRING,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
citrack_ros_msgs__msg__ViconPosition__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {citrack_ros_msgs__msg__ViconPosition__TYPE_NAME, 34, 34},
      {citrack_ros_msgs__msg__ViconPosition__FIELDS, 11, 11},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "float32 x_trans\n"
  "float32 y_trans\n"
  "float32 z_trans\n"
  "float32 x_rot\n"
  "float32 y_rot\n"
  "float32 z_rot\n"
  "float32 w\n"
  "string segment_name\n"
  "string subject_name\n"
  "int32 frame_number\n"
  "string translation_type";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
citrack_ros_msgs__msg__ViconPosition__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {citrack_ros_msgs__msg__ViconPosition__TYPE_NAME, 34, 34},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 183, 183},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
citrack_ros_msgs__msg__ViconPosition__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *citrack_ros_msgs__msg__ViconPosition__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}
