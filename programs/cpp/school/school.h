#include <vector>
#include "student.h"


class School {
public:
    unsigned short population;
    std::vector<Student> students;
    School(int population) {
        this->population = population;
        for (int i = 0; i < population; i++) {
            this->students.push_back(Student(0.5));
        }
    };
    std::vector<Student> get_students() {
        return this->students;
    }
};
