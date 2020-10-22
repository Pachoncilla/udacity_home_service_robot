/*
 * Based on the Willow Garage, Inc basic_shapes node.
 * Cristina Villegas 19.10.2020
 */

#include <ros/ros.h>
#include "manage_markers.h"
#include <pick_objects/pick_objects.h>

visualization_msgs::Marker marker;
ros::Publisher marker_pub;

void pick_callback(const pick_objects::pick_objects& msg){

  while (marker_pub.getNumSubscribers() < 1)
  {
    ROS_WARN_ONCE("Please create a subscriber to the marker");
    sleep(1);
  }

  ROS_INFO("pick_callback");
  if (!ros::ok()) return;
  if (msg.action == pick_objects::pick_objects::PICKING_OBJECT ||
      msg.action == pick_objects::pick_objects::OBJECT_DELIVERED) {
    AddMarker(marker);
    SetMarkerPosition(marker, msg.x, msg.y, msg.orientation);
    marker_pub.publish(marker);
    return;
  }
  if (msg.action == pick_objects::pick_objects::DELIVERING_OBJECT) {
    RemoveMarker(marker);
    marker_pub.publish(marker);
    return;
  }

}
int main( int argc, char** argv )
{
  ros::init(argc, argv, "add_markers");
  ros::NodeHandle n;
  
  marker_pub = n.advertise<visualization_msgs::Marker>("visualization_marker", 1);

  ros::Subscriber pick_objects_sub = n.subscribe("/pick_objects", 1000,
                                                 pick_callback);

  marker = CreateMarker();
  ros::spin();
  return 0;                                          
}