#include <ros/ros.h>
#include <move_base_msgs/MoveBaseAction.h>
#include <actionlib/client/simple_action_client.h>
#include <pick_objects/pick_objects.h>

ros::Publisher marker_pub;
// Define a client for to send goal requests to the move_base server through a SimpleActionClient
typedef actionlib::SimpleActionClient<move_base_msgs::MoveBaseAction> MoveBaseClient;

move_base_msgs::MoveBaseGoal createGoal(float x, float y, float orientation){
  move_base_msgs::MoveBaseGoal goal;

  // set up the frame parameters
  goal.target_pose.header.frame_id = "map";
  goal.target_pose.header.stamp = ros::Time::now();

  // Define a position and orientation for the robot to reach
  goal.target_pose.pose.position.x = x;
  goal.target_pose.pose.position.y = y;
  goal.target_pose.pose.orientation.w = orientation;

  return goal;
}

void publishPikingObject(float x, float y, float orientation){
  pick_objects::pick_objects marker;
  marker.x = x;
  marker.y = y;
  marker.orientation = orientation;
  marker.action = pick_objects::pick_objects::PICKING_OBJECT;
  marker_pub.publish(marker);
}

void publishObjectDelivered(float x, float y, float orientation){
  pick_objects::pick_objects marker;
  marker.x = x;
  marker.y = y;
  marker.orientation = orientation;
  marker.action = pick_objects::pick_objects::OBJECT_DELIVERED;
  marker_pub.publish(marker);
}

void publishDeliveringObject(){
  pick_objects::pick_objects marker;
  marker.action = pick_objects::pick_objects::DELIVERING_OBJECT;
  marker_pub.publish(marker);
}

int main(int argc, char** argv){
  // Initialize the simple_navigation_goals node
  ros::init(argc, argv, "pick_objects");
  ros::NodeHandle n;
  marker_pub = n.advertise<pick_objects::pick_objects>
      ("/pick_objects", 1);


  //tell the action client that we want to spin a thread by default
  MoveBaseClient ac("move_base", true);
  ROS_INFO("ready to publish");
 publishPikingObject(-2.0, -6.0, 1.0);
  // Wait 5 sec for move_base action server to come up
  while(!ac.waitForServer(ros::Duration(5.0))){
    ROS_INFO("Waiting for the move_base action server to come up");
  }


  // Send the goal position and orientation for the robot to reach
  ROS_INFO("Sending goal");
  ac.sendGoal(createGoal(-2.0, -6.0, 1.0));
  publishPikingObject(-2.0, -6.0, 1.0);

  // Wait an infinite time for the results
  ac.waitForResult();

  // Check if the robot reached its goal
  if(ac.getState() == actionlib::SimpleClientGoalState::SUCCEEDED) {
    ROS_INFO("Hooray, the base moved to goal position and is picking up the item");
    publishDeliveringObject();
  } else {
    ROS_INFO("The base failed to move to the goal position for some reason");
    return 0;
  }

  sleep(5.0);

  ac.sendGoal(createGoal(-3.5, -7.5, 1.0));
  publishObjectDelivered(-3.5, -7.5, 1.0);
  ac.waitForResult();
  if(ac.getState() == actionlib::SimpleClientGoalState::SUCCEEDED) {
    ROS_INFO("Hooray, the base moved to the goal position to deliver the item");

  } else {
    ROS_INFO("The base failed to move to the delivery position for some reason");

  }

  return 0;

}