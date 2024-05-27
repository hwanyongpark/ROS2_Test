// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from custom_interfaces:msg/Vehiclestate.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_INTERFACES__MSG__DETAIL__VEHICLESTATE__STRUCT_H_
#define CUSTOM_INTERFACES__MSG__DETAIL__VEHICLESTATE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'name'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/Vehiclestate in the package custom_interfaces.
typedef struct custom_interfaces__msg__Vehiclestate
{
  rosidl_runtime_c__String name;
  double position_x;
  double position_y;
  double position_z;
} custom_interfaces__msg__Vehiclestate;

// Struct for a sequence of custom_interfaces__msg__Vehiclestate.
typedef struct custom_interfaces__msg__Vehiclestate__Sequence
{
  custom_interfaces__msg__Vehiclestate * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} custom_interfaces__msg__Vehiclestate__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // CUSTOM_INTERFACES__MSG__DETAIL__VEHICLESTATE__STRUCT_H_
