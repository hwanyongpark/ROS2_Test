ACBBA::ACBBA(int id, std::function<void(std::map<std::string, double>)> broadcast_fh, 
             std::function<std::vector<std::map<std::string, double>>()> getmsg_fh, 
             std::function<double(const Task&)> reward_fh, int maxtasks)
    : Assignment(id, broadcast_fh, getmsg_fh, reward_fh), max_task(maxtasks) {}

// Update method
void ACBBA::update(double time) {
    phase1(time);
    phase2(time);
}

void ACBBA::phase1(double time) {
    if (task_list.empty() || price.size() != task_list.size()) {
        price.resize(task_list.size(), 0);
        bidder.resize(task_list.size(), 0);
        timestamp.resize(task_list.size(), 0);
        isdone.resize(task_list.size(), false);
    }

    for (int i = 0; i < task_list.size(); ++i) {
        if (!isdone[i] && (bundle.size() < max_task)) {
            double r;
            int idx;
            std::tie(r, idx) = marginal(task_list[i]);

            if (r > price[i]) {
                bundle.push_back(i);
                price[i] = r;
                bidder[i] = agent_id;
                timestamp[i] = time;
            }
        }
    }
}