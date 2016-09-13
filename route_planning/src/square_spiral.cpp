#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include <math.h>

using namespace std;

int main(int argc, char **argv) {
	ros::init(argc, argv, "square_spiral");
	ros::NodeHandle nh;

	//string robot_name;

	//get robot name
	//ros::param::param<std::string>("~robot_name", robot_name, "");

	ros::Publisher pub_vel = nh.advertise<geometry_msgs::Twist>("mobile_base/commands/velocity", 1);

	double time;
	ros::Duration temp;

	//message to publsh
	geometry_msgs::Twist vel_to_publish;
	vel_to_publish.linear.x = 0.7;

	ROS_INFO_STREAM("Start Motion");

	ros::Rate rate(32);

	ros::Time start = ros::Time::now();

	//some corrections
	double dd = 0.5;

	while (ros::ok() && ros::Time::now() - start < ros::Duration(14)) {

		pub_vel.publish(vel_to_publish);

		if (ros::Time::now() - start < ros::Duration(2 - dd)) {
			vel_to_publish.angular.z = 0;
			pub_vel.publish(vel_to_publish);
		}
		else if (ros::Time::now() - start > ros::Duration(2 - dd) && ros::Time::now() - start <= ros::Duration(2.5 - dd)) {
			temp = ros::Time::now() - start;
			time = temp.toSec();
			vel_to_publish.angular.z = M_PI * exp(-0.1 * (time - 2 - dd));
			pub_vel.publish(vel_to_publish);
		}
		else if (ros::Time::now() - start > ros::Duration(2.5 - dd) && ros::Time::now() - start <= ros::Duration(4 - dd)) {
			vel_to_publish.angular.z = 0;
			vel_to_publish.linear.x = 0.45;
			pub_vel.publish(vel_to_publish);
		}
		else if (ros::Time::now() - start > ros::Duration(4 - dd) && ros::Time::now() - start < ros::Duration(4.5 - dd)) {
			temp = ros::Time::now() - start;
			time = temp.toSec();
			vel_to_publish.angular.z = 1.1 * M_PI * exp(-0.1 * (time - 4 - dd));
			vel_to_publish.linear.x = 0.35;
			pub_vel.publish(vel_to_publish);
		}
		else if (ros::Time::now() - start >= ros::Duration(4.5 - dd) && ros::Time::now() - start < ros::Duration(6.9 - dd)) {
			vel_to_publish.angular.z = 0;
			vel_to_publish.linear.x = 0.2;
			pub_vel.publish(vel_to_publish);
		}
		else if (ros::Time::now() - start >= ros::Duration(6.9 - dd) && ros::Time::now() - start < ros::Duration(7.4 - dd)) {
			temp = ros::Time::now() - start;
			time = temp.toSec();
			vel_to_publish.angular.z = M_PI * exp(-0.1 * (time - 6.9 - dd));
			vel_to_publish.linear.x = 0.35;
			pub_vel.publish(vel_to_publish);
		}
		else if (ros::Time::now() - start >= ros::Duration(7.4 - dd) && ros::Time::now() - start < ros::Duration(8.5 - dd)) {
			vel_to_publish.angular.z = 0;
			vel_to_publish.linear.x = 0.5;
			pub_vel.publish(vel_to_publish);
		}
		else if (ros::Time::now() - start >= ros::Duration(8.5 - dd) && ros::Time::now() - start < ros::Duration(9 - dd)) {
			temp = ros::Time::now() - start;
			time = temp.toSec();
			vel_to_publish.angular.z = 0.9 * M_PI * exp(-0.1 * (time - 8.5 - dd));
			vel_to_publish.linear.x = 0.35;
			pub_vel.publish(vel_to_publish);
		}
		else if (ros::Time::now() - start >= ros::Duration(9 - dd) && ros::Time::now() - start < ros::Duration(10.8 - dd)) {
			vel_to_publish.angular.z = 0;
			vel_to_publish.linear.x = 0.2;
			pub_vel.publish(vel_to_publish);
		}
		else if (ros::Time::now() - start >= ros::Duration(10.8 - dd) && ros::Time::now() - start < ros::Duration(11.3 - dd)) {
			temp = ros::Time::now() - start;
			time = temp.toSec();
			vel_to_publish.angular.z = 0.9 * M_PI * exp(-0.1 * (time - 10.8 - dd));
			vel_to_publish.linear.x = 0.35;
			pub_vel.publish(vel_to_publish);
		}
		else if (ros::Time::now() - start >= ros::Duration(11.3 - dd) && ros::Time::now() - start < ros::Duration(12.1 - dd)) {
			vel_to_publish.angular.z = 0;
			pub_vel.publish(vel_to_publish);
		}
		else if (ros::Time::now() - start > ros::Duration(12.1 - dd) && ros::Time::now() - start < ros::Duration(12.5 - dd)) {
			temp = ros::Time::now() - start;
			time = temp.toSec();
			vel_to_publish.angular.z = 1.1 * M_PI * exp(-0.1 * (time - 12.1 - dd));
			pub_vel.publish(vel_to_publish);
		}
		else if (ros::Time::now() - start > ros::Duration(12.5)) {
			vel_to_publish.angular.z = 0;
			vel_to_publish.linear.x = 0.2;
			pub_vel.publish(vel_to_publish);
		}
		
		rate.sleep();
	}

	ROS_INFO_STREAM("Done");

/*
clear all
x=0;
y=0;
theta=0;
close all
plot(x,y,'x')
hold on
for t=0:0.1:14
    v=0.35
    if t<2
        w=0;
    elseif t>2 && t<=2.5
        w=1*pi*exp(-0.1*(t-2));
    elseif t>2.5 && t<=4
        w=0;
    elseif t>4 && t<4.5
        w=1.3*pi*exp(-0.1*(t-4));
    elseif t>=4.5 && t<6.9
        w=0;
    elseif t>=6.9 && t<7.4
       w=1*pi*exp(-0.1*(t-6.9));
    elseif t>=7.4 && t<8.5
        w=0;
    elseif t>=8.5 && t<9
        w=pi*exp(-0.1*(t-8.5));
    elseif t>=9 && t<10.8
        w=0;
    elseif t>=10.8 && t<11.3
        w=1*pi*exp(-0.1*(t-10.8));
    elseif  t>=11.3 && t<12.1
        w=0
    elseif t>12.1 && t<12.5
        w=1.3*pi*exp(-0.1*(t-12.1));
    else t>12.5
        w=0
    end
    x=x+v*cos(theta)*0.1;
    y=y+v*sin(theta)*0.1;
    theta=theta+w*0.1;
    plot(x,y,'*')
end
*/

	return 0;
}
