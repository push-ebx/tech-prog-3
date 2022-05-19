#include "EmployeeInStaff.h"
#include "Employee.h"

EmployeeInStaff::EmployeeInStaff(string firstName, string lastName, string phone, string address, double salary) : Employee(
  firstName, lastName, phone, address) {
  this->salary = salary;
}

double EmployeeInStaff::calculate_salary(double koef) {
  return salary;
}

void EmployeeInStaff::display() {
  Employee::display();
  cout << "Type: Employee in the staff" << "\nSalary per month: " << salary << "\n\n";
}

string EmployeeInStaff::get_info() {
  return "Staff " + Employee::get_info() + " " + to_string(this->salary);
}

void EmployeeInStaff::edit_params(string first_name, string last_name, string phone, string address, double salary, double koef2) {
  this->first_name = first_name;
  this->last_name = last_name;
  this->phone = phone;
  this->address = address;
  this->salary = salary;
}