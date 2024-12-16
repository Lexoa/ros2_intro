cmake_minimum_required(VERSION 3.5)
project(my_first_cpp_package)

# Default to C99
if(NOT CMAKE_C_STANDARD)
  set(CMAKE_C_STANDARD 99)
endif()

# Default to C++17
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 17)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(my_first_msgs REQUIRED)

#
include_directories(
  include
)

add_executable(my_first_publisher src/my_first_publisher.cpp)
ament_target_dependencies(my_first_publisher rclcpp my_first_msgs)

target_include_directories(my_first_publisher PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>
  ${CMAKE_CURRENT_BINARY_DIR}/rosidl_generator_cpp)
target_compile_features(my_first_publisher PUBLIC c_std_99 cxx_std_17)

add_executable(my_first_subscriber src/my_first_subscriber.cpp)
ament_target_dependencies(my_first_subscriber rclcpp my_first_msgs)

target_include_directories(my_first_subscriber PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>
  ${CMAKE_CURRENT_BINARY_DIR}/rosidl_generator_cpp)
target_compile_features(my_first_subscriber PUBLIC c_std_99 cxx_std_17)


install(TARGETS
  my_first_publisher
  my_first_subscriber
  DESTINATION lib/${PROJECT_NAME})

install(DIRECTORY include/
  DESTINATION include/)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # comment the line when a copyright and license is added to all source files
  set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # comment the line when this package is in a git repo and when
  # a copyright and license is added to all source files
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()