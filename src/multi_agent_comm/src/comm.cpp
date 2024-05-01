#include "rclcpp/rclcpp.hpp"
#include "multi_agent_comm/msg/agent_message.hpp"
#include <random>
#include <iomanip> 
#include <cstring>

using std::placeholders::_1;

class AgentNode : public rclcpp::Node {
public:
    AgentNode(int agent_id)
    : Node("agent_" + std::to_string(agent_id)), agent_id_(agent_id) {
        publisher_ = this->create_publisher<multi_agent_comm::msg::AgentMessage>("communication_test", 10);
        subscriber_ = this->create_subscription<multi_agent_comm::msg::AgentMessage>(
            "communication_test", 10, std::bind(&AgentNode::topic_callback, this, _1));

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
        std::uniform_real_distribution<> dis(0.5, 0.5);  // 1~3Hz
        
        timer_ = this->create_wall_timer(std::chrono::milliseconds(int(1000 * dis(gen))), timer_callback);
    }

private:
    void topic_callback(const multi_agent_comm::msg::AgentMessage::SharedPtr msg) const {
        auto clock = const_cast<rclcpp::Clock*>(this->get_clock().get());
        auto now = clock->now(); // 메시지를 받은 시점의 현재 시간
        
        std::time_t raw_time_now = now.seconds();
        auto milliseconds_now = now.nanoseconds() % 1000000000 / 1000000; // 밀리초 계산
        
        struct tm * dt_now;
        char formatted_time_now[40];
        dt_now = std::localtime(&raw_time_now);
        std::strftime(formatted_time_now, sizeof(formatted_time_now), "%H:%M:%S", dt_now);
        std::sprintf(formatted_time_now + std::strlen(formatted_time_now), ".%03lu", milliseconds_now);

        RCLCPP_INFO(this->get_logger(), "Heard: '%d, %s, Message Time: %s, Received Time: %s'", msg->agent_id, msg->status.c_str(), msg->formatted_time.c_str(), formatted_time_now);
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
    rclcpp::spin(std::make_shared<AgentNode>(agent_id));
    rclcpp::shutdown();
    return 0;
}