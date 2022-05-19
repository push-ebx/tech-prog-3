#pragma once
#include "Employee.h"

class EmployeeHourly : public Employee {
private:
    double salary_per_hour;
public:
    EmployeeHourly(string firstName, string lastName, string phone, string address, double salary_per_hour);
    double calculate_salary(double count_hours) override;
    void display() override;
    string get_info() override;
    void edit_params(string first_name, string last_name, string phone, string address, double salary, double koef2=0) override;
};