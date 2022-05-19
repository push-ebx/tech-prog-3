#include "Employee.h"

Employee::Employee() {}
Employee::~Employee() { count--; }
Employee::Employee(string first_name, string last_name, string phone, string address) {
  this->first_name = first_name;
  this->last_name = last_name;
  this->phone = phone;
  this->address = address;
  count++;
}

double Employee::calculate_salary(double) {}

void Employee::display() {
  cout << "Name: " << this->first_name << "\nSurname: " << this->last_name << "\nPhone: " << this->phone;
  cout << "\nAddress: " << this->address << endl;
}

string Employee::get_info() {
  return this->first_name + " " + this->last_name + " " + this->phone + " " + this->address;
}

void Employee::edit_params(string first_name, string last_name, string phone, string address, double koef1, double koef2) {}