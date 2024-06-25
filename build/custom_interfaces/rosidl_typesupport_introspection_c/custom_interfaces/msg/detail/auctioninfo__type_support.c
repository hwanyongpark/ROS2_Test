// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from custom_interfaces:msg/Auctioninfo.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "custom_interfaces/msg/detail/auctioninfo__rosidl_typesupport_introspection_c.h"
#include "custom_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "custom_interfaces/msg/detail/auctioninfo__functions.h"
#include "custom_interfaces/msg/detail/auctioninfo__struct.h"


// Include directives for member types
// Member `price`
// Member `bidder`
// Member `isdone`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void custom_interfaces__msg__Auctioninfo__rosidl_typesupport_introspection_c__Auctioninfo_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  custom_interfaces__msg__Auctioninfo__init(message_memory);
}

void custom_interfaces__msg__Auctioninfo__rosidl_typesupport_introspection_c__Auctioninfo_fini_function(void * message_memory)
{
  custom_interfaces__msg__Auctioninfo__fini(message_memory);
}

size_t custom_interfaces__msg__Auctioninfo__rosidl_typesupport_introspection_c__size_function__Auctioninfo__price(
  const void * untyped_member)
{
  const rosidl_runtime_c__float__Sequence * member =
    (const rosidl_runtime_c__float__Sequence *)(untyped_member);
  return member->size;
}

const void * custom_interfaces__msg__Auctioninfo__rosidl_typesupport_introspection_c__get_const_function__Auctioninfo__price(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__float__Sequence * member =
    (const rosidl_runtime_c__float__Sequence *)(untyped_member);
  return &member->data[index];
}

void * custom_interfaces__msg__Auctioninfo__rosidl_typesupport_introspection_c__get_function__Auctioninfo__price(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__float__Sequence * member =
    (rosidl_runtime_c__float__Sequence *)(untyped_member);
  return &member->data[index];
}

void custom_interfaces__msg__Auctioninfo__rosidl_typesupport_introspection_c__fetch_function__Auctioninfo__price(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const float * item =
    ((const float *)
    custom_interfaces__msg__Auctioninfo__rosidl_typesupport_introspection_c__get_const_function__Auctioninfo__price(untyped_member, index));
  float * value =
    (float *)(untyped_value);
  *value = *item;
}

void custom_interfaces__msg__Auctioninfo__rosidl_typesupport_introspection_c__assign_function__Auctioninfo__price(
  void * untyped_member, size_t index, const void * untyped_value)
{
  float * item =
    ((float *)
    custom_interfaces__msg__Auctioninfo__rosidl_typesupport_introspection_c__get_function__Auctioninfo__price(untyped_member, index));
  const float * value =
    (const float *)(untyped_value);
  *item = *value;
}

bool custom_interfaces__msg__Auctioninfo__rosidl_typesupport_introspection_c__resize_function__Auctioninfo__price(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__float__Sequence * member =
    (rosidl_runtime_c__float__Sequence *)(untyped_member);
  rosidl_runtime_c__float__Sequence__fini(member);
  return rosidl_runtime_c__float__Sequence__init(member, size);
}

size_t custom_interfaces__msg__Auctioninfo__rosidl_typesupport_introspection_c__size_function__Auctioninfo__bidder(
  const void * untyped_member)
{
  const rosidl_runtime_c__int32__Sequence * member =
    (const rosidl_runtime_c__int32__Sequence *)(untyped_member);
  return member->size;
}

const void * custom_interfaces__msg__Auctioninfo__rosidl_typesupport_introspection_c__get_const_function__Auctioninfo__bidder(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__int32__Sequence * member =
    (const rosidl_runtime_c__int32__Sequence *)(untyped_member);
  return &member->data[index];
}

void * custom_interfaces__msg__Auctioninfo__rosidl_typesupport_introspection_c__get_function__Auctioninfo__bidder(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__int32__Sequence * member =
    (rosidl_runtime_c__int32__Sequence *)(untyped_member);
  return &member->data[index];
}

