#include <iostream>
#include <string>

using namespace std;

class Employee {
protected:
    string name;
    double salary;

public:
    void setName(string name) {
        this->name = name;
    }

    void setSalary(double salary) {
        if (salary >= 0) {  // Validate salary to be non-negative
            this->salary = salary;
        } else {
            cerr << "Error: Salary cannot be negative." << endl;
        }
    }

    virtual double getTotalEarnings() = 0;  // Pure virtual function for total earnings
};

class Manager : public Employee {
private:
    double bonus;

public:
    void setBonus(double bonus) {
        this->bonus = bonus;
    }

    double getTotalEarnings() override {
        return salary + bonus;
    }

    void info() {
        cout << "Name of manager is " << name << endl;
        cout << "Salary of manager is " << salary << endl;
        cout << "Bonus of manager is " << bonus << endl;
        cout << "Total earning of manager is " << getTotalEarnings() << endl;
    }
};

class Intern : public Employee {
private:
    double hourlyRate;
    double hoursWorked;

public:
    void setHourlyRate(double rate) {
        if (rate >= 0) {  // Validate hourly rate to be non-negative
            hourlyRate = rate;
        } else {
            cerr << "Error: Hourly rate cannot be negative." << endl;
        }
    }

    void setHoursWorked(double hours) {
        if (hours >= 0) {  // Validate hours worked to be non-negative
            hoursWorked = hours;
        } else {
            cerr << "Error: Hours worked cannot be negative." << endl;
        }
    }

    double getTotalEarnings() override {
        return hourlyRate * hoursWorked;
    }

    void info() {
        cout << "Name of intern is " << name << endl;
        cout << "Hourly rate of intern is " << hourlyRate << endl;
        cout << "Hours worked by intern is " << hoursWorked << endl;
        cout << "Total earning of intern is " << getTotalEarnings() << endl;
    }
};

int main() {
    Manager m1;
    Intern i1;

    string name;
    double salary, bonus, hourlyRate, hours;
    int choice;

    cout << "1. For Manager" << endl;
    cout << "2. For Intern" << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
    case 1:
        cout << "Enter manager name: ";
        cin >> name;
        cout << "Enter salary of manager: ";
        cin >> salary;
        cout << "Enter bonus of manager: ";
        cin >> bonus;

        m1.setName(name);
        m1.setSalary(salary);
        m1.setBonus(bonus);

        cout << endl;  // Add a newline for better formatting
        m1.info();

        break;
    case 2:
        cout << "Enter intern name: ";
        cin >> name;
        cout << "Enter hours of intern: ";
        cin >> hours;  // Corrected: Input for hours worked
        cout << "Enter hourly rate of intern: ";
        cin >> hourlyRate;

        i1.setName(name);
        i1.setHoursWorked(hours);  // Corrected: Set hours worked
        i1.setHourlyRate(hourlyRate);

        cout << endl;  // Add a newline for better formatting
        i1.info();

        break;
    default:
        cout << "Invalid input!" << endl;
    }

    return 0;
}