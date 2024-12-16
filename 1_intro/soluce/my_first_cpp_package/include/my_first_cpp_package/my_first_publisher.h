#ifndef MY_FIRST_CPP_PACKAGE__MY_FIRST_PUBLISHER_H_
#define MY_FIRST_CPP_PACKAGE__MY_FIRST_PUBLISHER_H_

#include "rclcpp/rclcpp.hpp"
#include "my_first_msgs/msg/computer_id.hpp"

class MyFirstPublisher : public rclcpp::Node
{
public:
    MyFirstPublisher();

private:
    void timer_callback();
    rclcpp::Publisher<my_first_msgs::msg::ComputerID>::SharedPtr publisher_;
    rclcpp::TimerBase::SharedPtr timer_;
};

#endif  // MY_FIRST_CPP_PACKAGE__MY_FIRST_PUBLISHER_H_