#include <ros/ros.h>

int main(int argc, char *argv[]){
	ros::init(argc, argv, "printer_node");
	ros::start();
	ROS_INFO_STREAM("Hello World, coming from a printer node.");
	ros::spin();
	return 0;
}