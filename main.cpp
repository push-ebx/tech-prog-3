#include <iostream>
#include <fstream>
#include "Employee.h"
#include "EmployeeInStaff.h"
#include "EmployeeHourly.h"
#include "EmployeePercentage.h"

using namespace std;

int Employee::count = 0;

string *split(string str, string delimiter, int count = 6) {
  int pos, i = 0;
  if (str.substr(0, str.find(delimiter)) == "Percent") count = 7;
  string *strings = new string[count];

  while ((pos = str.find(delimiter)) != string::npos) {
    strings[i++] = str.substr(0, pos);
    str.erase(0, pos + delimiter.length());
  }
  strings[i] = str;
  return strings;
}

int get_count_employees(fstream &in, string path) {
  string line;
  int counter = 0;
  in.open(path, ios::in);
  if (in.is_open()) {
    while (getline(in, line)) {
      ++counter;
    }
  }
  in.close();
  return counter;
}

void menu() {
  cout << "1. Add a new employe\n2. Edit a employe\n3. Delete a employe\n";
  cout << "4. Print list of employe\n5. Calculate salary of employe\n";
  cout << "6. Get count a employe\n7. Save and quit\n\n";
}

enum commands { ADD=1, EDIT, DELETE, PRINT, CALC_SALARY, GET_COUNT_EMP, EXIT };

int main() {
  fstream in;
  string path("Employees.txt"), type, line;
  bool is_exit = false;
  int act, employee, count_employees = get_count_employees(in, path);
  Employee **employees = new Employee *[count_employees];

  in.open(path, ios::in);
  if (in.is_open()) {
    int i = 0;
    while (getline(in, line)) {
      string *params = split(line, " ");
      if (params[0] == "Percent") {
        employees[i++] = new EmployeePercentage(params[1], params[2], params[3], params[4], stod(params[5]), stod(params[6]));
      } else if (params[0] == "Hourly") {
        employees[i++] = new EmployeeHourly(params[1], params[1], params[3], params[4], stod(params[5]));
      } else if (params[0] == "Staff") {
        employees[i++] = new EmployeeInStaff(params[1], params[2], params[3], params[4], stod(params[5]));
      }
    }
  }
  in.close();
  menu();
  while (!is_exit) {
    cout << "\nEnter action: "; cin >> act;
    system("cls");
    menu();
    if (act == EXIT) is_exit = true;
    else if (act == PRINT) {
      for (int i = 0; i < count_employees; ++i) {
        cout << i + 1 << ". ";
        employees[i]->display();
      }
    }
    else if (act == ADD) {
      int salary, price, percent;
      string name, surname, address, phone;
      cout << "Select type of employee (1 - staff, 2 - hourly, 3 - percent): "; cin >> employee;
      cout << "Enter name: "; cin >> name;
      cout << "Enter surname: "; cin >> surname;
      cout << "Enter address: "; cin >> address;
      cout << "Enter phone: "; cin >> phone;

      if (employee == 1) { 
        cout << "Enter salary per month: "; cin >> salary;
      } else if (employee == 2) { 
        cout << "Enter salary per hour: "; cin >> salary;
      } else if (employee == 3) { 
        cout << "Enter percent: "; cin >> percent;
        cout << "Enter price product: "; cin >> price;
      }

      Employee** p = new Employee*[count_employees];
      for (int i = 0; i < count_employees; ++i)
        p[i] = employees[i];

      delete[] employees;
      employees = new Employee*[++count_employees];

      if (employee == 1) employees[count_employees - 1] = new EmployeeInStaff(name, surname,phone, address, salary);
      else if (employee == 2) employees[count_employees - 1] = new EmployeeHourly(name, surname,phone, address, salary);
      else if (employee == 3) employees[count_employees - 1] = new EmployeePercentage(name, surname,phone, address, percent, price);

      for (int i = 0; i < count_employees - 1; ++i)
        employees[i] = p[i];
      delete[] p;
    }
    else if (act == DELETE) {
      cout << "Select a employee for its removal: "; cin >> employee;

      Employee** p = new Employee*[count_employees];
      Employee::count--;
      for (int i = 0; i < count_employees; ++i)
        p[i] = employees[i];
      delete[] employees;

      employees = new Employee*[--count_employees];
      employee--;
      int j = 0;

      for (int i = 0; i < employee; ++i)
        employees[j++] = p[i];
      for (int i = employee + 1; i < count_employees + 1; ++i)
        employees[j++] = p[i];
      delete[] p;
    }
    else if (act == CALC_SALARY) {
      double koef;
      int num;
      cout << "Select a employee for its calculate salary: "; cin >> num;
      cout << "Enter a type of employee (1 - staff, 2 - hourly, 3 - percent): "; cin >> employee;
      if (employee == 1) {
        cout << employees[num - 1]->calculate_salary() << endl;
      } else if (employee == 2) {
        cout << "Enter count of hours: "; cin >> koef;
        cout << employees[num - 1]->calculate_salary(koef) << endl;
      } else if (employee == 3) {
        cout << "Enter count of sold products: "; cin >> koef;
        cout << employees[num - 1]->calculate_salary(koef) << endl;
      }
    }
    else if (act == EDIT) {
      int salary, price, percent, num;
      string name, surname, address, phone;
      cout << "Select a employee for its edit: "; cin >> num;
      cout << "Select type of employee (1 - staff, 2 - hourly, 3 - percent): "; cin >> employee;
      cout << "Enter name: "; cin >> name;
      cout << "Enter surname: "; cin >> surname;
      cout << "Enter address: "; cin >> address;
      cout << "Enter phone: "; cin >> phone;

      if (employee == 1) { 
        cout << "Enter salary per month: "; cin >> salary;
        employees[--num]->edit_params(name, surname, phone, address, salary);
      } else if (employee == 2) { 
        cout << "Enter salary per hour: "; cin >> salary;
        employees[--num]->edit_params(name, surname, phone, address, salary);
      } else if (employee == 3) { 
        cout << "Enter percent: "; cin >> percent;
        cout << "Enter price product: "; cin >> price;
        employees[--num]->edit_params(name, surname, phone, address, percent, price);
      }
    }
    else if (act == GET_COUNT_EMP) {
      cout << Employee::count << endl;
    }
  }
  
  in.open(path, ios::out);
  if (in.is_open()) {
    for (int i = 0; i < count_employees; ++i) {
      in << employees[i]->get_info() << endl;
    }
  }
  in.close();
  delete[] employees;
  return 0;
}

// g++ Employee.cpp Employee.h EmployeeHourly.cpp EmployeeHourly.h EmployeeInStaff.cpp EmployeeInStaff.h EmployeePercentage.cpp EmployeePercentage.h main.cpp -o main