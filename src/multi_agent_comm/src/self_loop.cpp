#include "rclcpp/rclcpp.hpp"
#include "multi_agent_comm/msg/agent_message.hpp"
#include <random>
#include <iomanip> 
#include <cstring>
#include <unistd.h>
#include <std_msgs/msg/int8.hpp>
using std::placeholders::_1;

class AgentNode : public rclcpp::Node {
public:
    AgentNode(int agent_id)
    : Node("agent_" + std::to_string(agent_id)), agent_id_(agent_id) {
        auto my_callback_group = create_callback_group(rclcpp::CallbackGroupType::MutuallyExclusive);

        count = 0;

        // 퍼블리셔와 서브스크라이버에 동일한 콜백 그룹 적용
        rclcpp::PublisherOptions pub_options;
        pub_options.callback_group = my_callback_group;
        publisher_ = this->create_publisher<std_msgs::msg::Int8>(
            "communication_test", 10, pub_options);

        rclcpp::SubscriptionOptions sub_options;
        sub_options.callback_group = my_callback_group;
        subscriber_ = this->create_subscription<std_msgs::msg::Int8>(
            "communication_test", rclcpp::SensorDataQoS(), std::bind(&AgentNode::topic_callback, this, _1), sub_options);

        //auto timer_callback = [this]() -> void {
        //     RCLCPP_INFO(this->get_logger(), "Counting: '%d'", count++);
        //};

        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_real_distribution<> dis(1, 1);  // 1~3Hz
        
        //timer_ = this->create_wall_timer(std::chrono::milliseconds(500), timer_callback);
    }

private:
    void topic_callback(const std_msgs::msg::Int8::SharedPtr msg) const {
        // const_cast를 사용하여 Clock 객체의 const 제약을 우회
        auto clock = const_cast<rclcpp::Clock*>(this->get_clock().get());
        auto pre_sleep_now = clock->now();  // Correctly get the current time

        std::time_t raw_pre_sleep_time = pre_sleep_now.seconds();
        auto milliseconds_pre_sleep = pre_sleep_now.nanoseconds() % 1000000000 / 1000000;
        
        struct tm * dt_pre_sleep;
        char formatted_pre_sleep_time[40];
        dt_pre_sleep = std::localtime(&raw_pre_sleep_time);
        std::strftime(formatted_pre_sleep_time, sizeof(formatted_pre_sleep_time), "%H:%M:%S", dt_pre_sleep);
        std::sprintf(formatted_pre_sleep_time + std::strlen(formatted_pre_sleep_time), ".%03lu", milliseconds_pre_sleep);

        std::this_thread::sleep_for(std::chrono::milliseconds(2000));  // Sleep

        RCLCPP_INFO(this->get_logger(), "Heard: '%d at %s'", msg->data, formatted_pre_sleep_time);
        publisher_->publish(*msg);
    }

    rclcpp::Publisher<std_msgs::msg::Int8>::SharedPtr publisher_;
    rclcpp::Subscription<std_msgs::msg::Int8>::SharedPtr subscriber_;
    rclcpp::TimerBase::SharedPtr timer_;
    int agent_id_;
    int count;

};

int main(int argc, char **argv) {
    rclcpp::init(argc, argv);
    if (argc != 2) {
        RCLCPP_ERROR(rclcpp::get_logger("rclcpp"), "usage: agent_node <agent_id>");
        return 1;
    }
    int agent_id = std::stoi(argv[1]);
    auto node = std::make_shared<AgentNode>(agent_id);
    rclcpp::executors::MultiThreadedExecutor executor;
    executor.add_node(node);
    executor.spin();
    rclcpp::shutdown();
    return 0;
}