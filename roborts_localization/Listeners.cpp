#include <ros/ros.h>
#include <tf/tf.h>
#include <tf/transform_broadcaster.h>
#include <tf/transform_listener.h>
#include <tf/message_filter.h>
#include <message_filters/subscriber.h>
#include <sstream>
#include "std_msgs/String.h"

#include <sensor_msgs/LaserScan.h>
#include <geometry_msgs/PoseWithCovarianceStamped.h>
#include <geometry_msgs/PoseArray.h>
#include <nav_msgs/GetMap.h>

geometry_msgs::PoseStamped _pose;
ros::Publisher pose_pub;
ros::Subscriber chatter_sub_;

void robort_pose_callback(const geometry_msgs::PoseStamped::ConstPtr& robort_pose)
{
	_pose = *robort_pose;
	std::cout<<_pose.header;
	pose_pub.publish(_pose);
}

/*void robort_pose_callback(const std_msgs::String::ConstPtr& msg)
{
	ROS_INFO("I heard {%s}", msg->data.c_str());
	pose_pub.publish(msg);
}*/

int main(int argc, char** argv)
{
	ros::init(argc, argv, "listener");
	ros::NodeHandle m;

	chatter_sub_ = m.subscribe<geometry_msgs::PoseStamped>("chatter", 2, robort_pose_callback);

	pose_pub = m.advertise<geometry_msgs::PoseStamped>("recieve", 2);

//	chatter_sub_ = m.subscribe<std_msgs::String>("chatter", 2, robort_pose_callback);

//	pose_pub = m.advertise<std_msgs::String>("recieve", 2);

	ros::spin();
	return 0;
}
