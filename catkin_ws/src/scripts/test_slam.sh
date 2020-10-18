#!/bin/sh

xterm -e "source /home/workspace/udacity_home_service_robot/catkin_ws/devel/setup.bash; roslaunch turtlebot_gazebo turtlebot_world.launch" &

sleep 5

xterm -e "source /home/workspace/udacity_home_service_robot/catkin_ws/devel/setup.bash; roslaunch turtlebot_navigation gmapping_demo.launch" &

sleep 2

xterm -e "source /home/workspace/udacity_home_service_robot/catkin_ws/devel/setup.bash; roslaunch turtlebot_rviz_launchers view_navigation.launch" &

sleep 2

xterm -e "source /home/workspace/udacity_home_service_robot/catkin_ws/devel/setup.bash; roslaunch turtlebot_teleop keyboard_teleop.launch"
