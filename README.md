# udacity_home_service_robot

### Launch script
[home_service.sh](./src/scripts/home_service.sh) launches the nodes and
 tools necessary to place our
 robot described in the [my_robot](./src/my_robot) package 
 inside a map, a service providing information about the map, and a node
  giving the robot simultaneously mapping and localization capabilities using a laser sensor and pose information.

### Mapping and Localization
The [turtlebot_gazebo package](./src/turtlebot_simulator/turtlebot_gazebo) there is a launch file that
 starts gazebo with the apartment world and places the robot inside it. 
 Another launch file in the same package is used to launch the
  map_server
  node inside the [map_server](./src/slam_gmapping)
  package, that offers the map data as a service. 
  The slam_gmapping node inside the slam_gmapping(./src/slam_gmapping) package is also started. 
  This node is a wrapper around gmapping which provides laser-based  SLAM
   capabilities to
   the robot. It  creates a 2-D occupancy grid map from laser and pose data collected by a mobile robot.

### Pick and delivery commands
In the package [pick_objects](./src/pick_objects) the pick_objects node sends
 the commands to the
 robot. First the robot has to pick the object, so it has to go to the
  specified position inside the map. After reaching the position, the node
   sends another location where the robot has to deliver the object. 

### Visualization

The [add_markers](./src/add_markers) package contains a add_markers node that
 receives information
 about the commands sent to the robot by pick_objects node via the /pick_objects
  message. It sends a marker representing the object in the initial position
  , removes
   the marker
   once the robot reaches and picks the object, and sends a marker again
    when the robot reaches the delivery location. The marker can be
     visualized with rviz. 
     
The rviz tool for visualization is also started. it
      shows the robot and the
 map, as well as the object marker to be picked and delivered as a marker
 . The launch file used with a rviz configuration with all needed is in the
  [home_service_rviz](./src/home_service_rviz) package. 




