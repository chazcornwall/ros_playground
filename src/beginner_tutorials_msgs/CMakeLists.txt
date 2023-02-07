cmake_minimum_required(VERSION 3.0.2)
project(beginner_tutorials_msgs)

find_package(catkin REQUIRED COMPONENTS
  std_msgs
  message_generation
)

## Generate messages in the 'msg' folder
add_message_files(
  FILES
  Stats.msg
)

## Generate services in the 'srv' folder
add_service_files(
  FILES
  SeeStats.srv
)

## Generate added messages and services with any dependencies listed here
generate_messages(
  DEPENDENCIES
  std_msgs
)

catkin_package(
  CATKIN_DEPENDS std_msgs message_runtime
)