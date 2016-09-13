#include "square_path_odom.h"
#include "circle_path_time.h"
#include "move_forward_by.h"

int main(int argc, char ** argv) {
	ros::init(argc, argv, "motion");

	Square draw_square;
	Circle draw_circle;
	Move move_forward;

	ROS_INFO_STREAM("Starting SQUARE motion");
	draw_square.startMotion();
	ROS_INFO_STREAM("SQUARE - Done");

	ROS_INFO_STREAM("Starting CIRCULAR motion");
	draw_circle.startMotion();
	ROS_INFO_STREAM("CIRCLE - Done");

	ROS_INFO_STREAM("Starting FORWARD move");
	move_forward.startMotion();
	ROS_INFO_STREAM("FORWARD - Done");

	ROS_INFO_STREAM("Overall - Done");
}
