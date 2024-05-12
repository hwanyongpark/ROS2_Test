cmake_minimum_required(VERSION 3.5)
project(srv_test)

# Default to C++14
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(custom_interfaces REQUIRED)  # Find the custom_interfaces package

include_directories(
  include
)

add_executable(client_node src/client_node.cpp)
ament_target_dependencies(client_node
  rclcpp
  custom_interfaces  # Link against custom_interfaces
)

add_executable(server_node src/server_node.cpp)
ament_target_dependencies(server_node
  rclcpp
  custom_interfaces  # Link against custom_interfaces
)

install(TARGETS
  client_node
  DESTINATION lib/${PROJECT_NAME}
)

install(TARGETS
  server_node
  DESTINATION lib/${PROJECT_NAME}
)

ament_package()
