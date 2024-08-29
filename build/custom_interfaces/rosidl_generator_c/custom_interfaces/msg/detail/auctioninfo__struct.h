// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from custom_interfaces:msg/Auctioninfo.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_INTERFACES__MSG__DETAIL__AUCTIONINFO__STRUCT_H_
#define CUSTOM_INTERFACES__MSG__DETAIL__AUCTIONINFO__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'price'
// Member 'bidder'
// Member 'isdone'
#include "rosidl_runtime_c/primitives_sequence.h"
// Member 'task_list'
#include "custom_interfaces/msg/detail/task__struct.h"
// Member 'timestamp'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/Auctioninfo in the package custom_interfaces.
typedef struct custom_interfaces__msg__Auctioninfo
{
  int32_t agent_id;
  rosidl_runtime_c__float__Sequence price;
  rosidl_runtime_c__int32__Sequence bidder;
  rosidl_runtime_c__boolean__Sequence isdone;
  custom_interfaces__msg__Task__Sequence task_list;
  rosidl_runtime_c__String timestamp;
} custom_interfaces__msg__Auctioninfo;

// Struct for a sequence of custom_interfaces__msg__Auctioninfo.
typedef struct custom_interfaces__msg__Auctioninfo__Sequence
{
  custom_interfaces__msg__Auctioninfo * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} custom_interfaces__msg__Auctioninfo__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // CUSTOM_INTERFACES__MSG__DETAIL__AUCTIONINFO__STRUCT_H_
