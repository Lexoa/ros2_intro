#include "my_first_cpp_package/my_first_publisher.h"

using namespace std::chrono_literals;

MyFirstPublisher::MyFirstPublisher()
: Node("my_first_publisher")
{
    publisher_ = this->create_publisher<my_first_msgs::msg::ComputerID>("my_first_topic", 10);
    timer_ = this->create_wall_timer(
        500ms, std::bind(&MyFirstPublisher::timer_callback, this));
}

void MyFirstPublisher::timer_callback()
{
    auto message = my_first_msgs::msg::ComputerID();
    message.computer_name = "vitis22";
    message.domain_id = 42;
    RCLCPP_INFO(this->get_logger(), "Publishing: '%s' and '%d'", message.computer_name.c_str(), message.domain_id);
    publisher_->publish(message);
}

int main(int argc, char * argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<MyFirstPublisher>());
    rclcpp::shutdown();
    return 0;
}