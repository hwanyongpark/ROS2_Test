// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from custom_interfaces:msg/Tasklist.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_INTERFACES__MSG__DETAIL__TASKLIST__STRUCT_HPP_
#define CUSTOM_INTERFACES__MSG__DETAIL__TASKLIST__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'tasks'
#include "custom_interfaces/msg/detail/task__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__custom_interfaces__msg__Tasklist __attribute__((deprecated))
#else
# define DEPRECATED__custom_interfaces__msg__Tasklist __declspec(deprecated)
#endif

namespace custom_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Tasklist_
{
  using Type = Tasklist_<ContainerAllocator>;

  explicit Tasklist_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->timestamp = "";
    }
  }

  explicit Tasklist_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : timestamp(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->timestamp = "";
    }
  }

  // field types and members
  using _tasks_type =
    std::vector<custom_interfaces::msg::Task_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<custom_interfaces::msg::Task_<ContainerAllocator>>>;
  _tasks_type tasks;
  using _timestamp_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _timestamp_type timestamp;

  // setters for named parameter idiom
  Type & set__tasks(
    const std::vector<custom_interfaces::msg::Task_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<custom_interfaces::msg::Task_<ContainerAllocator>>> & _arg)
  {
    this->tasks = _arg;
    return *this;
  }
  Type & set__timestamp(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->timestamp = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    custom_interfaces::msg::Tasklist_<ContainerAllocator> *;
  using ConstRawPtr =
    const custom_interfaces::msg::Tasklist_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<custom_interfaces::msg::Tasklist_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<custom_interfaces::msg::Tasklist_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      custom_interfaces::msg::Tasklist_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<custom_interfaces::msg::Tasklist_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      custom_interfaces::msg::Tasklist_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<custom_interfaces::msg::Tasklist_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<custom_interfaces::msg::Tasklist_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<custom_interfaces::msg::Tasklist_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__custom_interfaces__msg__Tasklist
    std::shared_ptr<custom_interfaces::msg::Tasklist_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__custom_interfaces__msg__Tasklist
    std::shared_ptr<custom_interfaces::msg::Tasklist_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Tasklist_ & other) const
  {
    if (this->tasks != other.tasks) {
      return false;
    }
    if (this->timestamp != other.timestamp) {
      return false;
    }
    return true;
  }
  bool operator!=(const Tasklist_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Tasklist_

// alias to use template instance with default allocator
using Tasklist =
  custom_interfaces::msg::Tasklist_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace custom_interfaces

#endif  // CUSTOM_INTERFACES__MSG__DETAIL__TASKLIST__STRUCT_HPP_
