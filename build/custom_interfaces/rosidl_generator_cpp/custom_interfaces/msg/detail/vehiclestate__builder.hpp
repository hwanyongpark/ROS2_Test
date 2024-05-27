// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from custom_interfaces:msg/Vehiclestate.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_INTERFACES__MSG__DETAIL__VEHICLESTATE__BUILDER_HPP_
#define CUSTOM_INTERFACES__MSG__DETAIL__VEHICLESTATE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "custom_interfaces/msg/detail/vehiclestate__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace custom_interfaces
{

namespace msg
{

namespace builder
{

class Init_Vehiclestate_position_z
{
public:
  explicit Init_Vehiclestate_position_z(::custom_interfaces::msg::Vehiclestate & msg)
  : msg_(msg)
  {}
  ::custom_interfaces::msg::Vehiclestate position_z(::custom_interfaces::msg::Vehiclestate::_position_z_type arg)
  {
    msg_.position_z = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custom_interfaces::msg::Vehiclestate msg_;
};

class Init_Vehiclestate_position_y
{
public:
  explicit Init_Vehiclestate_position_y(::custom_interfaces::msg::Vehiclestate & msg)
  : msg_(msg)
  {}
  Init_Vehiclestate_position_z position_y(::custom_interfaces::msg::Vehiclestate::_position_y_type arg)
  {
    msg_.position_y = std::move(arg);
    return Init_Vehiclestate_position_z(msg_);
  }

private:
  ::custom_interfaces::msg::Vehiclestate msg_;
};

class Init_Vehiclestate_position_x
{
public:
  explicit Init_Vehiclestate_position_x(::custom_interfaces::msg::Vehiclestate & msg)
  : msg_(msg)
  {}
  Init_Vehiclestate_position_y position_x(::custom_interfaces::msg::Vehiclestate::_position_x_type arg)
  {
    msg_.position_x = std::move(arg);
    return Init_Vehiclestate_position_y(msg_);
  }

private:
  ::custom_interfaces::msg::Vehiclestate msg_;
};

class Init_Vehiclestate_name
{
public:
  Init_Vehiclestate_name()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Vehiclestate_position_x name(::custom_interfaces::msg::Vehiclestate::_name_type arg)
  {
    msg_.name = std::move(arg);
    return Init_Vehiclestate_position_x(msg_);
  }

private:
  ::custom_interfaces::msg::Vehiclestate msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_interfaces::msg::Vehiclestate>()
{
  return custom_interfaces::msg::builder::Init_Vehiclestate_name();
}

}  // namespace custom_interfaces

#endif  // CUSTOM_INTERFACES__MSG__DETAIL__VEHICLESTATE__BUILDER_HPP_
