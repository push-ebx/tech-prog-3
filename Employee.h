#pragma once
#include <iostream>

using namespace std;

class Employee {
protected:
    string first_name, last_name, phone, address;
public:
    static int count;
    Employee();
    ~Employee();
    Employee(string first_name, string last_name, string phone, string address);

    virtual double calculate_salary(double koef=0);
    virtual void display();
    virtual string get_info();
    virtual void edit_params(string first_name, string last_name, string phone, string address, double koef1=0, double koef2=0);
};