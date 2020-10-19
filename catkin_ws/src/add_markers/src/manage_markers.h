//
// Created by mcbot on 19.10.20.
//

#ifndef UDACITY_HOME_SERVICE_ROBOT_MANAGE_MARKERS_H
#define UDACITY_HOME_SERVICE_ROBOT_MANAGE_MARKERS_H

#include <visualization_msgs/Marker.h>

visualization_msgs::Marker CreateMarker(){
  visualization_msgs::Marker marker;
  uint32_t shape_cube = visualization_msgs::Marker::CUBE;

  marker.header.frame_id = "/map";
  marker.header.stamp = ros::Time::now();

  // Set the namespace and id for this marker.  This serves to create a unique ID
  // Any marker sent with the same namespace and id will overwrite the old one

  marker.ns = "add_markers";
  marker.id = 0;

  // Set the marker type.  Initially this is CUBE, and cycles between that and SPHERE, ARROW, and CYLINDER
  marker.type = shape_cube;

  // Set the marker action.  Options are ADD, DELETE, and new in ROS Indigo: 3 (DELETEALL)
  marker.action = visualization_msgs::Marker::ADD;


  // Set the scale of the marker -- 1x1x1 here means 1m on a side
  marker.scale.x = 1.0;
  marker.scale.y = 1.0;
  marker.scale.z = 1.0;

  // Set the color -- be sure to set alpha to something non-zero!
  marker.color.r = 0.0f;
  marker.color.g = 1.0f;
  marker.color.b = 0.0f;
  marker.color.a = 1.0;

  marker.lifetime = ros::Duration();
  return marker;
}

void SetMarkerPosition(visualization_msgs::Marker& marker, float x, float y,
                       float
                       orientation){
  marker.pose.position.x = x;
  marker.pose.position.y = y;
  marker.pose.position.z = 0;
  marker.pose.orientation.x = 0.0;
  marker.pose.orientation.y = 0.0;
  marker.pose.orientation.z = 0.0;
  marker.pose.orientation.w = orientation;
}

void RemoveMarker(visualization_msgs::Marker& marker){
  marker.action = visualization_msgs::Marker::DELETE;
}

void AddMarker(visualization_msgs::Marker& marker){
  marker.action = visualization_msgs::Marker::ADD;
}

#endif // UDACITY_HOME_SERVICE_ROBOT_MANAGE_MARKERS_H
