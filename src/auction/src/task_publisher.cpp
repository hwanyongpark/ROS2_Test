#include "rclcpp/rclcpp.hpp"
#include "custom_interfaces/msg/tasklist.hpp"
#include "custom_interfaces/msg/task.hpp"
#include "geometry_msgs/msg/point.hpp"
#include <chrono>
#include <ctime>
#include <iomanip>
#include <sstream>

using namespace std;
using namespace custom_interfaces::msg;

class TaskPublisher : public rclcpp::Node {
public:
    TaskPublisher()
        : Node("task_publisher") {
        pub_task_list_ = this->create_publisher<Tasklist>("task_list", 10);

        // 퍼블리시할 작업 목록 생성
        create_task_list();

        // 1초마다 작업 목록을 퍼블리시하도록 타이머 설정
        timer_ = this->create_wall_timer(
            std::chrono::seconds(1), 
            std::bind(&TaskPublisher::publish_task_list, this));
    }

private:
    void create_task_list() {
        // 예시 작업 목록 생성
        Task task1;
        task1.task_name = "task1";
        task1.task_position.x = 0.0;
        task1.task_position.y = 2.0;
        task1.task_position.z = 0.0;
        task1.task_status = false;

        Task task2;
        task2.task_name = "task2";
        task2.task_position.x = 1.0;
        task2.task_position.y = 3.0;
        task2.task_position.z = 2.0;
        task2.task_status = false;

        Task task3;
        task3.task_name = "task3";
        task3.task_position.x = 2.0;
        task3.task_position.y = 2.0;
        task3.task_position.z = 2.0;
        task3.task_status = true;

        task_list_.tasks.push_back(task1);
        task_list_.tasks.push_back(task2);
        task_list_.tasks.push_back(task3);
    }

    void publish_task_list() {
        // 현재 시간을 가져와 타임스탬프 설정
        auto now = std::chrono::system_clock::now();
        std::time_t now_time = std::chrono::system_clock::to_time_t(now);
        auto now_ms = std::chrono::duration_cast<std::chrono::milliseconds>(now.time_since_epoch()) % 1000;

        std::tm now_tm = *std::localtime(&now_time);

        std::ostringstream oss;
        oss << std::setfill('0') << std::setw(2) << now_tm.tm_hour << '.'
            << std::setw(2) << now_tm.tm_min << '.'
            << std::setw(2) << now_tm.tm_sec << '.'
            << std::setw(3) << now_ms.count();

        task_list_.timestamp = oss.str();

        // 작업 목록을 퍼블리시
        pub_task_list_->publish(task_list_);
    }

    Tasklist task_list_;
    rclcpp::Publisher<Tasklist>::SharedPtr pub_task_list_;
    rclcpp::TimerBase::SharedPtr timer_;
};

int main(int argc, char *argv[]) {
    rclcpp::init(argc, argv);
    auto task_publisher_node = std::make_shared<TaskPublisher>();
    rclcpp::spin(task_publisher_node);
    rclcpp::shutdown();
    return 0;
}
