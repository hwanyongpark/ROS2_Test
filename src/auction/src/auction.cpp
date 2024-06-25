#include "rclcpp/rclcpp.hpp"
#include "custom_interfaces/msg/auctioninfo.hpp"
#include "custom_interfaces/msg/task.hpp"
#include "custom_interfaces/msg/tasklist.hpp"
#include "geometry_msgs/msg/point.hpp"
#include <vector>
#include <algorithm>
#include <tuple>
#include <string>
#include <cmath>

#define INF 1e9
#define EPSILON 0.5

using namespace std;
using namespace custom_interfaces::msg;

class Auction : public rclcpp::Node {
public:
    Auction(int agent_id, int max_tasks)
        : Node("auction"), agent_id_(agent_id), max_tasks_(max_tasks) {
        pub_auction_ = this->create_publisher<Auctioninfo>("auction_info", 10);
        sub_auction_ = this->create_subscription<Auctioninfo>("auction_info", 10, std::bind(&Auction::auction_callback, this, std::placeholders::_1));
        sub_task_list_ = this->create_subscription<Tasklist>("task_list", 10, std::bind(&Auction::task_list_callback, this, std::placeholders::_1));
        
        // 노드를 처음 실행할 때 초기화
        init_assignments();

        // 100ms마다 update 함수를 호출하는 타이머를 설정합니다.
        timer_ = this->create_wall_timer(
            std::chrono::milliseconds(100), 
            std::bind(&Auction::update, this));
    }

    void update() {
        double time = this->now().seconds();
        int m = task_list_.size();
        if (price_.empty() || bidder_.empty() || path_ == -1 || isdone_.empty()) {
            // 필요한 모든 매개 변수가 초기화되었는지 확인합니다.
            init_assignments();
        }

        auto price_previous = price_;

        // 외부 업데이트 (상호작용)
        auto msgs = getmsg();
        if (!msgs.empty()) {
            for (const auto &msg : msgs) {
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
                    isdone_[i] = isdone_[i] || msg->isdone[i];
                }
            }
        }

        // 내부 업데이트 -> 입찰
        for (int i = 0; i < m; ++i) {
            isdone_[i] = isdone_[i] || task_list_[i].task_status;
            if (isdone_[i]) {
                task_list_[i].task_status = true;
                price_[i] = 0;
                bidder_[i] = -1;  // 완료
                if (path_ == i) {
                    path_ = -1;
                }
            } else if (bidder_[i] == agent_id_ && path_ != i) {
                bidder_[i] = 0;
            }
        }
        if (all_of(isdone_.begin(), isdone_.end(), [](bool v) { return v; })) {
            path_ = -1;
        }

        // 모든 작업에 대한 보상 값을 계산하여 price_에 반영
        vector<double> rewards = reward();
        for (int j = 0; j < m; ++j) {
            if (!isdone_[j]) {
                price_[j] = rewards[j];
            }
        }

        // 단계 1: 가격 및 최고 입찰자 업데이트
        for (int j = 0; j < m; ++j) {
            double max_price = -INF;
            int max_bidder = -1;
            for (int k = 0; k < m; ++k) {
                if (price_[k] > max_price) {
                    max_price = price_[k];
                    max_bidder = bidder_[k];
                }
            }
            price_[j] = max_price;
            bidder_[j] = max_bidder;
        }

        // 단계 2: vi 및 wi 계산
        double vi = -INF;
        double wi = -INF;
        for (int j = 0; j < m; ++j) {
            double net_value = price_[j];
            if (net_value > vi) {
                vi = net_value;
            }
            if (j != path_ && net_value > wi) {
                wi = net_value;
            }
        }

        // 단계 3: gamma 계산
        double gamma = vi - wi + EPSILON;

        // 단계 4: 할당 업데이트 조건 확인
        if (path_ != -1 && price_previous[path_] <= price_[path_] && bidder_[path_] != agent_id_) {
            // 할당 업데이트
            path_ = distance(price_.begin(), max_element(price_.begin(), price_.end()));
            bidder_[path_] = agent_id_;
            price_[path_] += gamma;
        } else {
            // 현재 할당 유지
            path_ = path_;
        }

        // 단계 5: 정보 브로드캐스트
        broadcast();
    }

    void auction_callback(const Auctioninfo::SharedPtr msg) {
        // 들어오는 경매 메시지를 처리하는 콜백 함수
        int m = msg->price.size();
        for (int i = 0; i < m; ++i) {
            if (msg->price[i] > price_[i]) {
                price_[i] = msg->price[i];
                bidder_[i] = msg->bidder[i];
            }
            isdone_[i] = isdone_[i] || msg->isdone[i];
        }
    }

    void task_list_callback(const Tasklist::SharedPtr msg) {
        // 받은 메시지를 기반으로 작업 목록을 업데이트합니다.
        task_list_ = msg->tasks;
        // 작업 목록이 업데이트되면 초기화도 다시 실행해야 함
        init_assignments();
    }

private:
    void init_assignments() {
        int m = task_list_.size();
        price_ = vector<float>(m, 0.0f);
        bidder_ = vector<int>(m, -1);  // 초기 입찰자를 -1로 설정하여 아직 할당되지 않았음을 나타냄
        isdone_ = vector<bool>(m, false);
        path_ = -1;
    }

    vector<Auctioninfo::SharedPtr> getmsg() {
        // 실제 메시지 가져오기 로직을 위한 자리 표시자
        return {};
    }

    vector<double> reward() {
        // 에이전트의 위치를 (0, 0, 0)으로 가정합니다. 실제로는 에이전트의 위치를 설정해야 합니다.
        geometry_msgs::msg::Point agent_position;
        agent_position.x = 0.0;
        agent_position.y = 0.0;
        agent_position.z = 0.0;

        int m = task_list_.size();
        vector<double> rewards(m, -INF);

        // 각 작업에 대한 보상 값을 계산합니다.
        for (int j = 0; j < m; ++j) {
            auto task_position = task_list_[j].task_position;

            if (task_list_[j].task_status) {
                rewards[j] = -INF;
            } else {
                // 에이전트와 작업 사이의 유클리드 거리를 계산합니다.
                double distance = sqrt(pow(agent_position.x - task_position.x, 2) +
                                       pow(agent_position.y - task_position.y, 2) +
                                       pow(agent_position.z - task_position.z, 2));
                rewards[j] = -distance;
            }
        }

        return rewards;
    }

    void broadcast() {
        auto msg = Auctioninfo();
        msg.agent_id = agent_id_;
        msg.price = price_;
        msg.bidder = bidder_;
        msg.isdone = isdone_;
        pub_auction_->publish(msg);
    }

    int agent_id_;
    int max_tasks_;
    int path_ = -1;
    vector<float> price_;
    vector<int> bidder_;
    vector<bool> isdone_;
    vector<Task> task_list_;

    rclcpp::Publisher<Auctioninfo>::SharedPtr pub_auction_;
    rclcpp::Subscription<Auctioninfo>::SharedPtr sub_auction_;
    rclcpp::Subscription<Tasklist>::SharedPtr sub_task_list_;
    rclcpp::TimerBase::SharedPtr timer_;  // 타이머 추가
};

int main(int argc, char *argv[]) {
    rclcpp::init(argc, argv);
    auto auction_node = std::make_shared<Auction>(1, 10); // agent_id=1, max_tasks=10
    rclcpp::spin(auction_node);
    rclcpp::shutdown();
    return 0;
}
