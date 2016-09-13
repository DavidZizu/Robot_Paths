#include "square_path_odom.h"

int main(int argc, char ** argv) {
	ros::init(argc, argv, "draw_square");
	Square draw_square;

	//ros::Rate rate(10);

	draw_square.startMotion();
	ROS_INFO_STREAM("Done");
}
