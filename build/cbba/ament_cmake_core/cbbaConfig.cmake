# generated from ament/cmake/core/templates/nameConfig.cmake.in

# prevent multiple inclusion
if(_cbba_CONFIG_INCLUDED)
  # ensure to keep the found flag the same
  if(NOT DEFINED cbba_FOUND)
    # explicitly set it to FALSE, otherwise CMake will set it to TRUE
    set(cbba_FOUND FALSE)
  elseif(NOT cbba_FOUND)
    # use separate condition to avoid uninitialized variable warning
    set(cbba_FOUND FALSE)
  endif()
  return()
endif()
set(_cbba_CONFIG_INCLUDED TRUE)

# output package information
if(NOT cbba_FIND_QUIETLY)
  message(STATUS "Found cbba: 0.0.0 (${cbba_DIR})")
endif()

# warn when using a deprecated package
if(NOT "" STREQUAL "")
  set(_msg "Package 'cbba' is deprecated")
  # append custom deprecation text if available
  if(NOT "" STREQUAL "TRUE")
    set(_msg "${_msg} ()")
  endif()
  # optionally quiet the deprecation message
  if(NOT ${cbba_DEPRECATED_QUIET})
    message(DEPRECATION "${_msg}")
  endif()
endif()

# flag package as ament-based to distinguish it after being find_package()-ed
set(cbba_FOUND_AMENT_PACKAGE TRUE)

# include all config extra files
set(_extras "")
foreach(_extra ${_extras})
  include("${cbba_DIR}/${_extra}")
endforeach()
