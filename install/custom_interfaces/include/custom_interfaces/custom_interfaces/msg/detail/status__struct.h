// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from custom_interfaces:msg/Status.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_INTERFACES__MSG__DETAIL__STATUS__STRUCT_H_
#define CUSTOM_INTERFACES__MSG__DETAIL__STATUS__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/Status in the package custom_interfaces.
typedef struct custom_interfaces__msg__Status
{
  int64_t num;
} custom_interfaces__msg__Status;

// Struct for a sequence of custom_interfaces__msg__Status.
typedef struct custom_interfaces__msg__Status__Sequence
{
  custom_interfaces__msg__Status * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} custom_interfaces__msg__Status__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // CUSTOM_INTERFACES__MSG__DETAIL__STATUS__STRUCT_H_
