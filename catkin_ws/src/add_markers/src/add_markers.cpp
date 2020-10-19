/*
 * Based on the Willow Garage, Inc basic_shapes node.
 * Cristina Villegas 19.10.2020
 */

#include <ros/ros.h>
#include "manage_markers.h"

int main( int argc, char** argv )
{
  ros::init(argc, argv, "add_markers");
  ros::NodeHandle n;
  ros::Rate r(1);
  ros::Publisher marker_pub = n.advertise<visualization_msgs::Marker>("visualization_marker", 1);

  while (ros::ok())
  {
    while (marker_pub.getNumSubscribers() < 1)
    {
      if (!ros::ok())
      {
        return 0;
      }
      ROS_WARN_ONCE("Please create a subscriber to the marker");
      sleep(1);
    }

    auto marker = CreateMarker();
    SetMarkerPosition(marker, -2.0, -6.0, 1.0);
    marker_pub.publish(marker);
    sleep(5);
    
    RemoveMarker(marker);
    marker_pub.publish(marker);
    sleep(5);

    AddMarker(marker);
    SetMarkerPosition(marker, -3.5, -7.5, 1.0);
    marker_pub.publish(marker);
    sleep(5);

    r.sleep();
  }
}