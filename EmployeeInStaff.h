#pragma once
#include "Employee.h"

class EmployeeInStaff : public Employee {
private:
    double salary;
public:
    EmployeeInStaff(string firstName, string lastName, string phone, string address, double salary);
    double calculate_salary(double koef = 1) override;
    void display() override;
    string get_info();
    void edit_params(string first_name, string last_name, string phone, string address, double salary, double koef2=0);
};