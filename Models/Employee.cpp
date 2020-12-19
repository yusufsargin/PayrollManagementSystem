//
// Created by YUSUF on 18.12.2020.
//

#ifndef PAYROLLMANEGEMENTSYSTEM_EMPLOYEE_CPP
#define PAYROLLMANEGEMENTSYSTEM_EMPLOYEE_CPP

#include "People.h"
#include "Task.h"
#include <vector>
#include <iostream>
#include <iomanip>

enum Department {
    Software_Engineer,
    Human_Resources,
    Sales_Manager,
    Intern
};

using namespace std;

class Employee : public People {
    int GAP = 20;
    Department department;
    vector<Task> *tasks;
    double bonus;
    bool isActive;
    double workHours;

private:
    string convertTaskStatusTypes(TaskStatus taskStatus) {
        switch (taskStatus) {
            case WAITING:
                return "WAITING";
            case IN_PROGRESS:
                return "IN PROGRESS";
            case DONE:
                return "DONE";
            default:
                return "INVALID TYPE";
        }
    }

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
                     phone) {
        this->department = Intern;
        this->bonus = 0;
        this->isActive = false;
        this->workHours = 0;
        this->tasks = new vector<Task>();
    }

    ~Employee() {
        delete tasks;
    }

    Employee(Employee &obj) {
        int taskSize = tasks->size();
        delete tasks;

        department = obj.department;
        bonus = obj.bonus;
        isActive = obj.isActive;
        workHours = obj.workHours;

        tasks = new vector<Task>();

        for (int i = 0; i < taskSize; i++) {
            tasks->at(i) = obj.tasks->at(i);
        }
    }

    void displayMyInfo() {
        cout << left << setw(GAP) << "First Name";
        cout << left << setw(GAP) << "Last Name";
        cout << left << setw(GAP) << "Sex";
        cout << left << setw(GAP) << "Phone" << endl;

        cout << left << setw(GAP) << getFirstName();
        cout << left << setw(GAP) << getLastName();
        cout << left << setw(GAP) << getSex();
        cout << left << setw(GAP) << getPhone() << endl;
    }


    bool assignNewTaskToEmployee(Task task) {
        bool isExist = false;

        for (Task taskInfo : *tasks) {
            if (taskInfo.getId() == task.getId()) {
                isExist = true;
            }
        }

        if (!isExist) {
            this->tasks->push_back(task);

            return true;
        }

        return false;
    }

    bool editTask(int taskId, Task task) {
        bool isUpdate = false;

        for (int i = 0; i < tasks->size(); i++) {
            if (tasks->at(i).getId() == task.getId()) {
                tasks->at(i) = task;
                isUpdate = true;
            }
        }


        return isUpdate;
    }

    void showExistTasks() {
        cout << "----Existing Tasks-----" << endl;

        cout << left << setw(GAP) << "Task ID" <<
             left << setw(GAP) << "Task Title" <<
             left << setw(GAP) << "Task Description" <<
             left << setw(GAP) << "Task Status"
             << left << setw(GAP) << "Task Diff Level" << endl;
        for (Task task:*tasks) {
            cout << left << setw(GAP) << task.getId();
            cout << left << setw(GAP) << task.getTaskTitle();
            cout << left << setw(GAP) << task.getDescription();
            cout << left << setw(GAP) << convertTaskStatusTypes(task.getTaskStatus());
            cout << left << setw(GAP) << task.getLevel() << endl;
        }
    }

    void showAccordingToStatus(TaskStatus taskStatus) {
        cout << "----Existing Tasks-----" << endl;

        cout << left << setw(GAP) << "Task ID" <<
             left << setw(GAP) << "Task Title" <<
             left << setw(GAP) << "Task Description"
             << left << setw(GAP) << "Task Diff Level" << endl;
        for (Task task:*tasks) {
            if (task.getTaskStatus() == taskStatus) {
                cout << left << setw(GAP) << task.getId();
                cout << left << setw(GAP) << task.getTaskTitle();
                cout << left << setw(GAP) << task.getDescription();
                cout << left << setw(GAP) << convertTaskStatusTypes(task.getTaskStatus());
                cout << left << setw(GAP) << task.getLevel() << endl;
            }
        }
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

#endif //PAYROLLMANEGEMENTSYSTEM_EMPLOYEE_CPP
