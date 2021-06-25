################################################################################
# Set minimum required version of cmake, project name and compile options
################################################################################
cmake_minimum_required(VERSION 3.0.2)
project(open_manipulator_gazebo)

add_compile_options(-std=c++11)

################################################################################
# Find catkin packages and libraries for catkin and system dependencie
################################################################################
find_package(catkin REQUIRED
  COMPONENTS
    roscpp
    std_msgs
    gazebo_ros
    gazebo_ros_control
    controller_manager
    xacro
    urdf
)

find_package(gazebo REQUIRED)

################################################################################
# Setup for python modules and scripts
################################################################################

################################################################################
# Declare ROS messages, services and actions
################################################################################

################################################################################
# Declare ROS dynamic reconfigure parameters
################################################################################

################################################################################
# Declare catkin specific configuration to be passed to dependent projects
################################################################################
catkin_package(
  CATKIN_DEPENDS 
    roscpp
    std_msgs
    gazebo_ros
    gazebo_ros_control
    controller_manager
    xacro
    urdf
)

################################################################################
# Build
################################################################################
link_directories(${GAZEBO_LIBRARY_DIRS})

include_directories(
  ${catkin_INCLUDE_DIRS}
  ${GAZEBO_INCLUDE_DIRS}
)

add_executable(omx_gripper_sub_publisher src/omx_gripper_sub_publisher.cpp)
add_dependencies(omx_gripper_sub_publisher ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
target_link_libraries(omx_gripper_sub_publisher ${catkin_LIBRARIES})

################################################################################
# Install
################################################################################
install(TARGETS omx_gripper_sub_publisher
  RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)

install(DIRECTORY config launch worlds
  DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}
)

################################################################################
# Test
################################################################################
