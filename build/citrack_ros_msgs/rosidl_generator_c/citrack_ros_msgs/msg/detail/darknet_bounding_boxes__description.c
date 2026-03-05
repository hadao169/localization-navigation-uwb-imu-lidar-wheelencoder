// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from citrack_ros_msgs:msg/DarknetBoundingBoxes.idl
// generated code does not contain a copyright notice

#include "citrack_ros_msgs/msg/detail/darknet_bounding_boxes__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_citrack_ros_msgs
const rosidl_type_hash_t *
citrack_ros_msgs__msg__DarknetBoundingBoxes__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xf7, 0xf9, 0x68, 0x59, 0xee, 0xac, 0x14, 0x5f,
      0xcc, 0x74, 0xb5, 0x56, 0x44, 0xe8, 0x67, 0x45,
      0xb4, 0x57, 0xfa, 0x9a, 0xfe, 0xfd, 0xd2, 0x57,
      0xce, 0xf5, 0x8c, 0x82, 0xcf, 0x9e, 0x81, 0x2d,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types
#include "std_msgs/msg/detail/header__functions.h"
#include "builtin_interfaces/msg/detail/time__functions.h"
#include "citrack_ros_msgs/msg/detail/darknet_bounding_box__functions.h"

// Hashes for external referenced types
#ifndef NDEBUG
static const rosidl_type_hash_t builtin_interfaces__msg__Time__EXPECTED_HASH = {1, {
    0xb1, 0x06, 0x23, 0x5e, 0x25, 0xa4, 0xc5, 0xed,
    0x35, 0x09, 0x8a, 0xa0, 0xa6, 0x1a, 0x3e, 0xe9,
    0xc9, 0xb1, 0x8d, 0x19, 0x7f, 0x39, 0x8b, 0x0e,
    0x42, 0x06, 0xce, 0xa9, 0xac, 0xf9, 0xc1, 0x97,
  }};
static const rosidl_type_hash_t citrack_ros_msgs__msg__DarknetBoundingBox__EXPECTED_HASH = {1, {
    0x84, 0x86, 0x0f, 0x1a, 0x4c, 0x30, 0x9e, 0x4b,
    0x85, 0x0a, 0xa1, 0x62, 0x55, 0xac, 0xa0, 0x28,
    0x77, 0x77, 0x65, 0x28, 0x92, 0x7c, 0x06, 0x6a,
    0x70, 0x2a, 0xf2, 0x8e, 0xa6, 0xeb, 0xf8, 0x7d,
  }};
static const rosidl_type_hash_t std_msgs__msg__Header__EXPECTED_HASH = {1, {
    0xf4, 0x9f, 0xb3, 0xae, 0x2c, 0xf0, 0x70, 0xf7,
    0x93, 0x64, 0x5f, 0xf7, 0x49, 0x68, 0x3a, 0xc6,
    0xb0, 0x62, 0x03, 0xe4, 0x1c, 0x89, 0x1e, 0x17,
    0x70, 0x1b, 0x1c, 0xb5, 0x97, 0xce, 0x6a, 0x01,
  }};
#endif

static char citrack_ros_msgs__msg__DarknetBoundingBoxes__TYPE_NAME[] = "citrack_ros_msgs/msg/DarknetBoundingBoxes";
static char builtin_interfaces__msg__Time__TYPE_NAME[] = "builtin_interfaces/msg/Time";
static char citrack_ros_msgs__msg__DarknetBoundingBox__TYPE_NAME[] = "citrack_ros_msgs/msg/DarknetBoundingBox";
static char std_msgs__msg__Header__TYPE_NAME[] = "std_msgs/msg/Header";

// Define type names, field names, and default values
static char citrack_ros_msgs__msg__DarknetBoundingBoxes__FIELD_NAME__header[] = "header";
static char citrack_ros_msgs__msg__DarknetBoundingBoxes__FIELD_NAME__image_header[] = "image_header";
static char citrack_ros_msgs__msg__DarknetBoundingBoxes__FIELD_NAME__bounding_boxes[] = "bounding_boxes";

static rosidl_runtime_c__type_description__Field citrack_ros_msgs__msg__DarknetBoundingBoxes__FIELDS[] = {
  {
    {citrack_ros_msgs__msg__DarknetBoundingBoxes__FIELD_NAME__header, 6, 6},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {std_msgs__msg__Header__TYPE_NAME, 19, 19},
    },
    {NULL, 0, 0},
  },
  {
    {citrack_ros_msgs__msg__DarknetBoundingBoxes__FIELD_NAME__image_header, 12, 12},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {std_msgs__msg__Header__TYPE_NAME, 19, 19},
    },
    {NULL, 0, 0},
  },
  {
    {citrack_ros_msgs__msg__DarknetBoundingBoxes__FIELD_NAME__bounding_boxes, 14, 14},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE_UNBOUNDED_SEQUENCE,
      0,
      0,
      {citrack_ros_msgs__msg__DarknetBoundingBox__TYPE_NAME, 39, 39},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription citrack_ros_msgs__msg__DarknetBoundingBoxes__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {builtin_interfaces__msg__Time__TYPE_NAME, 27, 27},
    {NULL, 0, 0},
  },
  {
    {citrack_ros_msgs__msg__DarknetBoundingBox__TYPE_NAME, 39, 39},
    {NULL, 0, 0},
  },
  {
    {std_msgs__msg__Header__TYPE_NAME, 19, 19},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
citrack_ros_msgs__msg__DarknetBoundingBoxes__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {citrack_ros_msgs__msg__DarknetBoundingBoxes__TYPE_NAME, 41, 41},
      {citrack_ros_msgs__msg__DarknetBoundingBoxes__FIELDS, 3, 3},
    },
    {citrack_ros_msgs__msg__DarknetBoundingBoxes__REFERENCED_TYPE_DESCRIPTIONS, 3, 3},
  };
  if (!constructed) {
    assert(0 == memcmp(&builtin_interfaces__msg__Time__EXPECTED_HASH, builtin_interfaces__msg__Time__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = builtin_interfaces__msg__Time__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&citrack_ros_msgs__msg__DarknetBoundingBox__EXPECTED_HASH, citrack_ros_msgs__msg__DarknetBoundingBox__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[1].fields = citrack_ros_msgs__msg__DarknetBoundingBox__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&std_msgs__msg__Header__EXPECTED_HASH, std_msgs__msg__Header__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[2].fields = std_msgs__msg__Header__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "std_msgs/Header header\n"
  "std_msgs/Header image_header\n"
  "DarknetBoundingBox[] bounding_boxes";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
citrack_ros_msgs__msg__DarknetBoundingBoxes__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {citrack_ros_msgs__msg__DarknetBoundingBoxes__TYPE_NAME, 41, 41},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 88, 88},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
citrack_ros_msgs__msg__DarknetBoundingBoxes__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[4];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 4, 4};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *citrack_ros_msgs__msg__DarknetBoundingBoxes__get_individual_type_description_source(NULL),
    sources[1] = *builtin_interfaces__msg__Time__get_individual_type_description_source(NULL);
    sources[2] = *citrack_ros_msgs__msg__DarknetBoundingBox__get_individual_type_description_source(NULL);
    sources[3] = *std_msgs__msg__Header__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}
