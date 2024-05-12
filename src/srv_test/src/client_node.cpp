#include "rclcpp/rclcpp.hpp"
#include "rclcpp/executors/multi_threaded_executor.hpp"
#include "custom_interfaces/srv/check_name.hpp"
#include "custom_interfaces/msg/status.hpp"
#include <mutex>

using namespace std::chrono_literals;
using CheckName = custom_interfaces::srv::CheckName;
using Status = custom_interfaces::msg::Status;

class ClientNode : public rclcpp::Node
{
public:
    ClientNode(int instance) : Node("UV" + std::to_string(instance)), service_ready_(false)
    {
        std::string topic_name = "UV" + std::to_string(instance) + "_status";
        client_ = this->create_client<CheckName>("check_name_service");
        publisher_ = this->create_publisher<Status>(topic_name, 10);
        subscription_ = this->create_subscription<Status>(
            topic_name, 10,
            std::bind(&ClientNode::uav_status_callback, this, std::placeholders::_1));

        timer_ = this->create_wall_timer(
            500ms, [this]() { this->try_send_request(); });
        
        publish_status_timer_ = this->create_wall_timer(
            1s, [this]() { this->publish_status(); });
    }

private:
    rclcpp::Client<CheckName>::SharedPtr client_;
    rclcpp::Publisher<Status>::SharedPtr publisher_;
    rclcpp::Subscription<Status>::SharedPtr subscription_;
    rclcpp::TimerBase::SharedPtr timer_;
    rclcpp::TimerBase::SharedPtr publish_status_timer_;
    bool service_ready_;
    std::mutex mutex_;

    void try_send_request()
    {
        std::lock_guard<std::mutex> lock(mutex_);
        if (!client_->service_is_ready()) {
            RCLCPP_INFO(this->get_logger(), "[%s] Waiting for the service to be available or response...", this->get_name());
            return;
        }

        if (!service_ready_) {
            auto request = std::make_shared<CheckName::Request>();
            request->name = this->get_name();
            client_->async_send_request(request,
                [this](rclcpp::Client<CheckName>::SharedFuture future) {
                    this->handle_service_response(future);
                });
            service_ready_ = true; // Prevent further requests until the service becomes unavailable and available again
        }
    }

    void publish_status()
    {
        auto message = Status();
        message.num = 42; // Example value
        publisher_->publish(message);
    }

    void handle_service_response(rclcpp::Client<CheckName>::SharedFuture future)
    {
        auto response = future.get();
        RCLCPP_INFO(this->get_logger(), "[%s] Response from server: %s", this->get_name(), response->response.c_str());
    }

    void uav_status_callback(const Status::SharedPtr msg)
    {
        RCLCPP_INFO(this->get_logger(), "[%s] Received UAV status: %ld", this->get_name(), msg->num);
    }
};

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <instance>" << std::endl;
        return 1;
    }
    
    int instance = std::atoi(argv[1]);
    auto node = std::make_shared<ClientNode>(instance);
    rclcpp::executors::MultiThreadedExecutor executor;
    executor.add_node(node);
    executor.spin();
    rclcpp::shutdown();
    return 0;
}