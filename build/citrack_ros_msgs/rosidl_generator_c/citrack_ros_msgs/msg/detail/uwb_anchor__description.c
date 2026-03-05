// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from citrack_ros_msgs:msg/UwbAnchor.idl
// generated code does not contain a copyright notice

#include "citrack_ros_msgs/msg/detail/uwb_anchor__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_citrack_ros_msgs
const rosidl_type_hash_t *
citrack_ros_msgs__msg__UwbAnchor__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x24, 0xd7, 0xc4, 0xb4, 0x8a, 0x79, 0x42, 0xb9,
      0x37, 0x83, 0xcb, 0xdb, 0xe4, 0x4b, 0xff, 0xf1,
      0xdc, 0x48, 0xe8, 0xc4, 0x4e, 0xd4, 0x81, 0x1c,
      0x54, 0x3d, 0xe6, 0x83, 0x67, 0xe1, 0x64, 0x7b,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types

// Hashes for external referenced types
#ifndef NDEBUG
#endif

static char citrack_ros_msgs__msg__UwbAnchor__TYPE_NAME[] = "citrack_ros_msgs/msg/UwbAnchor";

// Define type names, field names, and default values
static char citrack_ros_msgs__msg__UwbAnchor__FIELD_NAME__id[] = "id";
static char citrack_ros_msgs__msg__UwbAnchor__FIELD_NAME__x[] = "x";
static char citrack_ros_msgs__msg__UwbAnchor__FIELD_NAME__y[] = "y";
static char citrack_ros_msgs__msg__UwbAnchor__FIELD_NAME__z[] = "z";
static char citrack_ros_msgs__msg__UwbAnchor__FIELD_NAME__distancefromtag[] = "distancefromtag";

static rosidl_runtime_c__type_description__Field citrack_ros_msgs__msg__UwbAnchor__FIELDS[] = {
  {
    {citrack_ros_msgs__msg__UwbAnchor__FIELD_NAME__id, 2, 2},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_STRING,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {citrack_ros_msgs__msg__UwbAnchor__FIELD_NAME__x, 1, 1},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {citrack_ros_msgs__msg__UwbAnchor__FIELD_NAME__y, 1, 1},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {citrack_ros_msgs__msg__UwbAnchor__FIELD_NAME__z, 1, 1},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {citrack_ros_msgs__msg__UwbAnchor__FIELD_NAME__distancefromtag, 15, 15},
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
citrack_ros_msgs__msg__UwbAnchor__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {citrack_ros_msgs__msg__UwbAnchor__TYPE_NAME, 30, 30},
      {citrack_ros_msgs__msg__UwbAnchor__FIELDS, 5, 5},
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
  "float64 x\n"
  "float64 y\n"
  "float64 z\n"
  "float64 distancefromtag";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
citrack_ros_msgs__msg__UwbAnchor__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {citrack_ros_msgs__msg__UwbAnchor__TYPE_NAME, 30, 30},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 63, 63},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
citrack_ros_msgs__msg__UwbAnchor__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *citrack_ros_msgs__msg__UwbAnchor__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}
