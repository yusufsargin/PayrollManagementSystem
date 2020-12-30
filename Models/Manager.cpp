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
    Employee *employee;
public:
    Manager() : Employee() {
        this->team = new Team;
        employee = new Employee;
    }

    Manager(vector<Employee *> *employeeList) {
        this->team = new Team(employeeList);
        for(Employee *emp: *employeeList){
            if(emp->getDepartment() == Sales_Manager){
                this->employee = emp;
                break;
            }
        }
    }

    /* Manager(int userId, string firstName, string lastName, char sex, int tc, string phone) : Employee(userId, firstName,
                                                                                                       lastName, sex, tc,
                                                                                                       phone,0,0) {
         this->team = new Team;
     }*/

    Manager(Manager const &obj) {
        if (team != nullptr) {
            delete team;
        }
        this->team = new Team;
    }

    ~Manager() {
        delete team;
        delete employee;
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

    void assignTaskToEmployee(int employeeID, Task *task) {
        team->assignTaskToEmployee(employeeID, task);
    }

    void showManagerInfo() {
        this->employee->displayMyInfo();
    }
};


#endif //PAYROLLMANEGEMENTSYSTEM_MANAGER_CPP
