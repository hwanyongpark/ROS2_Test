cmake_minimum_required(VERSION 3.5)
project(auction_node)

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(custom_interfaces REQUIRED)

add_executable(auction_node src/auction.cpp)
ament_target_dependencies(auction_node rclcpp geometry_msgs custom_interfaces)

install(TARGETS
  auction_node
  DESTINATION lib/${PROJECT_NAME})

ament_package()