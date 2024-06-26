// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from custom_interfaces:msg/Tasklist.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_INTERFACES__MSG__DETAIL__TASKLIST__STRUCT_H_
#define CUSTOM_INTERFACES__MSG__DETAIL__TASKLIST__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'tasks'
#include "custom_interfaces/msg/detail/task__struct.h"

/// Struct defined in msg/Tasklist in the package custom_interfaces.
typedef struct custom_interfaces__msg__Tasklist
{
  custom_interfaces__msg__Task__Sequence tasks;
} custom_interfaces__msg__Tasklist;

// Struct for a sequence of custom_interfaces__msg__Tasklist.
typedef struct custom_interfaces__msg__Tasklist__Sequence
{
  custom_interfaces__msg__Tasklist * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} custom_interfaces__msg__Tasklist__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // CUSTOM_INTERFACES__MSG__DETAIL__TASKLIST__STRUCT_H_
