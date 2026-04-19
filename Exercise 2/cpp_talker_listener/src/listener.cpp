#include "ros/ros.h"
#include "std_msgs/String.h"

void chatterCallback(const std_msgs::String::ConstPtr& msg) {
    // This function is called whenever a new message is received
    ROS_INFO("I heard: %s", msg->data.c_str());
}

int main(int argc, char **argv) {
    // Initialize the ROS node
    ros::init(argc, argv, "listener");

    // Create a NodeHandle object
    ros::NodeHandle nh;

    // Create a Subscriber object that listens to the "chatter" topic
    ros::Subscriber sub = nh.subscribe("chatter", 1000, chatterCallback);

    // Keep the node running
    ros::spin();

    return 0;
}