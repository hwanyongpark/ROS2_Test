// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from custom_interfaces:msg/Task.idl
// generated code does not contain a copyright notice
#include "custom_interfaces/msg/detail/task__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `task_name`
#include "rosidl_runtime_c/string_functions.h"
// Member `task_position`
#include "geometry_msgs/msg/detail/point__functions.h"

bool
custom_interfaces__msg__Task__init(custom_interfaces__msg__Task * msg)
{
  if (!msg) {
    return false;
  }
  // task_name
  if (!rosidl_runtime_c__String__init(&msg->task_name)) {
    custom_interfaces__msg__Task__fini(msg);
    return false;
  }
  // task_position
  if (!geometry_msgs__msg__Point__init(&msg->task_position)) {
    custom_interfaces__msg__Task__fini(msg);
    return false;
  }
  // task_status
  return true;
}

void
custom_interfaces__msg__Task__fini(custom_interfaces__msg__Task * msg)
{
  if (!msg) {
    return;
  }
  // task_name
  rosidl_runtime_c__String__fini(&msg->task_name);
  // task_position
  geometry_msgs__msg__Point__fini(&msg->task_position);
  // task_status
}

bool
custom_interfaces__msg__Task__are_equal(const custom_interfaces__msg__Task * lhs, const custom_interfaces__msg__Task * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // task_name
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->task_name), &(rhs->task_name)))
  {
    return false;
  }
  // task_position
  if (!geometry_msgs__msg__Point__are_equal(
      &(lhs->task_position), &(rhs->task_position)))
  {
    return false;
  }
  // task_status
  if (lhs->task_status != rhs->task_status) {
    return false;
  }
  return true;
}

bool
custom_interfaces__msg__Task__copy(
  const custom_interfaces__msg__Task * input,
  custom_interfaces__msg__Task * output)
{
  if (!input || !output) {
    return false;
  }
  // task_name
  if (!rosidl_runtime_c__String__copy(
      &(input->task_name), &(output->task_name)))
  {
    return false;
  }
  // task_position
  if (!geometry_msgs__msg__Point__copy(
      &(input->task_position), &(output->task_position)))
  {
    return false;
  }
  // task_status
  output->task_status = input->task_status;
  return true;
}

custom_interfaces__msg__Task *
custom_interfaces__msg__Task__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  custom_interfaces__msg__Task * msg = (custom_interfaces__msg__Task *)allocator.allocate(sizeof(custom_interfaces__msg__Task), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(custom_interfaces__msg__Task));
  bool success = custom_interfaces__msg__Task__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
custom_interfaces__msg__Task__destroy(custom_interfaces__msg__Task * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    custom_interfaces__msg__Task__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
custom_interfaces__msg__Task__Sequence__init(custom_interfaces__msg__Task__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  custom_interfaces__msg__Task * data = NULL;

  if (size) {
    data = (custom_interfaces__msg__Task *)allocator.zero_allocate(size, sizeof(custom_interfaces__msg__Task), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = custom_interfaces__msg__Task__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        custom_interfaces__msg__Task__fini(&data[i - 1]);
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
custom_interfaces__msg__Task__Sequence__fini(custom_interfaces__msg__Task__Sequence * array)
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
      custom_interfaces__msg__Task__fini(&array->data[i]);
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

custom_interfaces__msg__Task__Sequence *
custom_interfaces__msg__Task__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  custom_interfaces__msg__Task__Sequence * array = (custom_interfaces__msg__Task__Sequence *)allocator.allocate(sizeof(custom_interfaces__msg__Task__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = custom_interfaces__msg__Task__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
custom_interfaces__msg__Task__Sequence__destroy(custom_interfaces__msg__Task__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    custom_interfaces__msg__Task__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
custom_interfaces__msg__Task__Sequence__are_equal(const custom_interfaces__msg__Task__Sequence * lhs, const custom_interfaces__msg__Task__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!custom_interfaces__msg__Task__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
custom_interfaces__msg__Task__Sequence__copy(
  const custom_interfaces__msg__Task__Sequence * input,
  custom_interfaces__msg__Task__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(custom_interfaces__msg__Task);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    custom_interfaces__msg__Task * data =
      (custom_interfaces__msg__Task *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!custom_interfaces__msg__Task__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          custom_interfaces__msg__Task__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!custom_interfaces__msg__Task__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
