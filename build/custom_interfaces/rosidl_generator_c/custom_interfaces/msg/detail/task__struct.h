// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from custom_interfaces:msg/Task.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_INTERFACES__MSG__DETAIL__TASK__STRUCT_H_
#define CUSTOM_INTERFACES__MSG__DETAIL__TASK__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'task_name'
#include "rosidl_runtime_c/string.h"
// Member 'task_position'
#include "geometry_msgs/msg/detail/point__struct.h"

/// Struct defined in msg/Task in the package custom_interfaces.
typedef struct custom_interfaces__msg__Task
{
  rosidl_runtime_c__String task_name;
  geometry_msgs__msg__Point task_position;
  bool task_status;
} custom_interfaces__msg__Task;

// Struct for a sequence of custom_interfaces__msg__Task.
typedef struct custom_interfaces__msg__Task__Sequence
{
  custom_interfaces__msg__Task * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} custom_interfaces__msg__Task__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // CUSTOM_INTERFACES__MSG__DETAIL__TASK__STRUCT_H_
