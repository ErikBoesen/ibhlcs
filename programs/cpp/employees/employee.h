#pragma once
#include <iostream>


class Employee {
private:
    std::string name;
    unsigned long hireDate;

public:
    Employee() {};
    Employee(std::string name, unsigned long hireDate) {
        this->name = name;
        this->hireDate = hireDate;
    };
    ~Employee() {
        std::cout << "Ha murido " << this->name << std::endl;
    }
    std::string getName() {
        return this->name;
    };
    unsigned long getHireDate() {
        return this->hireDate;
    };
    void setName(std::string name) {
        this->name = name;
    };
    void setHireDate(unsigned long hireDate) {
        this->hireDate = hireDate;
    };
    bool operator == (const Employee& e) const {
        return (this->name == e.name
             && this->hireDate == e.hireDate);
    };
};
