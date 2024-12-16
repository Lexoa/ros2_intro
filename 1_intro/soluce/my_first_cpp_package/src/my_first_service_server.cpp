#include "my_first_cpp_package/my_first_service_server.h"

MyFirstServiceServer::MyFirstServiceServer()
: Node("my_first_service_server")
{
    server_ = this->create_service<my_first_msgs::srv::ComputerIDCheck>("computer_id_check",
        std::bind(&MyFirstServiceServer::handle_request, this, std::placeholders::_1, std::placeholders::_2));
}

void MyFirstServiceServer::handle_request(
    const std::shared_ptr<my_first_msgs::srv::ComputerIDCheck::Request> request,
    std::shared_ptr<my_first_msgs::srv::ComputerIDCheck::Response> response)
{
    RCLCPP_INFO(this->get_logger(), "Received computer ID check request with ID: %d", request->domain_id);
    response->success = true;
    response->check_name = request->computer_name == "vitis22";
    response->check_id = request->domain_id == 42;
}

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<MyFirstServiceServer>());
    rclcpp::shutdown();
    return 0;
}