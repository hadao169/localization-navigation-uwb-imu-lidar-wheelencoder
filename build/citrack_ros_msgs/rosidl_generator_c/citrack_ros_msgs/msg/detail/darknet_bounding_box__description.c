// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from citrack_ros_msgs:msg/DarknetBoundingBox.idl
// generated code does not contain a copyright notice

#include "citrack_ros_msgs/msg/detail/darknet_bounding_box__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_citrack_ros_msgs
const rosidl_type_hash_t *
citrack_ros_msgs__msg__DarknetBoundingBox__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x84, 0x86, 0x0f, 0x1a, 0x4c, 0x30, 0x9e, 0x4b,
      0x85, 0x0a, 0xa1, 0x62, 0x55, 0xac, 0xa0, 0x28,
      0x77, 0x77, 0x65, 0x28, 0x92, 0x7c, 0x06, 0x6a,
      0x70, 0x2a, 0xf2, 0x8e, 0xa6, 0xeb, 0xf8, 0x7d,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types

// Hashes for external referenced types
#ifndef NDEBUG
#endif

static char citrack_ros_msgs__msg__DarknetBoundingBox__TYPE_NAME[] = "citrack_ros_msgs/msg/DarknetBoundingBox";

// Define type names, field names, and default values
static char citrack_ros_msgs__msg__DarknetBoundingBox__FIELD_NAME__probability[] = "probability";
static char citrack_ros_msgs__msg__DarknetBoundingBox__FIELD_NAME__xmin[] = "xmin";
static char citrack_ros_msgs__msg__DarknetBoundingBox__FIELD_NAME__ymin[] = "ymin";
static char citrack_ros_msgs__msg__DarknetBoundingBox__FIELD_NAME__xmax[] = "xmax";
static char citrack_ros_msgs__msg__DarknetBoundingBox__FIELD_NAME__ymax[] = "ymax";
static char citrack_ros_msgs__msg__DarknetBoundingBox__FIELD_NAME__id[] = "id";
static char citrack_ros_msgs__msg__DarknetBoundingBox__FIELD_NAME__class_name[] = "class_name";

static rosidl_runtime_c__type_description__Field citrack_ros_msgs__msg__DarknetBoundingBox__FIELDS[] = {
  {
    {citrack_ros_msgs__msg__DarknetBoundingBox__FIELD_NAME__probability, 11, 11},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {citrack_ros_msgs__msg__DarknetBoundingBox__FIELD_NAME__xmin, 4, 4},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_INT64,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {citrack_ros_msgs__msg__DarknetBoundingBox__FIELD_NAME__ymin, 4, 4},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_INT64,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {citrack_ros_msgs__msg__DarknetBoundingBox__FIELD_NAME__xmax, 4, 4},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_INT64,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {citrack_ros_msgs__msg__DarknetBoundingBox__FIELD_NAME__ymax, 4, 4},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_INT64,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {citrack_ros_msgs__msg__DarknetBoundingBox__FIELD_NAME__id, 2, 2},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_INT16,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {citrack_ros_msgs__msg__DarknetBoundingBox__FIELD_NAME__class_name, 10, 10},
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
citrack_ros_msgs__msg__DarknetBoundingBox__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {citrack_ros_msgs__msg__DarknetBoundingBox__TYPE_NAME, 39, 39},
      {citrack_ros_msgs__msg__DarknetBoundingBox__FIELDS, 7, 7},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "float64 probability\n"
  "int64 xmin\n"
  "int64 ymin\n"
  "int64 xmax\n"
  "int64 ymax\n"
  "int16 id\n"
  "string class_name";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
citrack_ros_msgs__msg__DarknetBoundingBox__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {citrack_ros_msgs__msg__DarknetBoundingBox__TYPE_NAME, 39, 39},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 90, 90},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
citrack_ros_msgs__msg__DarknetBoundingBox__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *citrack_ros_msgs__msg__DarknetBoundingBox__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}
