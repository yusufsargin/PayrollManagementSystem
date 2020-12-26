//
// Created by yusuf_sargin on 24.12.2020.
//


/**
+ checkTaskStatus(id:int):Task
+ checkTeamStatus()
+ updateTaskDueDate(id:int,value:string):Task
+ deleteTask(id:int):Task
+ assingTaskToEmployee(Employee,Task)
 */

#ifndef PAYROLLMANEGEMENTSYSTEM_MANAGER_CPP
#define PAYROLLMANEGEMENTSYSTEM_MANAGER_CPP

#include "Employee.cpp"
#include "Team.cpp"
#include "Task.h"
#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Manager : public Employee {
    Team *team = nullptr;
public:
    Manager() : Employee() {
        this->team = new Team;
    }

    Manager(string firstName, string lastName, char sex, int tc, string phone) : Employee(firstName, lastName, sex, tc,
                                                                                          phone) {
        this->team = new Team;
    }

    Manager(Manager const &obj) {
        if (team != nullptr) {
            delete team;
        }
        this->team = new Team;
    }

    ~Manager() {
        delete team;
    }

    void setTeamMembers(vector<Employee *> *list, int listSize) {
        team->collectTeamMembersFromStorageVector(*list, listSize);
    }

    void showTeamMembers() {
        team->showMembersInfo();
    }

    void showAllTasks() {
        team->showMembersTaskList();
    }

    void updateTaskDueData(int id, string dueDate) {
        team->updateTaskDueDate(id, dueDate);
    }

    void assignTaskToEmployee(int employeeID, Task task) {
        //team->assignTaskToEmployee(employeeID, task);
    }

    void showManagerInfo() {
        this->displayMyInfo();
    }
};


#endif //PAYROLLMANEGEMENTSYSTEM_MANAGER_CPP
