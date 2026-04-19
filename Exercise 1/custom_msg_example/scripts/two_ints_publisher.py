#!/usr/bin/env python
import rospy
from custom_msg_example.msg import TwoInts

def send_two_ints():
    # Initialize the ROS node
    rospy.init_node('send_two_ints_node', anonymous=True)

    # Create a publisher object that publishes to the 'two_ints_topic' topic
    pub = rospy.Publisher('sum', TwoInts, queue_size=10)

    # Set the publishing rate (1 message per second)
    rate = rospy.Rate(1)

    while not rospy.is_shutdown():
        # Create a custom message
        msg = TwoInts()
        msg.a = 5
        msg.b = 10

        # Publish the message
        rospy.loginfo("Publishing: a = %d, b = %d", msg.a, msg.b)
        pub.publish(msg)

        # Sleep to maintain the publishing rate
        rate.sleep()

if __name__ == '__main__':
    try:
        send_two_ints()
    except rospy.ROSInterruptException:
        pass