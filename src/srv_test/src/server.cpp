#include "rclcpp/rclcpp.hpp"
#include "custom_interfaces/srv/check_name.hpp"
#include "custom_interfaces/msg/vehiclestate.hpp" 
#include "std_msgs/msg/string.hpp"
#include <vector>
#include <string>
#include <sstream> 

using std::placeholders::_1;
using std::placeholders::_2;
using namespace std::chrono_literals;
using VehicleState = custom_interfaces::msg::Vehiclestate; 

class ServerNode : public rclcpp::Node
{
public:
    ServerNode() : Node("check_name_server")
    {
        service_ = this->create_service<custom_interfaces::srv::CheckName>(
            "check_name_service", std::bind(&ServerNode::handle_request, this, _1, _2));

        states_publisher_ = this->create_publisher<std_msgs::msg::String>("vehicle_states", 10);
      
        publish_states_timer_ = this->create_wall_timer(
            1s, [this]() { this->publish_vehicle_states(); });
    }

private:
    rclcpp::Service<custom_interfaces::srv::CheckName>::SharedPtr service_;
    std::vector<rclcpp::Subscription<VehicleState>::SharedPtr> subscribers_; // VehicleState 구독자 목록
    rclcpp::Publisher<std_msgs::msg::String>::SharedPtr states_publisher_;
    rclcpp::TimerBase::SharedPtr publish_states_timer_;
    std::unordered_map<std::string, VehicleState> vehicle_states_;

    void handle_request(
        const std::shared_ptr<custom_interfaces::srv::CheckName::Request> request,
        std::shared_ptr<custom_interfaces::srv::CheckName::Response> response)
    {
        RCLCPP_INFO(this->get_logger(), "Received request from %s", request->name.c_str());
        response->response = "check";
        RCLCPP_INFO(this->get_logger(), "Sending back response: %s", response->response.c_str());

        // 클라이언트의 위치 메시지를 수신할 새로운 구독자를 생성하고 벡터에 추가합니다.
        std::string topic_name = request->name + "_vehicle_state";
        auto subscriber = this->create_subscription<VehicleState>(
            topic_name, 10,
            [this, topic_name](const VehicleState::SharedPtr msg) {
                this->handle_vehicle_state(topic_name, msg);
            });
        subscribers_.push_back(subscriber);
    }

    void handle_vehicle_state(const std::string &topic_name, const VehicleState::SharedPtr msg)
    {
        RCLCPP_INFO(this->get_logger(), "Received vehicle state from %s: %s at Position X:%.2f, Y:%.2f, Z:%.2f", topic_name.c_str(), msg->name.c_str(), msg->position_x, msg->position_y, msg->position_z);
        vehicle_states_[msg->name] = *msg;
    }

    

    void publish_vehicle_states()
    {
        std_msgs::msg::String message;
        std::stringstream ss;
        for (const auto& [key, state] : vehicle_states_) {
            ss << "[" << state.name << ", " << state.position_x << ", " << state.position_y << ", " << state.position_z << "], ";
        }
        message.data = ss.str();
        states_publisher_->publish(message);
        RCLCPP_INFO(this->get_logger(), "Published vehicle states: %s", message.data.c_str());
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
