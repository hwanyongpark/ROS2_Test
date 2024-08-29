// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from custom_interfaces:msg/Auctioninfo.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_INTERFACES__MSG__DETAIL__AUCTIONINFO__TRAITS_HPP_
#define CUSTOM_INTERFACES__MSG__DETAIL__AUCTIONINFO__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "custom_interfaces/msg/detail/auctioninfo__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'task_list'
#include "custom_interfaces/msg/detail/task__traits.hpp"

namespace custom_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const Auctioninfo & msg,
  std::ostream & out)
{
  out << "{";
  // member: agent_id
  {
    out << "agent_id: ";
    rosidl_generator_traits::value_to_yaml(msg.agent_id, out);
    out << ", ";
  }

  // member: price
  {
    if (msg.price.size() == 0) {
      out << "price: []";
    } else {
      out << "price: [";
      size_t pending_items = msg.price.size();
      for (auto item : msg.price) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: bidder
  {
    if (msg.bidder.size() == 0) {
      out << "bidder: []";
    } else {
      out << "bidder: [";
      size_t pending_items = msg.bidder.size();
      for (auto item : msg.bidder) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: isdone
  {
    if (msg.isdone.size() == 0) {
      out << "isdone: []";
    } else {
      out << "isdone: [";
      size_t pending_items = msg.isdone.size();
      for (auto item : msg.isdone) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: task_list
  {
    if (msg.task_list.size() == 0) {
      out << "task_list: []";
    } else {
      out << "task_list: [";
      size_t pending_items = msg.task_list.size();
      for (auto item : msg.task_list) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: timestamp
  {
    out << "timestamp: ";
    rosidl_generator_traits::value_to_yaml(msg.timestamp, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Auctioninfo & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: agent_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "agent_id: ";
    rosidl_generator_traits::value_to_yaml(msg.agent_id, out);
    out << "\n";
  }

  // member: price
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.price.size() == 0) {
      out << "price: []\n";
    } else {
      out << "price:\n";
      for (auto item : msg.price) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: bidder
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.bidder.size() == 0) {
      out << "bidder: []\n";
    } else {
      out << "bidder:\n";
      for (auto item : msg.bidder) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: isdone
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.isdone.size() == 0) {
      out << "isdone: []\n";
    } else {
      out << "isdone:\n";
      for (auto item : msg.isdone) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: task_list
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.task_list.size() == 0) {
      out << "task_list: []\n";
    } else {
      out << "task_list:\n";
      for (auto item : msg.task_list) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }

  // member: timestamp
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "timestamp: ";
    rosidl_generator_traits::value_to_yaml(msg.timestamp, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Auctioninfo & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace custom_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use custom_interfaces::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const custom_interfaces::msg::Auctioninfo & msg,
  std::ostream & out, size_t indentation = 0)
{
  custom_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use custom_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const custom_interfaces::msg::Auctioninfo & msg)
{
  return custom_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<custom_interfaces::msg::Auctioninfo>()
{
  return "custom_interfaces::msg::Auctioninfo";
}

template<>
inline const char * name<custom_interfaces::msg::Auctioninfo>()
{
  return "custom_interfaces/msg/Auctioninfo";
}

template<>
struct has_fixed_size<custom_interfaces::msg::Auctioninfo>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<custom_interfaces::msg::Auctioninfo>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<custom_interfaces::msg::Auctioninfo>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // CUSTOM_INTERFACES__MSG__DETAIL__AUCTIONINFO__TRAITS_HPP_
