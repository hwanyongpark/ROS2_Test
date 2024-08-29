// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from custom_interfaces:msg/Vehiclestate.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_INTERFACES__MSG__DETAIL__VEHICLESTATE__TRAITS_HPP_
#define CUSTOM_INTERFACES__MSG__DETAIL__VEHICLESTATE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "custom_interfaces/msg/detail/vehiclestate__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace custom_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const Vehiclestate & msg,
  std::ostream & out)
{
  out << "{";
  // member: name
  {
    out << "name: ";
    rosidl_generator_traits::value_to_yaml(msg.name, out);
    out << ", ";
  }

  // member: position_x
  {
    out << "position_x: ";
    rosidl_generator_traits::value_to_yaml(msg.position_x, out);
    out << ", ";
  }

  // member: position_y
  {
    out << "position_y: ";
    rosidl_generator_traits::value_to_yaml(msg.position_y, out);
    out << ", ";
  }

  // member: position_z
  {
    out << "position_z: ";
    rosidl_generator_traits::value_to_yaml(msg.position_z, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Vehiclestate & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: name
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "name: ";
    rosidl_generator_traits::value_to_yaml(msg.name, out);
    out << "\n";
  }

  // member: position_x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "position_x: ";
    rosidl_generator_traits::value_to_yaml(msg.position_x, out);
    out << "\n";
  }

  // member: position_y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "position_y: ";
    rosidl_generator_traits::value_to_yaml(msg.position_y, out);
    out << "\n";
  }

  // member: position_z
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "position_z: ";
    rosidl_generator_traits::value_to_yaml(msg.position_z, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Vehiclestate & msg, bool use_flow_style = false)
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
  const custom_interfaces::msg::Vehiclestate & msg,
  std::ostream & out, size_t indentation = 0)
{
  custom_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use custom_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const custom_interfaces::msg::Vehiclestate & msg)
{
  return custom_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<custom_interfaces::msg::Vehiclestate>()
{
  return "custom_interfaces::msg::Vehiclestate";
}

template<>
inline const char * name<custom_interfaces::msg::Vehiclestate>()
{
  return "custom_interfaces/msg/Vehiclestate";
}

template<>
struct has_fixed_size<custom_interfaces::msg::Vehiclestate>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<custom_interfaces::msg::Vehiclestate>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<custom_interfaces::msg::Vehiclestate>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // CUSTOM_INTERFACES__MSG__DETAIL__VEHICLESTATE__TRAITS_HPP_
