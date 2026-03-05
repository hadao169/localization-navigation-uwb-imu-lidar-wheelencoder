// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from motordriver_msgs:msg/MotordriverMessage.idl
// generated code does not contain a copyright notice

#include "motordriver_msgs/msg/detail/motordriver_message__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_motordriver_msgs
const rosidl_type_hash_t *
motordriver_msgs__msg__MotordriverMessage__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xf7, 0xfa, 0xc3, 0x05, 0xb8, 0x8f, 0xc0, 0x3f,
      0x46, 0xcc, 0xbd, 0x26, 0xa9, 0x37, 0xe0, 0x84,
      0x1e, 0x42, 0x5f, 0xc0, 0x9b, 0x8c, 0xc5, 0x0c,
      0x10, 0xfc, 0x59, 0xbc, 0xd5, 0x6a, 0x72, 0x0c,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types

// Hashes for external referenced types
#ifndef NDEBUG
#endif

static char motordriver_msgs__msg__MotordriverMessage__TYPE_NAME[] = "motordriver_msgs/msg/MotordriverMessage";

// Define type names, field names, and default values
static char motordriver_msgs__msg__MotordriverMessage__FIELD_NAME__encoder1[] = "encoder1";
static char motordriver_msgs__msg__MotordriverMessage__FIELD_NAME__encoder2[] = "encoder2";
static char motordriver_msgs__msg__MotordriverMessage__FIELD_NAME__speed1[] = "speed1";
static char motordriver_msgs__msg__MotordriverMessage__FIELD_NAME__speed2[] = "speed2";
static char motordriver_msgs__msg__MotordriverMessage__FIELD_NAME__pwm1[] = "pwm1";
static char motordriver_msgs__msg__MotordriverMessage__FIELD_NAME__pwm2[] = "pwm2";

static rosidl_runtime_c__type_description__Field motordriver_msgs__msg__MotordriverMessage__FIELDS[] = {
  {
    {motordriver_msgs__msg__MotordriverMessage__FIELD_NAME__encoder1, 8, 8},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_INT32,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {motordriver_msgs__msg__MotordriverMessage__FIELD_NAME__encoder2, 8, 8},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_INT32,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {motordriver_msgs__msg__MotordriverMessage__FIELD_NAME__speed1, 6, 6},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_INT32,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {motordriver_msgs__msg__MotordriverMessage__FIELD_NAME__speed2, 6, 6},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_INT32,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {motordriver_msgs__msg__MotordriverMessage__FIELD_NAME__pwm1, 4, 4},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_INT32,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {motordriver_msgs__msg__MotordriverMessage__FIELD_NAME__pwm2, 4, 4},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_INT32,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
motordriver_msgs__msg__MotordriverMessage__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {motordriver_msgs__msg__MotordriverMessage__TYPE_NAME, 39, 39},
      {motordriver_msgs__msg__MotordriverMessage__FIELDS, 6, 6},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "int32 encoder1\n"
  "int32 encoder2\n"
  "int32 speed1\n"
  "int32 speed2\n"
  "int32 pwm1\n"
  "int32 pwm2\n"
  "";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
motordriver_msgs__msg__MotordriverMessage__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {motordriver_msgs__msg__MotordriverMessage__TYPE_NAME, 39, 39},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 79, 79},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
motordriver_msgs__msg__MotordriverMessage__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *motordriver_msgs__msg__MotordriverMessage__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}
