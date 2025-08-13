//YASH BHURE
//B24CE1095
//Assignment 2
#include<iostream>
#include<string>
using namespace std;

class employee {
private:
    string name;
    int emp_id;
    string department;
    string date;
    int contact;
    static int emp_count;

public:
    employee() {
        cout << "Default employee object created." << endl;
        name = "Kartik";
        emp_id = 0;
        department = "DONT CARE";
        date = "NEVER";
        contact = 0;
        emp_count++;
    }

    employee(string a, string b, string c, int d, int e) {
        name = a;
        department = b;
        date = c;
        emp_id = d;
        contact = e;
        cout << "Employee object created for " << name << endl;
        emp_count++;
    }

    employee(const employee& other) {
        name = other.name;
        emp_id = other.emp_id;
        department = other.department;
        date = other.date;
        contact = other.contact;
        cout << "Employee object created by copying " << name << endl;
        emp_count++;
    }

    ~employee() {
        cout << "Destructed Employee: " << name << endl;
    }

    void display();
    static void display_emp_count();
};

int employee::emp_count = 0;

void employee::display() {
    cout << "--- EMPLOYEE INFORMATION ---\n";
    cout << "Name           : " << name << "\n";
    cout << "Employee ID    : " << emp_id << "\n";
    cout << "Department     : " << department << "\n";
    cout << "Working From   : " << date << "\n";
    cout << "Phone number   : " << contact << "\n";
    cout << "--------------------------------\n";
}

void employee::display_emp_count() {
    cout << "Total number of employees created: " << emp_count << endl;
}

int main() {
    string name, department, date;
    int emp_id, contact;

    cout << "WELCOME\n";
    cout << "Creating a default employee object:" << endl;
    employee default_obj;
    default_obj.display();
    employee::display_emp_count();

    cout << "\n--- Enter details for a new employee ---\n";
    cout << "Enter your name: ";
    getline(cin, name);
    cout << "Employee ID: ";
    cin >> emp_id;
    cout << "Department: ";
    cin.ignore();
    getline(cin, department);
    cout << "Date of joining: ";
    getline(cin, date);
    cout << "Phone: ";
    cin >> contact;

    cout << "\nDetails:\n";
    employee new_employee(name, department, date, emp_id, contact);
    new_employee.display();
    employee::display_emp_count();

    cout << "\n--- Demonstrating the Copy Constructor ---\n";
    employee copied_employee = new_employee;
    cout << "\nCopied Employee Details:\n";
    copied_employee.display();
    employee::display_emp_count();

    // ***** Using new and delete *****
    cout << "\n--- Creating a dynamic employee using 'new' ---\n";
    employee* dynamic_employee = new employee("Dynamic Emp", "IT", "05-08-2025", 999, 123456789);
    dynamic_employee->display();
    employee::display_emp_count();

    cout << "\n--- Deleting the dynamically created employee using 'delete' ---\n";
    delete dynamic_employee;  // Calls destructor for the dynamic object

    cout << "\nDestructors for remaining objects will be called automatically at the end of main()\n";
    return 0;
}
