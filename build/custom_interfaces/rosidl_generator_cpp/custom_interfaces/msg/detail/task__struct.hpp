// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from custom_interfaces:msg/Task.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_INTERFACES__MSG__DETAIL__TASK__STRUCT_HPP_
#define CUSTOM_INTERFACES__MSG__DETAIL__TASK__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'task_position'
#include "geometry_msgs/msg/detail/point__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__custom_interfaces__msg__Task __attribute__((deprecated))
#else
# define DEPRECATED__custom_interfaces__msg__Task __declspec(deprecated)
#endif

namespace custom_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Task_
{
  using Type = Task_<ContainerAllocator>;

  explicit Task_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : task_position(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->task_name = "";
      this->task_status = false;
    }
  }

  explicit Task_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : task_name(_alloc),
    task_position(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->task_name = "";
      this->task_status = false;
    }
  }

  // field types and members
  using _task_name_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _task_name_type task_name;
  using _task_position_type =
    geometry_msgs::msg::Point_<ContainerAllocator>;
  _task_position_type task_position;
  using _task_status_type =
    bool;
  _task_status_type task_status;

  // setters for named parameter idiom
  Type & set__task_name(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->task_name = _arg;
    return *this;
  }
  Type & set__task_position(
    const geometry_msgs::msg::Point_<ContainerAllocator> & _arg)
  {
    this->task_position = _arg;
    return *this;
  }
  Type & set__task_status(
    const bool & _arg)
  {
    this->task_status = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    custom_interfaces::msg::Task_<ContainerAllocator> *;
  using ConstRawPtr =
    const custom_interfaces::msg::Task_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<custom_interfaces::msg::Task_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<custom_interfaces::msg::Task_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      custom_interfaces::msg::Task_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<custom_interfaces::msg::Task_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      custom_interfaces::msg::Task_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<custom_interfaces::msg::Task_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<custom_interfaces::msg::Task_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<custom_interfaces::msg::Task_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__custom_interfaces__msg__Task
    std::shared_ptr<custom_interfaces::msg::Task_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__custom_interfaces__msg__Task
    std::shared_ptr<custom_interfaces::msg::Task_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Task_ & other) const
  {
    if (this->task_name != other.task_name) {
      return false;
    }
    if (this->task_position != other.task_position) {
      return false;
    }
    if (this->task_status != other.task_status) {
      return false;
    }
    return true;
  }
  bool operator!=(const Task_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Task_

// alias to use template instance with default allocator
using Task =
  custom_interfaces::msg::Task_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace custom_interfaces

#endif  // CUSTOM_INTERFACES__MSG__DETAIL__TASK__STRUCT_HPP_
