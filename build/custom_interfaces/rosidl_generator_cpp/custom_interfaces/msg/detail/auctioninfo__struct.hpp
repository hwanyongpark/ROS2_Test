// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from custom_interfaces:msg/Auctioninfo.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_INTERFACES__MSG__DETAIL__AUCTIONINFO__STRUCT_HPP_
#define CUSTOM_INTERFACES__MSG__DETAIL__AUCTIONINFO__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__custom_interfaces__msg__Auctioninfo __attribute__((deprecated))
#else
# define DEPRECATED__custom_interfaces__msg__Auctioninfo __declspec(deprecated)
#endif

namespace custom_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Auctioninfo_
{
  using Type = Auctioninfo_<ContainerAllocator>;

  explicit Auctioninfo_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->agent_id = 0l;
    }
  }

  explicit Auctioninfo_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->agent_id = 0l;
    }
  }

  // field types and members
  using _agent_id_type =
    int32_t;
  _agent_id_type agent_id;
  using _price_type =
    std::vector<float, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<float>>;
  _price_type price;
  using _bidder_type =
    std::vector<int32_t, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<int32_t>>;
  _bidder_type bidder;
  using _isdone_type =
    std::vector<bool, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<bool>>;
  _isdone_type isdone;

  // setters for named parameter idiom
  Type & set__agent_id(
    const int32_t & _arg)
  {
    this->agent_id = _arg;
    return *this;
  }
  Type & set__price(
    const std::vector<float, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<float>> & _arg)
  {
    this->price = _arg;
    return *this;
  }
  Type & set__bidder(
    const std::vector<int32_t, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<int32_t>> & _arg)
  {
    this->bidder = _arg;
    return *this;
  }
  Type & set__isdone(
    const std::vector<bool, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<bool>> & _arg)
  {
    this->isdone = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    custom_interfaces::msg::Auctioninfo_<ContainerAllocator> *;
  using ConstRawPtr =
    const custom_interfaces::msg::Auctioninfo_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<custom_interfaces::msg::Auctioninfo_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<custom_interfaces::msg::Auctioninfo_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      custom_interfaces::msg::Auctioninfo_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<custom_interfaces::msg::Auctioninfo_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      custom_interfaces::msg::Auctioninfo_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<custom_interfaces::msg::Auctioninfo_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<custom_interfaces::msg::Auctioninfo_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<custom_interfaces::msg::Auctioninfo_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__custom_interfaces__msg__Auctioninfo
    std::shared_ptr<custom_interfaces::msg::Auctioninfo_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__custom_interfaces__msg__Auctioninfo
    std::shared_ptr<custom_interfaces::msg::Auctioninfo_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Auctioninfo_ & other) const
  {
    if (this->agent_id != other.agent_id) {
      return false;
    }
    if (this->price != other.price) {
      return false;
    }
    if (this->bidder != other.bidder) {
      return false;
    }
    if (this->isdone != other.isdone) {
      return false;
    }
    return true;
  }
  bool operator!=(const Auctioninfo_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Auctioninfo_

// alias to use template instance with default allocator
using Auctioninfo =
  custom_interfaces::msg::Auctioninfo_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace custom_interfaces

#endif  // CUSTOM_INTERFACES__MSG__DETAIL__AUCTIONINFO__STRUCT_HPP_
