#include "rclcpp/rclcpp.hpp"
#include "custom_interfaces/srv/check_name.hpp"
#include "custom_interfaces/msg/status.hpp" 
#include "std_msgs/msg/string.hpp"
#include <vector>
#include <string>

using std::placeholders::_1;
using std::placeholders::_2;
using namespace std::chrono_literals;
using Status = custom_interfaces::msg::Status;

class ServerNode : public rclcpp::Node
{
public:
    ServerNode() : Node("check_name_server")
    {
        service_ = this->create_service<custom_interfaces::srv::CheckName>(
            "check_name_service", std::bind(&ServerNode::handle_request, this, _1, _2));

        subscriber_list_publisher_ = this->create_publisher<std_msgs::msg::String>("subscriber_list", 10);
        publish_list_timer_ = this->create_wall_timer(
            1s, [this]() { this->publish_subscriber_list(); });
    }

private:
    rclcpp::Service<custom_interfaces::srv::CheckName>::SharedPtr service_;
    std::vector<rclcpp::Subscription<Status>::SharedPtr> subscribers_;
    rclcpp::Publisher<std_msgs::msg::String>::SharedPtr subscriber_list_publisher_;
    rclcpp::TimerBase::SharedPtr publish_list_timer_;

    void handle_request(
        const std::shared_ptr<custom_interfaces::srv::CheckName::Request> request,
        std::shared_ptr<custom_interfaces::srv::CheckName::Response> response)
    {
        RCLCPP_INFO(this->get_logger(), "Received request from %s", request->name.c_str());
        response->response = "check";
        RCLCPP_INFO(this->get_logger(), "Sending back response: %s", response->response.c_str());

        // 클라이언트의 상태 메시지를 수신할 새로운 구독자를 생성하고 벡터에 추가합니다.
        std::string topic_name = request->name + "_status";
        auto subscriber = this->create_subscription<Status>(
            topic_name, 10,
            [this, topic_name](const Status::SharedPtr msg) {
                this->handle_status(topic_name, msg);
            });
        subscribers_.push_back(subscriber);
    }

    void handle_status(const std::string &topic_name, const Status::SharedPtr msg)
    {
        RCLCPP_INFO(this->get_logger(), "Received status from %s: %ld", topic_name.c_str(), msg->num);
    }

    void publish_subscriber_list()
    {
        std_msgs::msg::String message;
        message.data = "Subscribed topics: ";
        for (auto &subscriber : subscribers_) {
            message.data += std::string(subscriber->get_topic_name()) + ", ";
        }
        subscriber_list_publisher_->publish(message);
        RCLCPP_INFO(this->get_logger(), "Published subscriber list: %s", message.data.c_str());
    }
};

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<ServerNode>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}