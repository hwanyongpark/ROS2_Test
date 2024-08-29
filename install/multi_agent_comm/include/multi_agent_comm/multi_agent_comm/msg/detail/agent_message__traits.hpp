// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from multi_agent_comm:msg/AgentMessage.idl
// generated code does not contain a copyright notice

#ifndef MULTI_AGENT_COMM__MSG__DETAIL__AGENT_MESSAGE__TRAITS_HPP_
#define MULTI_AGENT_COMM__MSG__DETAIL__AGENT_MESSAGE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "multi_agent_comm/msg/detail/agent_message__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'timestamp'
#include "builtin_interfaces/msg/detail/time__traits.hpp"

namespace multi_agent_comm
{

namespace msg
{

inline void to_flow_style_yaml(
  const AgentMessage & msg,
  std::ostream & out)
{
  out << "{";
  // member: agent_id
  {
    out << "agent_id: ";
    rosidl_generator_traits::value_to_yaml(msg.agent_id, out);
    out << ", ";
  }

  // member: status
  {
    out << "status: ";
    rosidl_generator_traits::value_to_yaml(msg.status, out);
    out << ", ";
  }

  // member: timestamp
  {
    out << "timestamp: ";
    to_flow_style_yaml(msg.timestamp, out);
    out << ", ";
  }

  // member: formatted_time
  {
    out << "formatted_time: ";
    rosidl_generator_traits::value_to_yaml(msg.formatted_time, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const AgentMessage & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: agent_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "agent_id: ";
    rosidl_generator_traits::value_to_yaml(msg.agent_id, out);
    out << "\n";
  }

  // member: status
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "status: ";
    rosidl_generator_traits::value_to_yaml(msg.status, out);
    out << "\n";
  }

  // member: timestamp
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "timestamp:\n";
    to_block_style_yaml(msg.timestamp, out, indentation + 2);
  }

  // member: formatted_time
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "formatted_time: ";
    rosidl_generator_traits::value_to_yaml(msg.formatted_time, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const AgentMessage & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace multi_agent_comm

namespace rosidl_generator_traits
{

[[deprecated("use multi_agent_comm::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const multi_agent_comm::msg::AgentMessage & msg,
  std::ostream & out, size_t indentation = 0)
{
  multi_agent_comm::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use multi_agent_comm::msg::to_yaml() instead")]]
inline std::string to_yaml(const multi_agent_comm::msg::AgentMessage & msg)
{
  return multi_agent_comm::msg::to_yaml(msg);
}

template<>
inline const char * data_type<multi_agent_comm::msg::AgentMessage>()
{
  return "multi_agent_comm::msg::AgentMessage";
}

template<>
inline const char * name<multi_agent_comm::msg::AgentMessage>()
{
  return "multi_agent_comm/msg/AgentMessage";
}

template<>
struct has_fixed_size<multi_agent_comm::msg::AgentMessage>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<multi_agent_comm::msg::AgentMessage>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<multi_agent_comm::msg::AgentMessage>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // MULTI_AGENT_COMM__MSG__DETAIL__AGENT_MESSAGE__TRAITS_HPP_
