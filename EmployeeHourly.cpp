#include "EmployeeHourly.h"

EmployeeHourly::EmployeeHourly(string firstName, string lastName, string phone, string address, double salary_per_hour) : Employee(
  firstName, lastName, phone, address) {
  this->salary_per_hour = salary_per_hour;
}

double EmployeeHourly::calculate_salary(double count_hours) {
  return salary_per_hour * count_hours;
}

void EmployeeHourly::display() {
  Employee::display();
  cout << "Type: Employee hourly" << "\nSalary per hour: " << salary_per_hour << "\n\n";
}

string EmployeeHourly::get_info() {
return "Hourly " + Employee::get_info() + " " + to_string(this->salary_per_hour);
}

void EmployeeHourly::edit_params(string first_name, string last_name, string phone, string address, double salary, double koef2) {
  this->first_name = first_name;
  this->last_name = last_name;
  this->phone = phone;
  this->address = address;
  this->salary_per_hour = salary;
}