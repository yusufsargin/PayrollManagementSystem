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
    vector<Task *> *tasks = nullptr;
    Task *taskList = nullptr;
    double bonus;
    bool isActive;
    double workHours;
    int taskSize = 0;

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

private:
    void pushNewTask(Task task) {
        taskSize = taskSize + 1;
        cout << "TASK SIZE " << taskSize << endl;

        Task *tempTask = new Task[taskSize];

        for (int i = 0; i < taskSize - 1; i++) {
            cout << "TEDDE" << endl;
            tempTask[i] = taskList[i];
        }

        tempTask[taskSize - 1] = task;

        cout << task.getDescription() << endl;

        delete[] taskList;
        this->taskList = new Task[taskSize];

        for (int i = 0; i < taskSize; i++) {
            taskList[i] = tempTask[i];
            cout << taskList[i].getDescription() << endl;
        }

        delete[] tempTask;
    }

public:
    Employee() : People() {
        this->tasks = new vector<Task *>();
        this->taskList = new Task[0];
        this->department = Intern;
        this->bonus = 0;
        this->isActive = false;
        this->workHours = 0;
        this->taskSize = 0;
    }

    Employee(string firstName, string lastName, char sex, int TC, string phone)
            : People(firstName, lastName, sex, TC,
                     phone) {
        this->tasks = new vector<Task *>();
        this->taskList = new Task[0];
        this->department = Intern;
        this->bonus = 0;
        this->isActive = false;
        this->workHours = 0;
        this->GAP = 20;
        this->taskSize = 0;
    }

    ~Employee() {
        delete tasks;
        delete[] taskList;
    }

    Employee(Employee const &obj) {
        if (this->tasks != nullptr) {
            delete tasks;
        }
        if (taskList != nullptr) {
            delete[] taskList;
        }
        department = obj.department;
        bonus = obj.bonus;
        isActive = obj.isActive;
        workHours = obj.workHours;
        GAP = obj.GAP;

        tasks = new vector<Task *>;
        taskList = new Task[obj.taskSize];
        this->taskSize = obj.taskSize;
        for (int i = 0; i < obj.taskSize; i++) {
            tasks->at(i) = obj.tasks->at(i);
            taskList[i] = obj.taskList[i];
        }
    }

    void headerOfInfoTable() {
        cout << left << setw(GAP) << "User ID";
        cout << left << setw(GAP) << "First Name";
        cout << left << setw(GAP) << "Last Name";
        cout << left << setw(GAP) << "Sex";
        cout << left << setw(GAP) << "Phone" << endl;
    }

    void displayMyInfo(bool headerExist = false) {
        if (!headerExist) {
            headerOfInfoTable();
        }
        cout << left << setw(GAP) << getUserId();
        cout << left << setw(GAP) << getFirstName();
        cout << left << setw(GAP) << getLastName();
        cout << left << setw(GAP) << getSex();
        cout << left << setw(GAP) << getPhone() << endl;
    }


    bool assignNewTaskToEmployee(Task task) {
        bool isExist = false;
        bool assigned = false;

        for (Task *taskInfo : *tasks) {
            if (taskInfo->getId() == task.getId()) {
                isExist = true;
            }
        }

        /*for (int i = 0; i < taskSize; i++) {
            if (taskList[i].getId() == task.getId()) {
                isExist = true;
            }
        }*/

        if (!isExist) {
            tasks->push_back(new Task(task));
            cout << tasks->at(0)->getDueDate() << endl;
            //pushNewTask(task);
            assigned = true;
        }

        return assigned;
    }

    bool editTask(int taskId, Task task) {
        bool isUpdate = false;

        for (int i = 0; i < tasks->size(); i++) {
            if (tasks->at(i)->getId() == task.getId()) {
                tasks->at(i) = &task;
                isUpdate = true;
            }
        }


        return isUpdate;
    }

    void showExistTasks() {
        cout << "----Existing Tasks Of ";
        cout << getUserId();
        cout << "------------------" << endl;

        cout << left << setw(GAP) << "Task ID" <<
             left << setw(GAP) << "Task Title" <<
             left << setw(GAP) << "Task Description" <<
             left << setw(GAP) << "Task Status"
             << left << setw(GAP) << "Task Diff Level" << endl;

        for (Task *task: *tasks) {
            cout << left << setw(GAP) << task->getId();
            cout << left << setw(GAP) << task->getTaskTitle();
            cout << left << setw(GAP) << task->getDescription();
            cout << left << setw(GAP) << convertTaskStatusTypes(task->getTaskStatus());
            cout << left << setw(GAP) << task->getLevel() << endl;
        }
    }

    void showAccordingToStatus(TaskStatus taskStatus) {
        cout << "----Existing Tasks-----" << endl;

        cout << left << setw(GAP) << "Task ID" <<
             left << setw(GAP) << "Task Title" <<
             left << setw(GAP) << "Task Description"
             << left << setw(GAP) << "Task Diff Level" << endl;
        for (Task *task:*tasks) {
            if (task->getTaskStatus() == taskStatus) {
                cout << left << setw(GAP) << task->getId();
                cout << left << setw(GAP) << task->getTaskTitle();
                cout << left << setw(GAP) << task->getDescription();
                cout << left << setw(GAP) << convertTaskStatusTypes(task->getTaskStatus());
                cout << left << setw(GAP) << task->getLevel() << endl;
            }
        }
    }

    Department getDepartment() const {
        return department;
    }

    void setDepartment(Department department) {
        Employee::department = department;
    }

    vector<Task *> *getTasks() const {
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
