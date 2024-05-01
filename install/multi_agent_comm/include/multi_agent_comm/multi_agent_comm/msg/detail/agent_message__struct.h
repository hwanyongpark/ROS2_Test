// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from multi_agent_comm:msg/AgentMessage.idl
// generated code does not contain a copyright notice

#ifndef MULTI_AGENT_COMM__MSG__DETAIL__AGENT_MESSAGE__STRUCT_H_
#define MULTI_AGENT_COMM__MSG__DETAIL__AGENT_MESSAGE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'status'
// Member 'formatted_time'
#include "rosidl_runtime_c/string.h"
// Member 'timestamp'
#include "builtin_interfaces/msg/detail/time__struct.h"

/// Struct defined in msg/AgentMessage in the package multi_agent_comm.
typedef struct multi_agent_comm__msg__AgentMessage
{
  int32_t agent_id;
  rosidl_runtime_c__String status;
  builtin_interfaces__msg__Time timestamp;
  rosidl_runtime_c__String formatted_time;
} multi_agent_comm__msg__AgentMessage;

// Struct for a sequence of multi_agent_comm__msg__AgentMessage.
typedef struct multi_agent_comm__msg__AgentMessage__Sequence
{
  multi_agent_comm__msg__AgentMessage * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} multi_agent_comm__msg__AgentMessage__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // MULTI_AGENT_COMM__MSG__DETAIL__AGENT_MESSAGE__STRUCT_H_
