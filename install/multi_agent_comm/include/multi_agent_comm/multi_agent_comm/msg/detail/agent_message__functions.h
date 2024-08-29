// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from multi_agent_comm:msg/AgentMessage.idl
// generated code does not contain a copyright notice

#ifndef MULTI_AGENT_COMM__MSG__DETAIL__AGENT_MESSAGE__FUNCTIONS_H_
#define MULTI_AGENT_COMM__MSG__DETAIL__AGENT_MESSAGE__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "multi_agent_comm/msg/rosidl_generator_c__visibility_control.h"

#include "multi_agent_comm/msg/detail/agent_message__struct.h"

/// Initialize msg/AgentMessage message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * multi_agent_comm__msg__AgentMessage
 * )) before or use
 * multi_agent_comm__msg__AgentMessage__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_multi_agent_comm
bool
multi_agent_comm__msg__AgentMessage__init(multi_agent_comm__msg__AgentMessage * msg);

/// Finalize msg/AgentMessage message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_multi_agent_comm
void
multi_agent_comm__msg__AgentMessage__fini(multi_agent_comm__msg__AgentMessage * msg);

/// Create msg/AgentMessage message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * multi_agent_comm__msg__AgentMessage__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_multi_agent_comm
multi_agent_comm__msg__AgentMessage *
multi_agent_comm__msg__AgentMessage__create();

/// Destroy msg/AgentMessage message.
/**
 * It calls
 * multi_agent_comm__msg__AgentMessage__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_multi_agent_comm
void
multi_agent_comm__msg__AgentMessage__destroy(multi_agent_comm__msg__AgentMessage * msg);

/// Check for msg/AgentMessage message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_multi_agent_comm
bool
multi_agent_comm__msg__AgentMessage__are_equal(const multi_agent_comm__msg__AgentMessage * lhs, const multi_agent_comm__msg__AgentMessage * rhs);

/// Copy a msg/AgentMessage message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_multi_agent_comm
bool
multi_agent_comm__msg__AgentMessage__copy(
  const multi_agent_comm__msg__AgentMessage * input,
  multi_agent_comm__msg__AgentMessage * output);

/// Initialize array of msg/AgentMessage messages.
/**
 * It allocates the memory for the number of elements and calls
 * multi_agent_comm__msg__AgentMessage__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_multi_agent_comm
bool
multi_agent_comm__msg__AgentMessage__Sequence__init(multi_agent_comm__msg__AgentMessage__Sequence * array, size_t size);

/// Finalize array of msg/AgentMessage messages.
/**
 * It calls
 * multi_agent_comm__msg__AgentMessage__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_multi_agent_comm
void
multi_agent_comm__msg__AgentMessage__Sequence__fini(multi_agent_comm__msg__AgentMessage__Sequence * array);

/// Create array of msg/AgentMessage messages.
/**
 * It allocates the memory for the array and calls
 * multi_agent_comm__msg__AgentMessage__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_multi_agent_comm
multi_agent_comm__msg__AgentMessage__Sequence *
multi_agent_comm__msg__AgentMessage__Sequence__create(size_t size);

/// Destroy array of msg/AgentMessage messages.
/**
 * It calls
 * multi_agent_comm__msg__AgentMessage__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_multi_agent_comm
void
multi_agent_comm__msg__AgentMessage__Sequence__destroy(multi_agent_comm__msg__AgentMessage__Sequence * array);

/// Check for msg/AgentMessage message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_multi_agent_comm
bool
multi_agent_comm__msg__AgentMessage__Sequence__are_equal(const multi_agent_comm__msg__AgentMessage__Sequence * lhs, const multi_agent_comm__msg__AgentMessage__Sequence * rhs);

/// Copy an array of msg/AgentMessage messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_multi_agent_comm
bool
multi_agent_comm__msg__AgentMessage__Sequence__copy(
  const multi_agent_comm__msg__AgentMessage__Sequence * input,
  multi_agent_comm__msg__AgentMessage__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // MULTI_AGENT_COMM__MSG__DETAIL__AGENT_MESSAGE__FUNCTIONS_H_
