#include <vector>


class Student {
public:
    float immunity;
    std::vector<Student*> friends;
    Student(float immunity) {
        this->immunity = immunity;
    };
    void add_friend(Student *f) {
        this->friends.push_back(f);
    };
};
