#include <ros/ros.h>
#include <tf/tf.h>
#include <tf/transform_broadcaster.h>
#include <tf/transform_listener.h>
#include <tf/message_filter.h>
#include <message_filters/subscriber.h>
#include <iostream>
#include <sstream>
#include "std_msgs/String.h"


#include <sensor_msgs/LaserScan.h>
#include <geometry_msgs/PoseWithCovarianceStamped.h>
#include <geometry_msgs/PoseArray.h>
#include <nav_msgs/GetMap.h>


geometry_msgs::PoseStamped _pose;
ros::Publisher pose_pub;
ros::Subscriber recieve_sub_;

void robort_pose_Rcallback(const geometry_msgs::PoseStamped::ConstPtr& robort_pose)
{
	_pose=*robort_pose;
	std::cout<<_pose.header;
	std::cout<<_pose.pose;
}


/*void robort_pose_Rcallback(const std_msgs::String::ConstPtr& robort_pose)
{
	ROS_INFO("I heard {%s}", robort_pose->data.c_str());
}*/


int main(int argc, char** argv)
{
	ros::init(argc, argv, "reciever");
	ros::NodeHandle l;

	recieve_sub_ = l.subscribe<geometry_msgs::PoseStamped>("recieve", 2, robort_pose_Rcallback);
 	
//	recieve_sub_ = l.subscribe<std_msgs::String>("recieve", 2, robort_pose_Rcallback);

	ros::spin();
	return 0;
}
