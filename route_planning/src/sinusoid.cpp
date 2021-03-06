#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include <math.h>

using namespace std;

int main (int argc, char **argv) {
	ros::init(argc, argv, "sinusoid");
	ros::NodeHandle nh;

	//robot name
	string robot_name;

	//get robot name
	ros::param::param<std::string>("robot_name", robot_name, "");

	ros::Publisher pub_vel = nh.advertise<geometry_msgs::Twist>(robot_name + "/mobile_base/commands/velocity", 1);
	
	geometry_msgs::Twist vel_to_pub;

	ROS_INFO_STREAM("Start Motion for" << robot_name);

	ros::Rate rate(10)
	ros::Time start = ros::Time::now();
	
	

	ROS_INFO_STREAM("Done " << robot_name); 

	return 0;
}
