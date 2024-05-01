// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from multi_agent_comm:msg/AgentMessage.idl
// generated code does not contain a copyright notice

#ifndef MULTI_AGENT_COMM__MSG__DETAIL__AGENT_MESSAGE__BUILDER_HPP_
#define MULTI_AGENT_COMM__MSG__DETAIL__AGENT_MESSAGE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "multi_agent_comm/msg/detail/agent_message__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace multi_agent_comm
{

namespace msg
{

namespace builder
{

class Init_AgentMessage_formatted_time
{
public:
  explicit Init_AgentMessage_formatted_time(::multi_agent_comm::msg::AgentMessage & msg)
  : msg_(msg)
  {}
  ::multi_agent_comm::msg::AgentMessage formatted_time(::multi_agent_comm::msg::AgentMessage::_formatted_time_type arg)
  {
    msg_.formatted_time = std::move(arg);
    return std::move(msg_);
  }

private:
  ::multi_agent_comm::msg::AgentMessage msg_;
};

class Init_AgentMessage_timestamp
{
public:
  explicit Init_AgentMessage_timestamp(::multi_agent_comm::msg::AgentMessage & msg)
  : msg_(msg)
  {}
  Init_AgentMessage_formatted_time timestamp(::multi_agent_comm::msg::AgentMessage::_timestamp_type arg)
  {
    msg_.timestamp = std::move(arg);
    return Init_AgentMessage_formatted_time(msg_);
  }

private:
  ::multi_agent_comm::msg::AgentMessage msg_;
};

class Init_AgentMessage_status
{
public:
  explicit Init_AgentMessage_status(::multi_agent_comm::msg::AgentMessage & msg)
  : msg_(msg)
  {}
  Init_AgentMessage_timestamp status(::multi_agent_comm::msg::AgentMessage::_status_type arg)
  {
    msg_.status = std::move(arg);
    return Init_AgentMessage_timestamp(msg_);
  }

private:
  ::multi_agent_comm::msg::AgentMessage msg_;
};

class Init_AgentMessage_agent_id
{
public:
  Init_AgentMessage_agent_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_AgentMessage_status agent_id(::multi_agent_comm::msg::AgentMessage::_agent_id_type arg)
  {
    msg_.agent_id = std::move(arg);
    return Init_AgentMessage_status(msg_);
  }

private:
  ::multi_agent_comm::msg::AgentMessage msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::multi_agent_comm::msg::AgentMessage>()
{
  return multi_agent_comm::msg::builder::Init_AgentMessage_agent_id();
}

}  // namespace multi_agent_comm

#endif  // MULTI_AGENT_COMM__MSG__DETAIL__AGENT_MESSAGE__BUILDER_HPP_
