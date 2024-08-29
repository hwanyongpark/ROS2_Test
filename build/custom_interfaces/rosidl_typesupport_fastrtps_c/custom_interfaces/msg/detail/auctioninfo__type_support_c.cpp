// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from custom_interfaces:msg/Auctioninfo.idl
// generated code does not contain a copyright notice
#include "custom_interfaces/msg/detail/auctioninfo__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "custom_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "custom_interfaces/msg/detail/auctioninfo__struct.h"
#include "custom_interfaces/msg/detail/auctioninfo__functions.h"
#include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif

#include "custom_interfaces/msg/detail/task__functions.h"  // task_list
#include "rosidl_runtime_c/primitives_sequence.h"  // bidder, isdone, price
#include "rosidl_runtime_c/primitives_sequence_functions.h"  // bidder, isdone, price
#include "rosidl_runtime_c/string.h"  // timestamp
#include "rosidl_runtime_c/string_functions.h"  // timestamp

// forward declare type support functions
size_t get_serialized_size_custom_interfaces__msg__Task(
  const void * untyped_ros_message,
  size_t current_alignment);

size_t max_serialized_size_custom_interfaces__msg__Task(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, custom_interfaces, msg, Task)();


using _Auctioninfo__ros_msg_type = custom_interfaces__msg__Auctioninfo;

static bool _Auctioninfo__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _Auctioninfo__ros_msg_type * ros_message = static_cast<const _Auctioninfo__ros_msg_type *>(untyped_ros_message);
  // Field name: agent_id
  {
    cdr << ros_message->agent_id;
  }

  // Field name: price
  {
    size_t size = ros_message->price.size;
    auto array_ptr = ros_message->price.data;
    cdr << static_cast<uint32_t>(size);
    cdr.serializeArray(array_ptr, size);
  }

  // Field name: bidder
  {
    size_t size = ros_message->bidder.size;
    auto array_ptr = ros_message->bidder.data;
    cdr << static_cast<uint32_t>(size);
    cdr.serializeArray(array_ptr, size);
  }

  // Field name: isdone
  {
    size_t size = ros_message->isdone.size;
    auto array_ptr = ros_message->isdone.data;
    cdr << static_cast<uint32_t>(size);
    cdr.serializeArray(array_ptr, size);
  }

  // Field name: task_list
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, custom_interfaces, msg, Task
      )()->data);
    size_t size = ros_message->task_list.size;
    auto array_ptr = ros_message->task_list.data;
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; ++i) {
      if (!callbacks->cdr_serialize(
          &array_ptr[i], cdr))
      {
        return false;
      }
    }
  }

  // Field name: timestamp
  {
    const rosidl_runtime_c__String * str = &ros_message->timestamp;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  return true;
}

static bool _Auctioninfo__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _Auctioninfo__ros_msg_type * ros_message = static_cast<_Auctioninfo__ros_msg_type *>(untyped_ros_message);
  // Field name: agent_id
  {
    cdr >> ros_message->agent_id;
  }

  // Field name: price
  {
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);
    if (ros_message->price.data) {
      rosidl_runtime_c__float__Sequence__fini(&ros_message->price);
    }
    if (!rosidl_runtime_c__float__Sequence__init(&ros_message->price, size)) {
      fprintf(stderr, "failed to create array for field 'price'");
      return false;
    }
    auto array_ptr = ros_message->price.data;
    cdr.deserializeArray(array_ptr, size);
  }

  // Field name: bidder
  {
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);
    if (ros_message->bidder.data) {
      rosidl_runtime_c__int32__Sequence__fini(&ros_message->bidder);
    }
    if (!rosidl_runtime_c__int32__Sequence__init(&ros_message->bidder, size)) {
      fprintf(stderr, "failed to create array for field 'bidder'");
      return false;
    }
    auto array_ptr = ros_message->bidder.data;
    cdr.deserializeArray(array_ptr, size);
  }

  // Field name: isdone
  {
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);
    if (ros_message->isdone.data) {
      rosidl_runtime_c__boolean__Sequence__fini(&ros_message->isdone);
    }
    if (!rosidl_runtime_c__boolean__Sequence__init(&ros_message->isdone, size)) {
      fprintf(stderr, "failed to create array for field 'isdone'");
      return false;
    }
    auto array_ptr = ros_message->isdone.data;
    for (size_t i = 0; i < size; ++i) {
      uint8_t tmp;
      cdr >> tmp;
      array_ptr[i] = tmp ? true : false;
    }
  }

  // Field name: task_list
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, custom_interfaces, msg, Task
      )()->data);
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);
    if (ros_message->task_list.data) {
      custom_interfaces__msg__Task__Sequence__fini(&ros_message->task_list);
    }
    if (!custom_interfaces__msg__Task__Sequence__init(&ros_message->task_list, size)) {
      fprintf(stderr, "failed to create array for field 'task_list'");
      return false;
    }
    auto array_ptr = ros_message->task_list.data;
    for (size_t i = 0; i < size; ++i) {
      if (!callbacks->cdr_deserialize(
          cdr, &array_ptr[i]))
      {
        return false;
      }
    }
  }

  // Field name: timestamp
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->timestamp.data) {
      rosidl_runtime_c__String__init(&ros_message->timestamp);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->timestamp,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'timestamp'\n");
      return false;
    }
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_custom_interfaces
size_t get_serialized_size_custom_interfaces__msg__Auctioninfo(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _Auctioninfo__ros_msg_type * ros_message = static_cast<const _Auctioninfo__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name agent_id
  {
    size_t item_size = sizeof(ros_message->agent_id);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name price
  {
    size_t array_size = ros_message->price.size;
    auto array_ptr = ros_message->price.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name bidder
  {
    size_t array_size = ros_message->bidder.size;
    auto array_ptr = ros_message->bidder.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name isdone
  {
    size_t array_size = ros_message->isdone.size;
    auto array_ptr = ros_message->isdone.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name task_list
  {
    size_t array_size = ros_message->task_list.size;
    auto array_ptr = ros_message->task_list.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += get_serialized_size_custom_interfaces__msg__Task(
        &array_ptr[index], current_alignment);
    }
  }
  // field.name timestamp
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->timestamp.size + 1);

  return current_alignment - initial_alignment;
}

static uint32_t _Auctioninfo__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_custom_interfaces__msg__Auctioninfo(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_custom_interfaces
size_t max_serialized_size_custom_interfaces__msg__Auctioninfo(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;

  // member: agent_id
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: price
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: bidder
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: isdone
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: task_list
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);


    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_custom_interfaces__msg__Task(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }
  // member: timestamp
  {
    size_t array_size = 1;

    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = custom_interfaces__msg__Auctioninfo;
    is_plain =
      (
      offsetof(DataType, timestamp) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static size_t _Auctioninfo__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_custom_interfaces__msg__Auctioninfo(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_Auctioninfo = {
  "custom_interfaces::msg",
  "Auctioninfo",
  _Auctioninfo__cdr_serialize,
  _Auctioninfo__cdr_deserialize,
  _Auctioninfo__get_serialized_size,
  _Auctioninfo__max_serialized_size
};

static rosidl_message_type_support_t _Auctioninfo__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_Auctioninfo,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, custom_interfaces, msg, Auctioninfo)() {
  return &_Auctioninfo__type_support;
}

#if defined(__cplusplus)
}
#endif
