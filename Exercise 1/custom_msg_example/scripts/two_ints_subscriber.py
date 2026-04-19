#!/usr/bin/env python
import rospy
from custom_msg_example.msg import TwoInts

def callback(msg):
    # This function is called whenever a new message is received
    sum_result = msg.a + msg.b
    rospy.loginfo("Received: a = %d, b = %d, Sum = %d", msg.a, msg.b, sum_result)

def subscriber():
    # Initialize the ROS node
    rospy.init_node('two_ints_subscriber', anonymous=True)

    # Create a subscriber object that listens to the 'two_ints_topic' topic
    rospy.Subscriber('sum', TwoInts, callback)

    # Keep the node running
    rospy.spin()

if __name__ == '__main__':
    subscriber()