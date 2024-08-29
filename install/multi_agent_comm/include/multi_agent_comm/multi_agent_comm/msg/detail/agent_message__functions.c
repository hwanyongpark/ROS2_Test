// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from multi_agent_comm:msg/AgentMessage.idl
// generated code does not contain a copyright notice
#include "multi_agent_comm/msg/detail/agent_message__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `status`
// Member `formatted_time`
#include "rosidl_runtime_c/string_functions.h"
// Member `timestamp`
#include "builtin_interfaces/msg/detail/time__functions.h"

bool
multi_agent_comm__msg__AgentMessage__init(multi_agent_comm__msg__AgentMessage * msg)
{
  if (!msg) {
    return false;
  }
  // agent_id
  // status
  if (!rosidl_runtime_c__String__init(&msg->status)) {
    multi_agent_comm__msg__AgentMessage__fini(msg);
    return false;
  }
  // timestamp
  if (!builtin_interfaces__msg__Time__init(&msg->timestamp)) {
    multi_agent_comm__msg__AgentMessage__fini(msg);
    return false;
  }
  // formatted_time
  if (!rosidl_runtime_c__String__init(&msg->formatted_time)) {
    multi_agent_comm__msg__AgentMessage__fini(msg);
    return false;
  }
  return true;
}

void
multi_agent_comm__msg__AgentMessage__fini(multi_agent_comm__msg__AgentMessage * msg)
{
  if (!msg) {
    return;
  }
  // agent_id
  // status
  rosidl_runtime_c__String__fini(&msg->status);
  // timestamp
  builtin_interfaces__msg__Time__fini(&msg->timestamp);
  // formatted_time
  rosidl_runtime_c__String__fini(&msg->formatted_time);
}

bool
multi_agent_comm__msg__AgentMessage__are_equal(const multi_agent_comm__msg__AgentMessage * lhs, const multi_agent_comm__msg__AgentMessage * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // agent_id
  if (lhs->agent_id != rhs->agent_id) {
    return false;
  }
  // status
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->status), &(rhs->status)))
  {
    return false;
  }
  // timestamp
  if (!builtin_interfaces__msg__Time__are_equal(
      &(lhs->timestamp), &(rhs->timestamp)))
  {
    return false;
  }
  // formatted_time
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->formatted_time), &(rhs->formatted_time)))
  {
    return false;
  }
  return true;
}

bool
multi_agent_comm__msg__AgentMessage__copy(
  const multi_agent_comm__msg__AgentMessage * input,
  multi_agent_comm__msg__AgentMessage * output)
{
  if (!input || !output) {
    return false;
  }
  // agent_id
  output->agent_id = input->agent_id;
  // status
  if (!rosidl_runtime_c__String__copy(
      &(input->status), &(output->status)))
  {
    return false;
  }
  // timestamp
  if (!builtin_interfaces__msg__Time__copy(
      &(input->timestamp), &(output->timestamp)))
  {
    return false;
  }
  // formatted_time
  if (!rosidl_runtime_c__String__copy(
      &(input->formatted_time), &(output->formatted_time)))
  {
    return false;
  }
  return true;
}

multi_agent_comm__msg__AgentMessage *
multi_agent_comm__msg__AgentMessage__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  multi_agent_comm__msg__AgentMessage * msg = (multi_agent_comm__msg__AgentMessage *)allocator.allocate(sizeof(multi_agent_comm__msg__AgentMessage), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(multi_agent_comm__msg__AgentMessage));
  bool success = multi_agent_comm__msg__AgentMessage__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
multi_agent_comm__msg__AgentMessage__destroy(multi_agent_comm__msg__AgentMessage * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    multi_agent_comm__msg__AgentMessage__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
multi_agent_comm__msg__AgentMessage__Sequence__init(multi_agent_comm__msg__AgentMessage__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  multi_agent_comm__msg__AgentMessage * data = NULL;

  if (size) {
    data = (multi_agent_comm__msg__AgentMessage *)allocator.zero_allocate(size, sizeof(multi_agent_comm__msg__AgentMessage), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = multi_agent_comm__msg__AgentMessage__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        multi_agent_comm__msg__AgentMessage__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
multi_agent_comm__msg__AgentMessage__Sequence__fini(multi_agent_comm__msg__AgentMessage__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      multi_agent_comm__msg__AgentMessage__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

multi_agent_comm__msg__AgentMessage__Sequence *
multi_agent_comm__msg__AgentMessage__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  multi_agent_comm__msg__AgentMessage__Sequence * array = (multi_agent_comm__msg__AgentMessage__Sequence *)allocator.allocate(sizeof(multi_agent_comm__msg__AgentMessage__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = multi_agent_comm__msg__AgentMessage__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
multi_agent_comm__msg__AgentMessage__Sequence__destroy(multi_agent_comm__msg__AgentMessage__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    multi_agent_comm__msg__AgentMessage__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
multi_agent_comm__msg__AgentMessage__Sequence__are_equal(const multi_agent_comm__msg__AgentMessage__Sequence * lhs, const multi_agent_comm__msg__AgentMessage__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!multi_agent_comm__msg__AgentMessage__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
multi_agent_comm__msg__AgentMessage__Sequence__copy(
  const multi_agent_comm__msg__AgentMessage__Sequence * input,
  multi_agent_comm__msg__AgentMessage__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(multi_agent_comm__msg__AgentMessage);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    multi_agent_comm__msg__AgentMessage * data =
      (multi_agent_comm__msg__AgentMessage *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!multi_agent_comm__msg__AgentMessage__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          multi_agent_comm__msg__AgentMessage__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!multi_agent_comm__msg__AgentMessage__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
