#ifndef MY_FIRST_CPP_PACKAGE__MY_FIRST_SERVICE_SERVER_H_
#define MY_FIRST_CPP_PACKAGE__MY_FIRST_SERVICE_SERVER_H_

#include "rclcpp/rclcpp.hpp"
#include "my_first_msgs/srv/computer_id_check.hpp"

class MyFirstServiceServer : public rclcpp::Node
{
public:
    MyFirstServiceServer();

private:
    void handle_request(
        const std::shared_ptr<my_first_msgs::srv::ComputerIDCheck::Request> request,
        std::shared_ptr<my_first_msgs::srv::ComputerIDCheck::Response> response);
    rclcpp::Service<my_first_msgs::srv::ComputerIDCheck>::SharedPtr server_;
};

#endif  // MY_FIRST_CPP_PACKAGE__MY_FIRST_SERVICE_SERVER_H_
