#pragma once
#include <vector>
#include "friendship.h"


class Student {
private:
    float immunity;
    std::vector<Student*> friends;

public:
    Student(float immunity) {
        this->immunity = immunity;
    };
    void add_friend(Student *f) {
        this->friends.push_back(f);
    };
    std::vector<Student*> get_friends() {
        return this->friends;
    };
};
