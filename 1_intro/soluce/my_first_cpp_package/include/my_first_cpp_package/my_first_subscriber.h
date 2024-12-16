#ifndef MY_FIRST_CPP_PACKAGE__MY_FIRST_SUBSCRIBER_H_
#define MY_FIRST_CPP_PACKAGE__MY_FIRST_SUBSCRIBER_H_

#include "rclcpp/rclcpp.hpp"
#include "my_first_msgs/msg/computer_id.hpp"

class MyFirstSubscriber : public rclcpp::Node
{
public:
    MyFirstSubscriber();

private:
    void topic_callback(const my_first_msgs::msg::ComputerID::SharedPtr msg);
    rclcpp::Subscription<my_first_msgs::msg::ComputerID>::SharedPtr subscription_;
};

#endif  // MY_FIRST_CPP_PACKAGE__MY_FIRST_SUBSCRIBER_H_