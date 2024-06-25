// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from custom_interfaces:msg/Tasklist.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "custom_interfaces/msg/detail/tasklist__rosidl_typesupport_introspection_c.h"
#include "custom_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "custom_interfaces/msg/detail/tasklist__functions.h"
#include "custom_interfaces/msg/detail/tasklist__struct.h"


// Include directives for member types
// Member `tasks`
#include "custom_interfaces/msg/task.h"
// Member `tasks`
#include "custom_interfaces/msg/detail/task__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void custom_interfaces__msg__Tasklist__rosidl_typesupport_introspection_c__Tasklist_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  custom_interfaces__msg__Tasklist__init(message_memory);
}

void custom_interfaces__msg__Tasklist__rosidl_typesupport_introspection_c__Tasklist_fini_function(void * message_memory)
{
  custom_interfaces__msg__Tasklist__fini(message_memory);
}

size_t custom_interfaces__msg__Tasklist__rosidl_typesupport_introspection_c__size_function__Tasklist__tasks(
  const void * untyped_member)
{
  const custom_interfaces__msg__Task__Sequence * member =
    (const custom_interfaces__msg__Task__Sequence *)(untyped_member);
  return member->size;
}

const void * custom_interfaces__msg__Tasklist__rosidl_typesupport_introspection_c__get_const_function__Tasklist__tasks(
  const void * untyped_member, size_t index)
{
  const custom_interfaces__msg__Task__Sequence * member =
    (const custom_interfaces__msg__Task__Sequence *)(untyped_member);
  return &member->data[index];
}

void * custom_interfaces__msg__Tasklist__rosidl_typesupport_introspection_c__get_function__Tasklist__tasks(
  void * untyped_member, size_t index)
{
  custom_interfaces__msg__Task__Sequence * member =
    (custom_interfaces__msg__Task__Sequence *)(untyped_member);
  return &member->data[index];
}

void custom_interfaces__msg__Tasklist__rosidl_typesupport_introspection_c__fetch_function__Tasklist__tasks(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const custom_interfaces__msg__Task * item =
    ((const custom_interfaces__msg__Task *)
    custom_interfaces__msg__Tasklist__rosidl_typesupport_introspection_c__get_const_function__Tasklist__tasks(untyped_member, index));
  custom_interfaces__msg__Task * value =
    (custom_interfaces__msg__Task *)(untyped_value);
  *value = *item;
}

void custom_interfaces__msg__Tasklist__rosidl_typesupport_introspection_c__assign_function__Tasklist__tasks(
  void * untyped_member, size_t index, const void * untyped_value)
{
  custom_interfaces__msg__Task * item =
    ((custom_interfaces__msg__Task *)
    custom_interfaces__msg__Tasklist__rosidl_typesupport_introspection_c__get_function__Tasklist__tasks(untyped_member, index));
  const custom_interfaces__msg__Task * value =
    (const custom_interfaces__msg__Task *)(untyped_value);
  *item = *value;
}

bool custom_interfaces__msg__Tasklist__rosidl_typesupport_introspection_c__resize_function__Tasklist__tasks(
  void * untyped_member, size_t size)
{
  custom_interfaces__msg__Task__Sequence * member =
    (custom_interfaces__msg__Task__Sequence *)(untyped_member);
  custom_interfaces__msg__Task__Sequence__fini(member);
  return custom_interfaces__msg__Task__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember custom_interfaces__msg__Tasklist__rosidl_typesupport_introspection_c__Tasklist_message_member_array[1] = {
  {
    "tasks",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(custom_interfaces__msg__Tasklist, tasks),  // bytes offset in struct
    NULL,  // default value
    custom_interfaces__msg__Tasklist__rosidl_typesupport_introspection_c__size_function__Tasklist__tasks,  // size() function pointer
    custom_interfaces__msg__Tasklist__rosidl_typesupport_introspection_c__get_const_function__Tasklist__tasks,  // get_const(index) function pointer
    custom_interfaces__msg__Tasklist__rosidl_typesupport_introspection_c__get_function__Tasklist__tasks,  // get(index) function pointer
    custom_interfaces__msg__Tasklist__rosidl_typesupport_introspection_c__fetch_function__Tasklist__tasks,  // fetch(index, &value) function pointer
    custom_interfaces__msg__Tasklist__rosidl_typesupport_introspection_c__assign_function__Tasklist__tasks,  // assign(index, value) function pointer
    custom_interfaces__msg__Tasklist__rosidl_typesupport_introspection_c__resize_function__Tasklist__tasks  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers custom_interfaces__msg__Tasklist__rosidl_typesupport_introspection_c__Tasklist_message_members = {
  "custom_interfaces__msg",  // message namespace
  "Tasklist",  // message name
  1,  // number of fields
  sizeof(custom_interfaces__msg__Tasklist),
  custom_interfaces__msg__Tasklist__rosidl_typesupport_introspection_c__Tasklist_message_member_array,  // message members
  custom_interfaces__msg__Tasklist__rosidl_typesupport_introspection_c__Tasklist_init_function,  // function to initialize message memory (memory has to be allocated)
  custom_interfaces__msg__Tasklist__rosidl_typesupport_introspection_c__Tasklist_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t custom_interfaces__msg__Tasklist__rosidl_typesupport_introspection_c__Tasklist_message_type_support_handle = {
  0,
  &custom_interfaces__msg__Tasklist__rosidl_typesupport_introspection_c__Tasklist_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_custom_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, custom_interfaces, msg, Tasklist)() {
  custom_interfaces__msg__Tasklist__rosidl_typesupport_introspection_c__Tasklist_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, custom_interfaces, msg, Task)();
  if (!custom_interfaces__msg__Tasklist__rosidl_typesupport_introspection_c__Tasklist_message_type_support_handle.typesupport_identifier) {
    custom_interfaces__msg__Tasklist__rosidl_typesupport_introspection_c__Tasklist_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &custom_interfaces__msg__Tasklist__rosidl_typesupport_introspection_c__Tasklist_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
