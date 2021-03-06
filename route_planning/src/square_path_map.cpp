#include <ros/ros.h>
#include <move_base_msgs/MoveBaseAction.h>
#include <actionlib/client/simple_action_client.h>

typedef actionlib::SimpleActionClient<move_base_msgs::MoveBaseAction> MoveBaseClient;

int main(int argc, char **argv) {
	ros::init(argc, argv, "draw_square");

	//tell the action client that we want to spin a thread by default
	MoveBaseClient ac("move_base", true);

  	//wait for the action server to come up
  	while(!ac.waitForServer(ros::Duration(5.0))){
    		ROS_INFO("Waiting for the move_base action server to come up");
  	}

  	move_base_msgs::MoveBaseGoal goal;

	

}
