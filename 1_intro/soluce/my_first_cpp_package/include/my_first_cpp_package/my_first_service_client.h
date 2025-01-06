#ifndef MY_FIRST_CPP_PACKAGE__MY_FIRST_SERVICE_CLIENT_H_
#define MY_FIRST_CPP_PACKAGE__MY_FIRST_SERVICE_CLIENT_H_

#include "rclcpp/rclcpp.hpp"
#include "my_first_msgs/srv/computer_id_check.hpp"

class MyFirstServiceClient : public rclcpp::Node
{
public:
    MyFirstServiceClient();

private:
    void send_request();
    rclcpp::Client<my_first_msgs::srv::ComputerIDCheck>::SharedPtr client_;
};

#endif  // MY_FIRST_CPP_PACKAGE__MY_FIRST_SERVICE_CLIENT_H_