#include <iostream>
#include "school.h"
#include "student.h"

int main(int argc, char *argv[]) {
    Student a(0.5);
    Student b(0.6);
    a.add_friend(&b);
    b.add_friend(&a);
    std::cout << "Student A has " << a.friends.size() << " friend(s)." << std::endl;
    School school(700);
    std::cout << "School has " << school.students.size() << " students." << std::endl;
    // TODO: Allow number of students to be specified in CLI argument
    return 0;
}
