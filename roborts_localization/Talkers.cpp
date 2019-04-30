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
ros::Publisher chatter_pub;
ros::Subscriber robort_sub_;

void robort_pose_callback(const geometry_msgs::PoseStamped::ConstPtr& robort_pose)
{
	_pose = *robort_pose;
	chatter_pub.publish(_pose);
}

int main(int argc, char** argv)
{
	ros::init(argc, argv, "Talkers");
	ros::NodeHandle n;

	robort_sub_= n.subscribe<geometry_msgs::PoseStamped>("amcl_pose", 2, robort_pose_callback);

	chatter_pub = n.advertise<geometry_msgs::PoseStamped>("chatter", 2);
//	chatter_pub = n.advertise<std_msgs::String>("chatter", 2);

	/*while(ros::ok())
       {
	std_msgs::String msg;
	std::stringstream ss;
	ss<<"Hello";
	msg.data=ss.str();
	ROS_INFO("I heard {%s}", msg.data.c_str());
	chatter_pub.publish(msg);
       }*/

	ros::spin();
	return 0;
}
