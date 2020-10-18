#!/bin/sh

export ROBOT_INITIAL_POSE="-x 4.5 -y -6.5 -Y 0"

xterm -e "source /home/workspace/udacity_home_service_robot/catkin_ws/devel/setup.bash; roslaunch turtlebot_gazebo turtlebot_world.launch world_file:=/home/workspace/udacity_home_service_robot/catkin_ws/src/my_robot/worlds/apartment" &

sleep 15

xterm -e "source /home/workspace/udacity_home_service_robot/catkin_ws/devel/setup.bash; roslaunch turtlebot_gazebo amcl_demo.launch map_file:=/home/workspace/udacity_home_service_robot/catkin_ws/src/my_robot/maps/apartment.yaml initial_pose_x:=-6.5 initial_pose_y:=-4.5 initial_pose_a:=-1.57" &

sleep 2

xterm -e "source /home/workspace/udacity_home_service_robot/catkin_ws/devel/setup.bash; rosrun pick_objects pick_objects" &

sleep 1

xterm -e "source /home/workspace/udacity_home_service_robot/catkin_ws/devel/setup.bash; roslaunch turtlebot_rviz_launchers view_navigation.launch" &
