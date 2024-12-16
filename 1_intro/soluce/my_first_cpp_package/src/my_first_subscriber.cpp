#include "my_first_cpp_package/my_first_subscriber.h"

MyFirstSubscriber::MyFirstSubscriber()
: Node("my_first_subscriber")
{
    subscription_ = this->create_subscription<my_first_msgs::msg::ComputerID>(
        "my_first_topic", 10, std::bind(&MyFirstSubscriber::topic_callback, this, std::placeholders::_1));
}

void MyFirstSubscriber::topic_callback(const my_first_msgs::msg::ComputerID::SharedPtr msg)
{
    RCLCPP_INFO(this->get_logger(), "Message received!\nYour computer name is: '%s' \nYour domain_id is: '%d'", msg->computer_name.c_str(), msg->domain_id);
}

int main(int argc, char * argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<MyFirstSubscriber>());
    rclcpp::shutdown();
    return 0;
}