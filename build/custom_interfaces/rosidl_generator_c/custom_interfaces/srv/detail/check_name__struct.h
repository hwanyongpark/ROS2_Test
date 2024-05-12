// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from custom_interfaces:srv/CheckName.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_INTERFACES__SRV__DETAIL__CHECK_NAME__STRUCT_H_
#define CUSTOM_INTERFACES__SRV__DETAIL__CHECK_NAME__STRUCT_H_

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

/// Struct defined in srv/CheckName in the package custom_interfaces.
typedef struct custom_interfaces__srv__CheckName_Request
{
  rosidl_runtime_c__String name;
} custom_interfaces__srv__CheckName_Request;

// Struct for a sequence of custom_interfaces__srv__CheckName_Request.
typedef struct custom_interfaces__srv__CheckName_Request__Sequence
{
  custom_interfaces__srv__CheckName_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} custom_interfaces__srv__CheckName_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'response'
// already included above
// #include "rosidl_runtime_c/string.h"

/// Struct defined in srv/CheckName in the package custom_interfaces.
typedef struct custom_interfaces__srv__CheckName_Response
{
  rosidl_runtime_c__String response;
} custom_interfaces__srv__CheckName_Response;

// Struct for a sequence of custom_interfaces__srv__CheckName_Response.
typedef struct custom_interfaces__srv__CheckName_Response__Sequence
{
  custom_interfaces__srv__CheckName_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} custom_interfaces__srv__CheckName_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // CUSTOM_INTERFACES__SRV__DETAIL__CHECK_NAME__STRUCT_H_
