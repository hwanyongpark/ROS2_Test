// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__rosidl_typesupport_fastrtps_cpp.hpp.em
// with input from multi_agent_comm:msg/AgentMessage.idl
// generated code does not contain a copyright notice

#ifndef MULTI_AGENT_COMM__MSG__DETAIL__AGENT_MESSAGE__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
#define MULTI_AGENT_COMM__MSG__DETAIL__AGENT_MESSAGE__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_

#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_interface/macros.h"
#include "multi_agent_comm/msg/rosidl_typesupport_fastrtps_cpp__visibility_control.h"
#include "multi_agent_comm/msg/detail/agent_message__struct.hpp"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

#include "fastcdr/Cdr.h"

namespace multi_agent_comm
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_multi_agent_comm
cdr_serialize(
  const multi_agent_comm::msg::AgentMessage & ros_message,
  eprosima::fastcdr::Cdr & cdr);

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_multi_agent_comm
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  multi_agent_comm::msg::AgentMessage & ros_message);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_multi_agent_comm
get_serialized_size(
  const multi_agent_comm::msg::AgentMessage & ros_message,
  size_t current_alignment);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_multi_agent_comm
max_serialized_size_AgentMessage(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace multi_agent_comm

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_multi_agent_comm
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, multi_agent_comm, msg, AgentMessage)();

#ifdef __cplusplus
}
#endif

#endif  // MULTI_AGENT_COMM__MSG__DETAIL__AGENT_MESSAGE__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
