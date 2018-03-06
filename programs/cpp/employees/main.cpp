#include <iostream>
#include "employee.h"

using namespace std;

int main() {
    Employee james;
    james.setName("Jake Kent");
    james.setHireDate(1520322911);
    Employee jake("Jake Kent", 1520322911);
    cout << james.getName() << endl;
    cout << jake.getHireDate() << endl;
    cout << (james == jake) << endl;
}
