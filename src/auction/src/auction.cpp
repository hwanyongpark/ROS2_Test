#include "rclcpp/rclcpp.hpp"
#include "custom_interfaces/msg/auctioninfo.hpp"
#include "custom_interfaces/msg/tasklist.hpp"
#include "custom_interfaces/msg/task.hpp"
#include "geometry_msgs/msg/point.hpp"
#include <vector>
#include <algorithm>
#include <tuple>
#include <string>
#include <cmath>
#include <unordered_set>

#define INF 1e9
#define EPSILON 0.5

using namespace std;
using namespace custom_interfaces::msg;

class Auction : public rclcpp::Node {
public:
    Auction(int agent_id, geometry_msgs::msg::Point agent_position)
        : Node("auction"), agent_id_(agent_id), agent_position_(agent_position) {
        pub_auction_ = this->create_publisher<Auctioninfo>("auction_info", 10);
        sub_auction_ = this->create_subscription<Auctioninfo>("auction_info", 10, std::bind(&Auction::auction_callback, this, std::placeholders::_1));
        sub_task_list_ = this->create_subscription<Tasklist>("task_list", 10, std::bind(&Auction::task_list_callback, this, std::placeholders::_1));
        sub_UV_State_ = this->create_subscription<UVState>("UV_State", 10, std::bind(&Auction::uv_state_callback, this, std::placeholders::_1));

        init_assignments();

        timer_ = this->create_wall_timer(
            std::chrono::milliseconds(100), 
            std::bind(&Auction::update, this));
    }

    void update() {
        int m = task_list_.size();
        if (price_.empty() || bidder_.empty() || path_ == -1 || isdone_.empty()) {
            init_assignments();
        }

        auto price_previous = price_;
        int alpha_ = 0;
        
        // 외부 업데이트 (상호작용)
        for (const auto& msg : received_msgs_) {
            int msg_size = msg->price.size();
            if (msg_size < m) {
                msg->price.resize(m, -INF);
                msg->bidder.resize(m, 0);
                msg->isdone.resize(m, false);
            }

            for (int i = 0; i < msg_size; ++i) {
                if (msg->price[i] > price_[i]) {
                    price_[i] = msg->price[i];
                    bidder_[i] = msg->bidder[i];
                }
                if (msg->isdone[i]) {
                    isdone_[i] = true;
                    bidder_[i] = msg->bidder[i];
                }
            }
            task_list_ = msg->task_list;  // task_list_를 msg->task_list로 업데이트
        }
        received_msgs_.clear();

        // 내부 업데이트 -> 작업 상태 업데이트
        for (int i = 0; i < m; ++i) {
            isdone_[i] = isdone_[i] || task_list_[i].task_status;
            if (isdone_[i]) {
                task_list_[i].task_status = true;
                price_[i] = 0;
                bidder_[i] = -1;  // 완료
                
            } else if (bidder_[i] == agent_id_ && alpha_ != i) {
                bidder_[i] = 0;
            }
        }
        if (all_of(isdone_.begin(), isdone_.end(), [](bool v) { return v; })) {
            alpha_ = -1;
        }

        // 모든 작업에 대한 가격 값을 계산하여 reward에 반영
        benefit = vector<double>(m,0.0);
        for (int j = 0; j < m; ++j){
            benefit[j] = reward();
        }

        net_value = vector<double>(m,0.0);
        for (int j = 0; j < m; ++j){
            net_value[j] = benefit[j] - price_[j];
        }
        // 최댓값의 반복자 찾기
        double v = std::max_element(net_value.begin(), net_value.end());

        // 최댓값의 인덱스 계산
        alpha_ = std::distance(net_value.begin(), v);
        
        net_value.erase(net_value.begin()+alpha_);
        w =  std::max_element(net_value.begin(), net_value.end());
        
        double gamma = v - w + EPSILON;

        // 단계 4: 할당 업데이트 조건 확인
        for (int j = 0; j < m; ++j) {
            if ((path_ == -1 && any_of(bidder_.begin(), bidder_.end(), [](int b){ return b == 0; })) || 
                (path_ != -1 && price_previous[path_] <= price_[path_] && bidder_[path_] != agent_id_) || 
                (path_ != -1 && bidder_[path_] != agent_id_ && price_[path_] < price_previous[path_])) {
                if (!isdone_[path_] && vi[j] != -INF) {
                    if (path_ != -1) {
                        bidder_[path_] = 0;  // release
                    }
                    path_ = j;
                    bidder_[path_] = agent_id_;
                    price_[path_] = price_previous[path_] + gamma[path_];
                } else {
                    path_ = -1;
                }
            }
        }

        // 단계 5: 정보 브로드캐스트
        broadcast();
    }

    void auction_callback(const Auctioninfo::SharedPtr msg) {
        received_msgs_.push_back(msg);
    }

    void task_list_callback(const Tasklist::SharedPtr msg) {
        task_list_ = msg->tasks;
    }

    void uv_state_callback(const UVState::SharedPtr msg) {
        uv_state_ = msg.battery;
    }

private:
    void init_assignments() {
        int m = task_list_.size();
        price_ = vector<float>(m, 0.0f);
        bidder_ = vector<int>(m, -1);
        isdone_ = vector<bool>(m, false);
        alpha_ = 0;
        
        for (int j = 0; j < m; ++j) {
            if (!task_list_[j].task_status) {
                price_[j] = -calculate_distance(task_list_[j].task_position);
            }
        }
    }

    double calculate_distance(const geometry_msgs::msg::Point& task_position) {
        return sqrt(pow(agent_position_.x - task_position.x, 2) +
                    pow(agent_position_.y - task_position.y, 2) +
                    pow(agent_position_.z - task_position.z, 2));
    }

    void broadcast() {
        auto msg = Auctioninfo();
        msg.agent_id = agent_id_;
        msg.price = price_;
        msg.bidder = bidder_;
        msg.isdone = isdone_;
        msg.task_list = task_list_;  // task_list_를 msg에 추가
        auto now = this->now();
        msg.timestamp = std::to_string(now.seconds() * 1000 + now.nanoseconds() / 1e6);
        pub_auction_->publish(msg);
    }

    int agent_id_;
    int path_ = -1;
    geometry_msgs::msg::Point agent_position_;
    vector<float> price_;
    vector<int> bidder_;
    vector<bool> isdone_;
    vector<Task> task_list_;
    vector<Auctioninfo::SharedPtr> received_msgs_;

    rclcpp::Publisher<Auctioninfo>::SharedPtr pub_auction_;
    rclcpp::Subscription<Auctioninfo>::SharedPtr sub_auction_;
    rclcpp::Subscription<Tasklist>::SharedPtr sub_task_list_;
    rclcpp::TimerBase::SharedPtr timer_;
};

int main(int argc, char *argv[]) {
    rclcpp::init(argc, argv);

    if (argc != 5) {
        RCLCPP_ERROR(rclcpp::get_logger("rclcpp"), "Usage: auction_node <agent_id> <x> <y> <z>");
        return 1;
    }

    int agent_id = atoi(argv[1]);
    geometry_msgs::msg::Point agent_position;
    agent_position.x = atof(argv[2]);
    agent_position.y = atof(argv[3]);
    agent_position.z = atof(argv[4]);

    auto auction_node = std::make_shared<Auction>(agent_id, agent_position);
    rclcpp::spin(auction_node);
    rclcpp::shutdown();
    return 0;
}
