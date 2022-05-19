#include "EmployeePercentage.h"

EmployeePercentage::EmployeePercentage(string firstName, string lastName, string phone, string address, double percent, double price_product)
: Employee(firstName, lastName, phone, address) {
  this->percent = percent;
  this->price_product = price_product;
}

double EmployeePercentage::calculate_salary(double amount_product) {
  return amount_product * percent / 100 * price_product;
}

void EmployeePercentage::display() {
  Employee::display();
  cout << "Type: Employee percentage" << "\nPercent: " << this->percent << "\nPrice product: " << price_product << "\n\n";
}

string EmployeePercentage::get_info() {
  return "Percent " + Employee::get_info() + " " + to_string(this->percent) + " " + to_string(this->price_product);
}

void EmployeePercentage::edit_params(string first_name, string last_name, string phone, string address, double percent, double price_product) {
  this->first_name = first_name;
  this->last_name = last_name;
  this->phone = phone;
  this->address = address;
  this->percent = percent;
  this->price_product = price_product;
}