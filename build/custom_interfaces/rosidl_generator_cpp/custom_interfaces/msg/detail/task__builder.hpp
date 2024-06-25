// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from custom_interfaces:msg/Task.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_INTERFACES__MSG__DETAIL__TASK__BUILDER_HPP_
#define CUSTOM_INTERFACES__MSG__DETAIL__TASK__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "custom_interfaces/msg/detail/task__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace custom_interfaces
{

namespace msg
{

namespace builder
{

class Init_Task_task_status
{
public:
  explicit Init_Task_task_status(::custom_interfaces::msg::Task & msg)
  : msg_(msg)
  {}
  ::custom_interfaces::msg::Task task_status(::custom_interfaces::msg::Task::_task_status_type arg)
  {
    msg_.task_status = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custom_interfaces::msg::Task msg_;
};

class Init_Task_task_position
{
public:
  explicit Init_Task_task_position(::custom_interfaces::msg::Task & msg)
  : msg_(msg)
  {}
  Init_Task_task_status task_position(::custom_interfaces::msg::Task::_task_position_type arg)
  {
    msg_.task_position = std::move(arg);
    return Init_Task_task_status(msg_);
  }

private:
  ::custom_interfaces::msg::Task msg_;
};

class Init_Task_task_name
{
public:
  Init_Task_task_name()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Task_task_position task_name(::custom_interfaces::msg::Task::_task_name_type arg)
  {
    msg_.task_name = std::move(arg);
    return Init_Task_task_position(msg_);
  }

private:
  ::custom_interfaces::msg::Task msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_interfaces::msg::Task>()
{
  return custom_interfaces::msg::builder::Init_Task_task_name();
}

}  // namespace custom_interfaces

#endif  // CUSTOM_INTERFACES__MSG__DETAIL__TASK__BUILDER_HPP_
