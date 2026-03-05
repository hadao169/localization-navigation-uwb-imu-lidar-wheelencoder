// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from citrack_ros_msgs:msg/UwbTag.idl
// generated code does not contain a copyright notice

#include "citrack_ros_msgs/msg/detail/uwb_tag__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_citrack_ros_msgs
const rosidl_type_hash_t *
citrack_ros_msgs__msg__UwbTag__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x87, 0xa7, 0x5b, 0x1b, 0xed, 0x61, 0xeb, 0x7f,
      0x16, 0xcb, 0x24, 0x4a, 0x61, 0x71, 0xb7, 0x56,
      0x98, 0x52, 0x20, 0x9a, 0x4d, 0xbb, 0x3f, 0x34,
      0xa8, 0x82, 0x3e, 0x90, 0xcb, 0x04, 0x52, 0x1d,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types

// Hashes for external referenced types
#ifndef NDEBUG
#endif

static char citrack_ros_msgs__msg__UwbTag__TYPE_NAME[] = "citrack_ros_msgs/msg/UwbTag";

// Define type names, field names, and default values
static char citrack_ros_msgs__msg__UwbTag__FIELD_NAME__id[] = "id";
static char citrack_ros_msgs__msg__UwbTag__FIELD_NAME__x[] = "x";
static char citrack_ros_msgs__msg__UwbTag__FIELD_NAME__y[] = "y";
static char citrack_ros_msgs__msg__UwbTag__FIELD_NAME__z[] = "z";

static rosidl_runtime_c__type_description__Field citrack_ros_msgs__msg__UwbTag__FIELDS[] = {
  {
    {citrack_ros_msgs__msg__UwbTag__FIELD_NAME__id, 2, 2},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_STRING,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {citrack_ros_msgs__msg__UwbTag__FIELD_NAME__x, 1, 1},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {citrack_ros_msgs__msg__UwbTag__FIELD_NAME__y, 1, 1},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {citrack_ros_msgs__msg__UwbTag__FIELD_NAME__z, 1, 1},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
citrack_ros_msgs__msg__UwbTag__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {citrack_ros_msgs__msg__UwbTag__TYPE_NAME, 27, 27},
      {citrack_ros_msgs__msg__UwbTag__FIELDS, 4, 4},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "string id\n"
  "float64  x\n"
  "float64  y\n"
  "float64  z";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
citrack_ros_msgs__msg__UwbTag__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {citrack_ros_msgs__msg__UwbTag__TYPE_NAME, 27, 27},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 43, 43},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
citrack_ros_msgs__msg__UwbTag__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *citrack_ros_msgs__msg__UwbTag__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}
