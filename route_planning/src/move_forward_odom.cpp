#include "move_forward_by.h"

int main(int argc, char ** argv) {
	ros::init(argc, argv, "move_forward_odom");
	Move move;

	move.startMotion();
	ROS_INFO_STREAM("Done");
}
