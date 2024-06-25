// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from custom_interfaces:msg/Task.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_INTERFACES__MSG__DETAIL__TASK__TRAITS_HPP_
#define CUSTOM_INTERFACES__MSG__DETAIL__TASK__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "custom_interfaces/msg/detail/task__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'task_position'
#include "geometry_msgs/msg/detail/point__traits.hpp"

namespace custom_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const Task & msg,
  std::ostream & out)
{
  out << "{";
  // member: task_name
  {
    out << "task_name: ";
    rosidl_generator_traits::value_to_yaml(msg.task_name, out);
    out << ", ";
  }

  // member: task_position
  {
    out << "task_position: ";
    to_flow_style_yaml(msg.task_position, out);
    out << ", ";
  }

  // member: task_status
  {
    out << "task_status: ";
    rosidl_generator_traits::value_to_yaml(msg.task_status, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Task & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: task_name
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "task_name: ";
    rosidl_generator_traits::value_to_yaml(msg.task_name, out);
    out << "\n";
  }

  // member: task_position
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "task_position:\n";
    to_block_style_yaml(msg.task_position, out, indentation + 2);
  }

  // member: task_status
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "task_status: ";
    rosidl_generator_traits::value_to_yaml(msg.task_status, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Task & msg, bool use_flow_style = false)
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

}  // namespace custom_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use custom_interfaces::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const custom_interfaces::msg::Task & msg,
  std::ostream & out, size_t indentation = 0)
{
  custom_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use custom_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const custom_interfaces::msg::Task & msg)
{
  return custom_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<custom_interfaces::msg::Task>()
{
  return "custom_interfaces::msg::Task";
}

template<>
inline const char * name<custom_interfaces::msg::Task>()
{
  return "custom_interfaces/msg/Task";
}

template<>
struct has_fixed_size<custom_interfaces::msg::Task>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<custom_interfaces::msg::Task>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<custom_interfaces::msg::Task>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // CUSTOM_INTERFACES__MSG__DETAIL__TASK__TRAITS_HPP_