void custom_interfaces__msg__Auctioninfo__rosidl_typesupport_introspection_c__fetch_function__Auctioninfo__bidder(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const int32_t * item =
    ((const int32_t *)
    custom_interfaces__msg__Auctioninfo__rosidl_typesupport_introspection_c__get_const_function__Auctioninfo__bidder(untyped_member, index));
  int32_t * value =
    (int32_t *)(untyped_value);
  *value = *item;
}

void custom_interfaces__msg__Auctioninfo__rosidl_typesupport_introspection_c__assign_function__Auctioninfo__bidder(
  void * untyped_member, size_t index, const void * untyped_value)
{
  int32_t * item =
    ((int32_t *)
    custom_interfaces__msg__Auctioninfo__rosidl_typesupport_introspection_c__get_function__Auctioninfo__bidder(untyped_member, index));
  const int32_t * value =
    (const int32_t *)(untyped_value);
  *item = *value;
}

bool custom_interfaces__msg__Auctioninfo__rosidl_typesupport_introspection_c__resize_function__Auctioninfo__bidder(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__int32__Sequence * member =
    (rosidl_runtime_c__int32__Sequence *)(untyped_member);
  rosidl_runtime_c__int32__Sequence__fini(member);
  return rosidl_runtime_c__int32__Sequence__init(member, size);
}

size_t custom_interfaces__msg__Auctioninfo__rosidl_typesupport_introspection_c__size_function__Auctioninfo__isdone(
  const void * untyped_member)
{
  const rosidl_runtime_c__boolean__Sequence * member =
    (const rosidl_runtime_c__boolean__Sequence *)(untyped_member);
  return member->size;
}

const void * custom_interfaces__msg__Auctioninfo__rosidl_typesupport_introspection_c__get_const_function__Auctioninfo__isdone(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__boolean__Sequence * member =
    (const rosidl_runtime_c__boolean__Sequence *)(untyped_member);
  return &member->data[index];
}

void * custom_interfaces__msg__Auctioninfo__rosidl_typesupport_introspection_c__get_function__Auctioninfo__isdone(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__boolean__Sequence * member =
    (rosidl_runtime_c__boolean__Sequence *)(untyped_member);
  return &member->data[index];
}

void custom_interfaces__msg__Auctioninfo__rosidl_typesupport_introspection_c__fetch_function__Auctioninfo__isdone(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const bool * item =
    ((const bool *)
    custom_interfaces__msg__Auctioninfo__rosidl_typesupport_introspection_c__get_const_function__Auctioninfo__isdone(untyped_member, index));
  bool * value =
    (bool *)(untyped_value);
  *value = *item;
}

void custom_interfaces__msg__Auctioninfo__rosidl_typesupport_introspection_c__assign_function__Auctioninfo__isdone(
  void * untyped_member, size_t index, const void * untyped_value)
{
  bool * item =
    ((bool *)
    custom_interfaces__msg__Auctioninfo__rosidl_typesupport_introspection_c__get_function__Auctioninfo__isdone(untyped_member, index));
  const bool * value =
    (const bool *)(untyped_value);
  *item = *value;
}

