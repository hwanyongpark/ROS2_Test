// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from custom_interfaces:msg/Vehiclestate.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_INTERFACES__MSG__DETAIL__VEHICLESTATE__STRUCT_HPP_
#define CUSTOM_INTERFACES__MSG__DETAIL__VEHICLESTATE__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__custom_interfaces__msg__Vehiclestate __attribute__((deprecated))
#else
# define DEPRECATED__custom_interfaces__msg__Vehiclestate __declspec(deprecated)
#endif

namespace custom_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Vehiclestate_
{
  using Type = Vehiclestate_<ContainerAllocator>;

  explicit Vehiclestate_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->name = "";
      this->position_x = 0.0;
      this->position_y = 0.0;
      this->position_z = 0.0;
    }
  }

  explicit Vehiclestate_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : name(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->name = "";
      this->position_x = 0.0;
      this->position_y = 0.0;
      this->position_z = 0.0;
    }
  }

  // field types and members
  using _name_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _name_type name;
  using _position_x_type =
    double;
  _position_x_type position_x;
  using _position_y_type =
    double;
  _position_y_type position_y;
  using _position_z_type =
    double;
  _position_z_type position_z;

  // setters for named parameter idiom
  Type & set__name(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->name = _arg;
    return *this;
  }
  Type & set__position_x(
    const double & _arg)
  {
    this->position_x = _arg;
    return *this;
  }
  Type & set__position_y(
    const double & _arg)
  {
    this->position_y = _arg;
    return *this;
  }
  Type & set__position_z(
    const double & _arg)
  {
    this->position_z = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    custom_interfaces::msg::Vehiclestate_<ContainerAllocator> *;
  using ConstRawPtr =
    const custom_interfaces::msg::Vehiclestate_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<custom_interfaces::msg::Vehiclestate_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<custom_interfaces::msg::Vehiclestate_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      custom_interfaces::msg::Vehiclestate_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<custom_interfaces::msg::Vehiclestate_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      custom_interfaces::msg::Vehiclestate_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<custom_interfaces::msg::Vehiclestate_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<custom_interfaces::msg::Vehiclestate_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<custom_interfaces::msg::Vehiclestate_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__custom_interfaces__msg__Vehiclestate
    std::shared_ptr<custom_interfaces::msg::Vehiclestate_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__custom_interfaces__msg__Vehiclestate
    std::shared_ptr<custom_interfaces::msg::Vehiclestate_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Vehiclestate_ & other) const
  {
    if (this->name != other.name) {
      return false;
    }
    if (this->position_x != other.position_x) {
      return false;
    }
    if (this->position_y != other.position_y) {
      return false;
    }
    if (this->position_z != other.position_z) {
      return false;
    }
    return true;
  }
  bool operator!=(const Vehiclestate_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Vehiclestate_

// alias to use template instance with default allocator
using Vehiclestate =
  custom_interfaces::msg::Vehiclestate_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace custom_interfaces

#endif  // CUSTOM_INTERFACES__MSG__DETAIL__VEHICLESTATE__STRUCT_HPP_
