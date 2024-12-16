#include "my_first_cpp_package/my_first_service_client.h"

MyFirstServiceClient::MyFirstServiceClient()
: Node("my_first_service_client")
{
    client_ = this->create_client<my_first_msgs::srv::ComputerIDCheck>("computer_id_check");
    send_request();
}

void MyFirstServiceClient::send_request()
{
    auto request = std::make_shared<my_first_msgs::srv::ComputerIDCheck::Request>();
    request->computer_name = "vitis22";
    request->domain_id = 42;

    auto result = client_->async_send_request(request);
    if (rclcpp::spin_until_future_complete(this->get_node_base_interface(), result) == rclcpp::FutureReturnCode::SUCCESS)
    {   

        RCLCPP_INFO(this->get_logger(), "Computer name check: %s,\n Domain ID check: %s",
            result.get()->check_name ? "success" : "failure",
            result.get()->check_id ? "success" : "failure"); 
    }
    else
    {
        RCLCPP_ERROR(this->get_logger(), "Failed to call service computer_id_check");
    }
}

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<MyFirstServiceClient>());
    rclcpp::shutdown();
    return 0;
}