// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from custom_interfaces:msg/Tasklist.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_INTERFACES__MSG__DETAIL__TASKLIST__BUILDER_HPP_
#define CUSTOM_INTERFACES__MSG__DETAIL__TASKLIST__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "custom_interfaces/msg/detail/tasklist__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace custom_interfaces
{

namespace msg
{

namespace builder
{

class Init_Tasklist_tasks
{
public:
  Init_Tasklist_tasks()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::custom_interfaces::msg::Tasklist tasks(::custom_interfaces::msg::Tasklist::_tasks_type arg)
  {
    msg_.tasks = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custom_interfaces::msg::Tasklist msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_interfaces::msg::Tasklist>()
{
  return custom_interfaces::msg::builder::Init_Tasklist_tasks();
}

}  // namespace custom_interfaces

#endif  // CUSTOM_INTERFACES__MSG__DETAIL__TASKLIST__BUILDER_HPP_
