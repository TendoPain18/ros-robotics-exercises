#include "ros/ros.h"
#include "std_msgs/String.h"
#include <sstream>

int main(int argc, char **argv) {
    // Initialize the ROS node
    ros::init(argc, argv, "talker");

    // Create a NodeHandle object
    ros::NodeHandle nh;

    // Create a Publisher object that publishes to the "chatter" topic
    ros::Publisher chatter_pub = nh.advertise<std_msgs::String>("chatter", 1000);

    // Set the publishing rate (10 messages per second)
    ros::Rate loop_rate(10);

    int count = 0;
    while (ros::ok()) {
        // Create a message object
        std_msgs::String msg;

        // Set the message data
        std::stringstream ss;
        ss << "Hello World " << count;
        msg.data = ss.str();

        // Publish the message
        ROS_INFO("Publishing: %s", msg.data.c_str());
        chatter_pub.publish(msg);

        // Spin once and sleep to maintain the publishing rate
        ros::spinOnce();
        loop_rate.sleep();
        ++count;
    }

    return 0;
}