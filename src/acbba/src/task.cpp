#include <vector>
#include <string>

class Task {
public:
    std::string Type;
    bool isdone;
    double reward;
    double discount;
    std::string agent_type;
    std::vector<double> Loc;

    // 생성자
    Task(const std::string& type, const std::vector<double>& loc, const std::string& agent_type)
        : Type(type), Loc(loc), isdone(false), reward(100), discount(0.5), agent_type(agent_type) {}

    // 동등 비교 연산자
    bool operator==(const Task& other) const {
        return (Type == other.Type) && 
               (Loc == other.Loc) && 
               (isdone == other.isdone);
    }

    // 작업 완료 메소드
    bool complete() {
        isdone = true;
        return isdone;
    }

    // 위치 정보 반환
    std::vector<double> getLoc() const {
        return Loc;
    }
};