bool custom_interfaces__msg__Auctioninfo__rosidl_typesupport_introspection_c__resize_function__Auctioninfo__isdone(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__boolean__Sequence * member =
    (rosidl_runtime_c__boolean__Sequence *)(untyped_member);
  rosidl_runtime_c__boolean__Sequence__fini(member);
  return rosidl_runtime_c__boolean__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember custom_interfaces__msg__Auctioninfo__rosidl_typesupport_introspection_c__Auctioninfo_message_member_array[4] = {
  {
    "agent_id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(custom_interfaces__msg__Auctioninfo, agent_id),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "price",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(custom_interfaces__msg__Auctioninfo, price),  // bytes offset in struct
    NULL,  // default value
    custom_interfaces__msg__Auctioninfo__rosidl_typesupport_introspection_c__size_function__Auctioninfo__price,  // size() function pointer
    custom_interfaces__msg__Auctioninfo__rosidl_typesupport_introspection_c__get_const_function__Auctioninfo__price,  // get_const(index) function pointer
    custom_interfaces__msg__Auctioninfo__rosidl_typesupport_introspection_c__get_function__Auctioninfo__price,  // get(index) function pointer
    custom_interfaces__msg__Auctioninfo__rosidl_typesupport_introspection_c__fetch_function__Auctioninfo__price,  // fetch(index, &value) function pointer
    custom_interfaces__msg__Auctioninfo__rosidl_typesupport_introspection_c__assign_function__Auctioninfo__price,  // assign(index, value) function pointer
    custom_interfaces__msg__Auctioninfo__rosidl_typesupport_introspection_c__resize_function__Auctioninfo__price  // resize(index) function pointer
  },
  {
    "bidder",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(custom_interfaces__msg__Auctioninfo, bidder),  // bytes offset in struct
    NULL,  // default value
    custom_interfaces__msg__Auctioninfo__rosidl_typesupport_introspection_c__size_function__Auctioninfo__bidder,  // size() function pointer
    custom_interfaces__msg__Auctioninfo__rosidl_typesupport_introspection_c__get_const_function__Auctioninfo__bidder,  // get_const(index) function pointer
    custom_interfaces__msg__Auctioninfo__rosidl_typesupport_introspection_c__get_function__Auctioninfo__bidder,  // get(index) function pointer
    custom_interfaces__msg__Auctioninfo__rosidl_typesupport_introspection_c__fetch_function__Auctioninfo__bidder,  // fetch(index, &value) function pointer
    custom_interfaces__msg__Auctioninfo__rosidl_typesupport_introspection_c__assign_function__Auctioninfo__bidder,  // assign(index, value) function pointer
    custom_interfaces__msg__Auctioninfo__rosidl_typesupport_introspection_c__resize_function__Auctioninfo__bidder  // resize(index) function pointer
  },
  {
    "isdone",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(custom_interfaces__msg__Auctioninfo, isdone),  // bytes offset in struct
    NULL,  // default value
    custom_interfaces__msg__Auctioninfo__rosidl_typesupport_introspection_c__size_function__Auctioninfo__isdone,  // size() function pointer
    custom_interfaces__msg__Auctioninfo__rosidl_typesupport_introspection_c__get_const_function__Auctioninfo__isdone,  // get_const(index) function pointer
    custom_interfaces__msg__Auctioninfo__rosidl_typesupport_introspection_c__get_function__Auctioninfo__isdone,  // get(index) function pointer
    custom_interfaces__msg__Auctioninfo__rosidl_typesupport_introspection_c__fetch_function__Auctioninfo__isdone,  // fetch(index, &value) function pointer
    custom_interfaces__msg__Auctioninfo__rosidl_typesupport_introspection_c__assign_function__Auctioninfo__isdone,  // assign(index, value) function pointer
    custom_interfaces__msg__Auctioninfo__rosidl_typesupport_introspection_c__resize_function__Auctioninfo__isdone  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers custom_interfaces__msg__Auctioninfo__rosidl_typesupport_introspection_c__Auctioninfo_message_members = {
  "custom_interfaces__msg",  // message namespace
  "Auctioninfo",  // message name
  4,  // number of fields
  sizeof(custom_interfaces__msg__Auctioninfo),
  custom_interfaces__msg__Auctioninfo__rosidl_typesupport_introspection_c__Auctioninfo_message_member_array,  // message members
  custom_interfaces__msg__Auctioninfo__rosidl_typesupport_introspection_c__Auctioninfo_init_function,  // function to initialize message memory (memory has to be allocated)
  custom_interfaces__msg__Auctioninfo__rosidl_typesupport_introspection_c__Auctioninfo_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t custom_interfaces__msg__Auctioninfo__rosidl_typesupport_introspection_c__Auctioninfo_message_type_support_handle = {
  0,
  &custom_interfaces__msg__Auctioninfo__rosidl_typesupport_introspection_c__Auctioninfo_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_custom_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, custom_interfaces, msg, Auctioninfo)() {
  if (!custom_interfaces__msg__Auctioninfo__rosidl_typesupport_introspection_c__Auctioninfo_message_type_support_handle.typesupport_identifier) {
    custom_interfaces__msg__Auctioninfo__rosidl_typesupport_introspection_c__Auctioninfo_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &custom_interfaces__msg__Auctioninfo__rosidl_typesupport_introspection_c__Auctioninfo_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
