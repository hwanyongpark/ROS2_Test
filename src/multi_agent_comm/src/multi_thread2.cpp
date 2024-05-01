#include "rclcpp/rclcpp.hpp"
#include "multi_agent_comm/msg/agent_message.hpp"
#include <random>
#include <iomanip> 
#include <cstring>
#include <unistd.h>
using std::placeholders::_1;

class AgentNode : public rclcpp::Node {
public:
    AgentNode(int agent_id)
    : Node("agent_" + std::to_string(agent_id)), agent_id_(agent_id) {
        auto my_callback_group = create_callback_group(rclcpp::CallbackGroupType::MutuallyExclusive);

        // 퍼블리셔와 서브스크라이버에 동일한 콜백 그룹 적용
        rclcpp::PublisherOptions pub_options;
        pub_options.callback_group = my_callback_group;
        publisher_ = this->create_publisher<multi_agent_comm::msg::AgentMessage>(
            "communication_test", 10, pub_options);

        rclcpp::SubscriptionOptions sub_options;
        sub_options.callback_group = my_callback_group;
        subscriber_ = this->create_subscription<multi_agent_comm::msg::AgentMessage>(
            "communication_test", rclcpp::SensorDataQoS(), std::bind(&AgentNode::topic_callback, this, _1), sub_options);

        auto timer_callback = [this]() -> void {
            auto message = multi_agent_comm::msg::AgentMessage();
            message.agent_id = this->agent_id_;
            message.status = "publishing done";
            message.timestamp = this->get_clock()->now();

            // 시간을 HH:MM:SS 형식으로 포맷팅
            std::time_t raw_time = message.timestamp.sec;
            auto milliseconds = message.timestamp.nanosec / 1000000;
            struct tm * dt;
            char formatted_time[40];
            dt = std::localtime(&raw_time);
            std::strftime(formatted_time, sizeof(formatted_time), "%H:%M:%S", dt);
            std::sprintf(formatted_time + strlen(formatted_time), ".%03u", milliseconds);
            message.formatted_time = formatted_time;

            RCLCPP_INFO(this->get_logger(), "Publishing: '%d, %s, %s'", message.agent_id, message.status.c_str(), formatted_time);
            publisher_->publish(message);
        };

        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_real_distribution<> dis(1, 1);  // 1~3Hz
        
        timer_ = this->create_wall_timer(std::chrono::milliseconds(500), timer_callback);
    }

private:
    void topic_callback(const multi_agent_comm::msg::AgentMessage::SharedPtr msg) const {
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

        auto post_sleep_now = clock->now();  // Get the time after sleep
        
        std::time_t raw_post_sleep_time = post_sleep_now.seconds();
        auto milliseconds_post_sleep = post_sleep_now.nanoseconds() % 1000000000 / 1000000;
        
        struct tm * dt_post_sleep;
        char formatted_post_sleep_time[40];
        dt_post_sleep = std::localtime(&raw_post_sleep_time);
        std::strftime(formatted_post_sleep_time, sizeof(formatted_post_sleep_time), "%H:%M:%S", dt_post_sleep);
        std::sprintf(formatted_post_sleep_time + std::strlen(formatted_post_sleep_time), ".%03lu", milliseconds_post_sleep);

        RCLCPP_INFO(this->get_logger(), "Heard: '%d, %s, Message Time: %s, Received Time Pre-Sleep: %s, Received Time Post-Sleep: %s'", 
                    msg->agent_id, msg->status.c_str(), msg->formatted_time.c_str(), formatted_pre_sleep_time, formatted_post_sleep_time);
    }

    rclcpp::Publisher<multi_agent_comm::msg::AgentMessage>::SharedPtr publisher_;
    rclcpp::Subscription<multi_agent_comm::msg::AgentMessage>::SharedPtr subscriber_;
    rclcpp::TimerBase::SharedPtr timer_;
    int agent_id_;
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