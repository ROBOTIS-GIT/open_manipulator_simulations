/*******************************************************************************
* Copyright 2018 ROBOTIS CO., LTD.
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*     http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*******************************************************************************/

/* Authors: Darby Lim, Hye-Jong KIM, Ryan Shim, Yong-Ho Na */

#include <ros/ros.h>
#include <std_msgs/Float64.h>

ros::Publisher gripper_joint_sub_pub;

void gripperJointCallback(const std_msgs::Float64::ConstPtr& msg)
{
  gripper_joint_sub_pub.publish(msg);
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "gripper_sub_publisher");
  ros::NodeHandle node_handle("");

  ros::Subscriber gripper_joint_sub = node_handle.subscribe("gripper_position/command", 10, gripperJointCallback);
  gripper_joint_sub_pub = node_handle.advertise<std_msgs::Float64>("gripper_sub_position/command", 10);

  ros::spin();
  return 0;
}
