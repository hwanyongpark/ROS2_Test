// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from custom_interfaces:msg/Auctioninfo.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_INTERFACES__MSG__DETAIL__AUCTIONINFO__BUILDER_HPP_
#define CUSTOM_INTERFACES__MSG__DETAIL__AUCTIONINFO__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "custom_interfaces/msg/detail/auctioninfo__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace custom_interfaces
{

namespace msg
{

namespace builder
{

class Init_Auctioninfo_timestamp
{
public:
  explicit Init_Auctioninfo_timestamp(::custom_interfaces::msg::Auctioninfo & msg)
  : msg_(msg)
  {}
  ::custom_interfaces::msg::Auctioninfo timestamp(::custom_interfaces::msg::Auctioninfo::_timestamp_type arg)
  {
    msg_.timestamp = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custom_interfaces::msg::Auctioninfo msg_;
};

class Init_Auctioninfo_task_list
{
public:
  explicit Init_Auctioninfo_task_list(::custom_interfaces::msg::Auctioninfo & msg)
  : msg_(msg)
  {}
  Init_Auctioninfo_timestamp task_list(::custom_interfaces::msg::Auctioninfo::_task_list_type arg)
  {
    msg_.task_list = std::move(arg);
    return Init_Auctioninfo_timestamp(msg_);
  }

private:
  ::custom_interfaces::msg::Auctioninfo msg_;
};

class Init_Auctioninfo_isdone
{
public:
  explicit Init_Auctioninfo_isdone(::custom_interfaces::msg::Auctioninfo & msg)
  : msg_(msg)
  {}
  Init_Auctioninfo_task_list isdone(::custom_interfaces::msg::Auctioninfo::_isdone_type arg)
  {
    msg_.isdone = std::move(arg);
    return Init_Auctioninfo_task_list(msg_);
  }

private:
  ::custom_interfaces::msg::Auctioninfo msg_;
};

class Init_Auctioninfo_bidder
{
public:
  explicit Init_Auctioninfo_bidder(::custom_interfaces::msg::Auctioninfo & msg)
  : msg_(msg)
  {}
  Init_Auctioninfo_isdone bidder(::custom_interfaces::msg::Auctioninfo::_bidder_type arg)
  {
    msg_.bidder = std::move(arg);
    return Init_Auctioninfo_isdone(msg_);
  }

private:
  ::custom_interfaces::msg::Auctioninfo msg_;
};

class Init_Auctioninfo_price
{
public:
  explicit Init_Auctioninfo_price(::custom_interfaces::msg::Auctioninfo & msg)
  : msg_(msg)
  {}
  Init_Auctioninfo_bidder price(::custom_interfaces::msg::Auctioninfo::_price_type arg)
  {
    msg_.price = std::move(arg);
    return Init_Auctioninfo_bidder(msg_);
  }

private:
  ::custom_interfaces::msg::Auctioninfo msg_;
};

class Init_Auctioninfo_agent_id
{
public:
  Init_Auctioninfo_agent_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Auctioninfo_price agent_id(::custom_interfaces::msg::Auctioninfo::_agent_id_type arg)
  {
    msg_.agent_id = std::move(arg);
    return Init_Auctioninfo_price(msg_);
  }

private:
  ::custom_interfaces::msg::Auctioninfo msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_interfaces::msg::Auctioninfo>()
{
  return custom_interfaces::msg::builder::Init_Auctioninfo_agent_id();
}

}  // namespace custom_interfaces

#endif  // CUSTOM_INTERFACES__MSG__DETAIL__AUCTIONINFO__BUILDER_HPP_
