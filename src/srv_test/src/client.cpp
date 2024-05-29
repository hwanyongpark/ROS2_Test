#include "rclcpp/rclcpp.hpp"
#include "rclcpp/executors/multi_threaded_executor.hpp"
#include "custom_interfaces/srv/check_name.hpp"
#include "custom_interfaces/msg/vehiclestate.hpp"
#include <mutex>

using namespace std::chrono_literals;
using CheckName = custom_interfaces::srv::CheckName;
using VehicleState = custom_interfaces::msg::Vehiclestate;

class ClientNode : public rclcpp::Node
{
public:
    
    ClientNode(int instance, double x, double y, double z) 
        : Node("UV" + std::to_string(instance)), 
          x_(x), y_(y), z_(z), service_ready_(false)
    {
        std::string topic_name = "UV" + std::to_string(instance) + "_vehicle_state";
        client_ = this->create_client<CheckName>("check_name_service");
        publisher_ = this->create_publisher<VehicleState>(topic_name, 10);

        timer_ = this->create_wall_timer(
            500ms, [this]() { this->try_send_request(); });
        
        publish_status_timer_ = this->create_wall_timer(
            1000ms, [this]() { this->publish_status(); });
    }

private:
    rclcpp::Client<CheckName>::SharedPtr client_;
    rclcpp::Publisher<VehicleState>::SharedPtr publisher_;
    rclcpp::TimerBase::SharedPtr timer_;
    rclcpp::TimerBase::SharedPtr publish_status_timer_;
    bool service_ready_;
    std::mutex mutex_;
    double x_, y_, z_;

    void try_send_request()
    {
        std::lock_guard<std::mutex> lock(mutex_);
        if (!client_->service_is_ready()) {
            RCLCPP_INFO(this->get_logger(), "[%s] Waiting for the service to be available...", this->get_name());
            service_ready_ = false;
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
        auto message = VehicleState();
        message.name = this->get_name();
        message.position_x = x_;
        message.position_y = y_;
        message.position_z = z_;
        publisher_->publish(message);

        // Update positions
        x_ += 1;
        y_ += 1;
        z_ += 1;
    }

    void handle_service_response(rclcpp::Client<CheckName>::SharedFuture future)
    {
        auto response = future.get();
        RCLCPP_INFO(this->get_logger(), "[%s] Response from server: %s", this->get_name(), response->response.c_str());
    }
};

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    
    if (argc < 5) {
        std::cerr << "Usage: " << argv[0] << " <instance> <initial_x> <initial_y> <initial_z>" << std::endl;
        return 1;
    }
    
    int instance = std::atoi(argv[1]);
    double initial_x = std::atof(argv[2]);
    double initial_y = std::atof(argv[3]);
    double initial_z = std::atof(argv[4]);
    
    auto node = std::make_shared<ClientNode>(instance, initial_x, initial_y, initial_z);
    rclcpp::executors::MultiThreadedExecutor executor;
    executor.add_node(node);
    executor.spin();
    rclcpp::shutdown();
    return 0;
}