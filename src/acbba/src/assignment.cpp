#include <functional>
#include <vector>

class Assignment {
protected:
    std::vector<Task> task_list;
    int agent_id;

    // Function handles as std::function
    std::function<void(std::map<std::string, double>)> broadcast;
    std::function<std::vector<std::map<std::string, double>>()> getmsg;
    std::function<double(Task)> reward;

public:
    // Abstract methods must be implemented by derived classes
    virtual void update(double time) = 0;
    virtual Task getTask() = 0;
    virtual void addTask(const Task& newTask) = 0;
    virtual void releaseAll() = 0;
    virtual void setTaskList(const std::vector<Task>& task_list) = 0;

    // Constructor
    Assignment(int id,
               std::function<void(std::map<std::string, double>)> broadcast_fh,
               std::function<std::vector<std::map<std::string, double>>()> getmsg_fh,
               std::function<double(Task)> reward_fh) 
               : agent_id(id), broadcast(broadcast_fh), getmsg(getmsg_fh), reward(reward_fh) {}
};