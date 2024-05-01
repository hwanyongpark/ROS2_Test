cmake_minimum_required(VERSION 3.5)
project(multi_agent_comm)

# C++14 사용
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# 의존성 찾기
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(builtin_interfaces REQUIRED)
find_package(rosidl_default_generators REQUIRED)
find_package(std_msgs REQUIRED)

# ROS 메시지 및 서비스 선언, 의존성 추가
rosidl_generate_interfaces(${PROJECT_NAME}
  "msg/AgentMessage.msg"
  DEPENDENCIES builtin_interfaces
)

# 헤더 포함
include_directories(include)

# 실행 파일 추가
add_executable(comm src/comm.cpp)
add_executable(comm_qos src/comm_qos.cpp)
add_executable(count src/count.cpp)
add_executable(multi_thread1 src/multi_thread1.cpp)
add_executable(self_loop src/self_loop.cpp)

# 실행 파일 빌드 전 메시지 헤더 생성이 완료되었는지 확인
ament_target_dependencies(comm
  rclcpp
  builtin_interfaces
)

ament_target_dependencies(comm_qos
  rclcpp
  builtin_interfaces
)

ament_target_dependencies(count
  rclcpp
  builtin_interfaces
)

ament_target_dependencies(multi_thread1
  rclcpp
  builtin_interfaces
)

ament_target_dependencies(self_loop
  rclcpp
  std_msgs
)

add_dependencies(comm
  ${PROJECT_NAME}__rosidl_generator_cpp
)

add_dependencies(comm_qos
  ${PROJECT_NAME}__rosidl_generator_cpp
)

add_dependencies(count
  ${PROJECT_NAME}__rosidl_generator_cpp
)

add_dependencies(multi_thread1
  ${PROJECT_NAME}__rosidl_generator_cpp
)

add_dependencies(self_loop
  ${PROJECT_NAME}__rosidl_generator_cpp
)

# 타입 서포트와 연결
target_link_libraries(comm
  ${PROJECT_NAME}__rosidl_typesupport_cpp
)

target_link_libraries(comm_qos
  ${PROJECT_NAME}__rosidl_typesupport_cpp
)

target_link_libraries(count
  ${PROJECT_NAME}__rosidl_typesupport_cpp
)

target_link_libraries(multi_thread1
  ${PROJECT_NAME}__rosidl_typesupport_cpp
)
target_link_libraries(self_loop
  ${PROJECT_NAME}__rosidl_typesupport_cpp
)

# 실행 파일 설치
install(TARGETS
  comm
  DESTINATION lib/${PROJECT_NAME}
)

install(TARGETS
  comm_qos
  DESTINATION lib/${PROJECT_NAME}
)

install(TARGETS
  count
  DESTINATION lib/${PROJECT_NAME}
)

install(TARGETS
  multi_thread1
  DESTINATION lib/${PROJECT_NAME}
)

install(TARGETS
  self_loop
  DESTINATION lib/${PROJECT_NAME}
)

# 하위 패키지에 정보 내보내기
ament_package()