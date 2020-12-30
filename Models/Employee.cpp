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
#include "Account.h"
#include "Departmans.h"

using namespace std;

class Employee : public People {
    int GAP = 20;
    Department department;
    vector<Task *> *tasks = nullptr;
    Task *taskList = nullptr;
    double bonus;
    bool isActive = true;
    double workHours;
    int taskSize = 0;
    int paidDayOffs;
    Account *account = nullptr;
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

    //ACCOUNT CREATE
    string convertTaskLevelTypes(TaskLevels taskLevels) {
        switch (taskLevels) {
            case EASY:
                return "EASY";
            case MEDIUM:
                return "MEDIUM";
            case HARD:
                return "HARD";
            case VERY_HARD:
                return "VERY HARD";
            default:
                return "INVALID TYPE";
        }
    }

    Department convertDepartmentType(int department) {
        switch (department) {
            case 0:
                return Software_Engineer;
            case 1:
                return Human_Resources;
            case 2:
                return Sales_Manager;
            case 3:
                return Intern;
            default:
                return IN_VALID_DEPARTMENT;
        }
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
        this->account = new Account;
        this->paidDayOffs = 0;
    }

    Employee(int userId, int password, string firstName, string lastName, char sex, string TC, string phone,
             int paidDayOffs,
             int department)
            : People(userId, password, firstName, lastName, sex, TC,
                     phone) {
        this->tasks = new vector<Task *>();
        this->taskList = new Task[0];
        this->department = Intern;
        this->bonus = 0;
        this->isActive = false;
        this->workHours = 0;
        this->GAP = 20;
        this->taskSize = 0;
        this->account = new Account;
        this->paidDayOffs = paidDayOffs;
        this->department = convertDepartmentType(department);
    }

    Employee(int userId, int password, string firstName, string lastName, char sex, string TC, string phone,
             string enterDate, int childNumber, int dayOffNumber, double salary, string address, string email,
             string birthDate, int department, int paidDayOffs, int workHours, int bonus) : People(userId, password,
                                                                                                   firstName,
                                                                                                   lastName, sex, TC,
                                                                                                   phone,
                                                                                                   enterDate,
                                                                                                   childNumber,
                                                                                                   dayOffNumber, salary,
                                                                                                   address, email,
                                                                                                   birthDate) {
        this->department = convertDepartmentType(department);
        this->paidDayOffs = dayOffNumber;
        this->workHours = workHours;
        this->bonus = bonus;
    }

    Employee(People const &people, int department, int paidDayOffs) : People(people) {
        this->department = convertDepartmentType(department);
        this->paidDayOffs = paidDayOffs;
    }

    ~Employee() {
        delete tasks;
        delete[] taskList;
        delete account;
    }

    Employee(Employee const &obj) {
        if (this->tasks != nullptr) {
            delete tasks;
        }
        if (taskList != nullptr) {
            delete[] taskList;
        }
        if (account != nullptr) {
            delete account;
        }
        department = obj.department;
        bonus = obj.bonus;
        isActive = obj.isActive;
        workHours = obj.workHours;
        GAP = obj.GAP;

        this->account = obj.account;
        tasks = new vector<Task *>;
        taskList = new Task[obj.taskSize];
        this->paidDayOffs = obj.paidDayOffs;
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
        cout << left << setw(GAP) << "TC";
        cout << left << setw(GAP) << "Birth Date";
        cout << left << setw(GAP) << "Email";
        cout << left << setw(GAP) << "Enter Date";
        cout << left << setw(GAP) << "Child Number";
        cout << left << setw(GAP) << "Day Off Number" << endl;
    }

    void displayMyInfo(bool headerExist = false) {
        if (!headerExist) {
            headerOfInfoTable();
        }
        cout << left << setw(GAP) << getUserId();
        cout << left << setw(GAP) << getFirstName();
        cout << left << setw(GAP) << getLastName();
        cout << left << setw(GAP) << getSex();
        cout << left << setw(GAP) << getTc();
        cout << left << setw(GAP) << getBirthDate();
        cout << left << setw(GAP) << getEmail();
        cout << left << setw(GAP) << getEnterDate();
        cout << left << setw(GAP) << getChildNumber();
        cout << left << setw(GAP) << getDayoffNumber() << endl;
    }


    bool assignNewTaskToEmployee(Task task) {
        bool isExist = false;
        bool assigned = false;

        for (Task *taskInfo : *tasks) {
            if (taskInfo->getId() == task.getId()) {
                isExist = true;
            }
        }

        if (!isExist) {
            tasks->push_back(new Task(task));

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

        cout << left << setw(GAP) << "Task ID";
        cout << left << setw(GAP) << "Task Title";
        cout << left << setw(GAP) << "Task Description";
        cout << left << setw(GAP) << "Task Status";
        cout << left << setw(GAP) << "Task Due Date";
        cout << left << setw(GAP) << "Task Diff Level" << endl;

        if (tasks != nullptr) {
            for (Task *task: *tasks) {
                cout << left << setw(GAP) << task->getId();
                cout << left << setw(GAP) << task->getTaskTitle();
                cout << left << setw(GAP) << task->getDescription();
                cout << left << setw(GAP) << convertTaskStatusTypes(task->getTaskStatus());
                cout << left << setw(GAP) << task->getDueDate();
                cout << left << setw(GAP) << convertTaskLevelTypes(task->getLevel()) << endl;
            }
        }
    }

    void showAccordingToStatus(TaskStatus taskStatus) {
        cout << "----Existing Tasks Of ";
        cout << getUserId();
        cout << "------------------" << endl;

        cout << left << setw(GAP) << "Task ID";
        cout << left << setw(GAP) << "Task Title";
        cout << left << setw(GAP) << "Task Description";
        cout << left << setw(GAP) << "Task Status";
        cout << left << setw(GAP) << "Task Diff Level" << endl;

        if (tasks != nullptr) {
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

    void setTasks(vector<Task *> *task) {
        this->tasks = task;
    }

    double getBonus() {
        if (tasks != nullptr) {
            this->bonus = account->calcBonus(*tasks);
        }
        return bonus;
    }

    void setBonus(double bonus) {
        Employee::bonus = bonus;
    }

    double getSalary() override {
        //this->salary = account->calcSalary(department, workHours, bonus);
        return salary;
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

    void setDayoffNumber(int paidDayOffs) {
        this->paidDayOffs = paidDayOffs;
    }

    int getDayoffNumber() { return paidDayOffs; }

    void setDepartmentWithInt(int department) {
        this->department = convertDepartmentType(department);
    }
};

#endif //PAYROLLMANEGEMENTSYSTEM_EMPLOYEE_CPP
