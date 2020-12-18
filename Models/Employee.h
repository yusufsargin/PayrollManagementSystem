//
// Created by YUSUF on 18.12.2020.
//

#ifndef PAYROLLMANEGEMENTSYSTEM_EMPLOYEE_H
#define PAYROLLMANEGEMENTSYSTEM_EMPLOYEE_H

#include "People.h"
#include "Task.h"
#include <vector>

enum Department {
    Software_Engineer,
    Human_Resources,
    Sales_Manager,
    Intern
};

using namespace std;

class Employee : public People {
    Department department;
    vector<Task> *tasks;
    double bonus;
    bool isActive;
    double workHours;
public:
    Employee() : People() {
        this->department = Intern;
        this->bonus = 0;
        this->isActive = false;
        this->workHours = 0;
        this->tasks = new vector<Task>;
    }

    Employee(string firstName, string lastName, char sex, int TC, string phone)
            : People(firstName, lastName, sex, TC,
                     phone) {}

    void displayMyInfo() {
        cout << getFirstName() << endl;
        cout << getLastName() << endl;
        cout << getSex() << endl;
        cout << getPhone() << endl;
    }

    Department getDepartment() const {
        return department;
    }

    void setDepartment(Department department) {
        Employee::department = department;
    }

    vector<Task> *getTasks() const {
        return tasks;
    }

    bool assignNewTask(Task task) {
        bool isExist = false;

        for (Task taskInfo : *tasks) {
            if (taskInfo.id == task.id) {
                isExist = true;
            }
        }

        if (!isExist) {
            this->tasks->push_back(task);

            return true;
        }

        return false;
    }

    double getBonus() const {
        return bonus;
    }

    void setBonus(double bonus) {
        Employee::bonus = bonus;
    }

    bool isActive1() const {
        return isActive;
    }

    void setIsActive(bool isActive) {
        Employee::isActive = isActive;
    }

    double getWorkHours() const {
        return workHours;
    }

    void setWorkHours(double workHours) {
        Employee::workHours = workHours;
    }
};

#endif //PAYROLLMANEGEMENTSYSTEM_EMPLOYEE_H
