#pragma once
#include "Employee.h"

class EmployeePercentage : public Employee {
private:
    double percent, price_product;
public:
    EmployeePercentage(string firstName, string lastName, string phone, string address, double percent, double price_product);
    double calculate_salary(double amount_product) override;
    void display() override;
    string get_info() override;
    void edit_params(string first_name, string last_name, string phone, string address, double percent, double price_product);
};