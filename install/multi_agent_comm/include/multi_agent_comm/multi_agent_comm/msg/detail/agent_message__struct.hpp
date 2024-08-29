// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from multi_agent_comm:msg/AgentMessage.idl
// generated code does not contain a copyright notice

#ifndef MULTI_AGENT_COMM__MSG__DETAIL__AGENT_MESSAGE__STRUCT_HPP_
#define MULTI_AGENT_COMM__MSG__DETAIL__AGENT_MESSAGE__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'timestamp'
#include "builtin_interfaces/msg/detail/time__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__multi_agent_comm__msg__AgentMessage __attribute__((deprecated))
#else
# define DEPRECATED__multi_agent_comm__msg__AgentMessage __declspec(deprecated)
#endif

namespace multi_agent_comm
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct AgentMessage_
{
  using Type = AgentMessage_<ContainerAllocator>;

  explicit AgentMessage_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : timestamp(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->agent_id = 0l;
      this->status = "";
      this->formatted_time = "";
    }
  }

  explicit AgentMessage_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : status(_alloc),
    timestamp(_alloc, _init),
    formatted_time(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->agent_id = 0l;
      this->status = "";
      this->formatted_time = "";
    }
  }

  // field types and members
  using _agent_id_type =
    int32_t;
  _agent_id_type agent_id;
  using _status_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _status_type status;
  using _timestamp_type =
    builtin_interfaces::msg::Time_<ContainerAllocator>;
  _timestamp_type timestamp;
  using _formatted_time_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _formatted_time_type formatted_time;

  // setters for named parameter idiom
  Type & set__agent_id(
    const int32_t & _arg)
  {
    this->agent_id = _arg;
    return *this;
  }
  Type & set__status(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->status = _arg;
    return *this;
  }
  Type & set__timestamp(
    const builtin_interfaces::msg::Time_<ContainerAllocator> & _arg)
  {
    this->timestamp = _arg;
    return *this;
  }
  Type & set__formatted_time(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->formatted_time = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    multi_agent_comm::msg::AgentMessage_<ContainerAllocator> *;
  using ConstRawPtr =
    const multi_agent_comm::msg::AgentMessage_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<multi_agent_comm::msg::AgentMessage_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<multi_agent_comm::msg::AgentMessage_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      multi_agent_comm::msg::AgentMessage_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<multi_agent_comm::msg::AgentMessage_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      multi_agent_comm::msg::AgentMessage_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<multi_agent_comm::msg::AgentMessage_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<multi_agent_comm::msg::AgentMessage_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<multi_agent_comm::msg::AgentMessage_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__multi_agent_comm__msg__AgentMessage
    std::shared_ptr<multi_agent_comm::msg::AgentMessage_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__multi_agent_comm__msg__AgentMessage
    std::shared_ptr<multi_agent_comm::msg::AgentMessage_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const AgentMessage_ & other) const
  {
    if (this->agent_id != other.agent_id) {
      return false;
    }
    if (this->status != other.status) {
      return false;
    }
    if (this->timestamp != other.timestamp) {
      return false;
    }
    if (this->formatted_time != other.formatted_time) {
      return false;
    }
    return true;
  }
  bool operator!=(const AgentMessage_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct AgentMessage_

// alias to use template instance with default allocator
using AgentMessage =
  multi_agent_comm::msg::AgentMessage_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace multi_agent_comm

#endif  // MULTI_AGENT_COMM__MSG__DETAIL__AGENT_MESSAGE__STRUCT_HPP_
