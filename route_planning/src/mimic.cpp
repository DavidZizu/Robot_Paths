#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include <nav_msgs/Odometry.h>
#include <iostream>

class Mimic {
public:
	Mimic();
private:
	void poseCallback(const nav_msgs::OdometryConstPtr & odom);
	//void cmd_velCallback(const geometry_msgs::Twist & odom);

	ros::Publisher vel_pub;
	ros::Subscriber pose_sub;
};

Mimic::Mimic() {
	ros::NodeHandle input_nh("input");
	ros::NodeHandle output_nh("output");
	vel_pub = output_nh.advertise<geometry_msgs::Twist>("mobile_base/commands/velocity", 100);
	pose_sub = input_nh.subscribe<nav_msgs::Odometry>("odom", 1, &Mimic::poseCallback, this);
	//pose_sub = input_nh.subscribe<geometry_msgs::Twist>("turtlebot_1/mobile_base/commands/velocity", 1, &Mimic::cmd_velCallback);
}
/*
void Mimic::cmd_velCallback(const geometry_msgs::Twist & odom) {
	geometry_msgs::Twist vel;
	vel.linear = odom.linear; 
	vel.angular = odom.angular;

	vel_pub.publish(vel);
}
*/
void Mimic::poseCallback(const nav_msgs::OdometryConstPtr & odom) {
	geometry_msgs::Twist vel;
	vel.linear = odom->twist.twist.linear; 
	vel.angular = odom->twist.twist.angular;

	vel_pub.publish(vel);
}

int main(int argc, char **argv) {

	ros::init(argc, argv, "mimic");
	Mimic mimic;
	
	ros::spin();
}

	
