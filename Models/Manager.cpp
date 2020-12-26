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

    void setTeamMembers(Employee list[], int listSize) {
        team->collectTeamMembersFromStorage(list, listSize);
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

    /*void showTeamMembers() {
        *//*cout << "SHOW" << endl;
           for (auto i = this->employeeList->cbegin(); i != employeeList->cend(); ++i) {
               cout<< i->getFirstName() << endl;
       }*//*

        for (int i = 0; i < employeeListSize; ++i) {
            employeeList[i].displayMyInfo();
        }
    }*/

    void showManagerInfo() {
        this->displayMyInfo();
    }

    /* bool assignTaskToTeamMember(int id, Task task) {
         return team->assignTaskToEmployee(id, task);
     }

     TaskStatus checkTaskStatus(int id) {
         return team->getTaskById(id).getTaskStatus();
     }

     vector<Task> checkTeamTaskList() {
         return team->getTeamTasks();
     }

     bool updateTaskDueDate(int taskId, string dueDate) {
         Task task = team->getTaskById(taskId);

         task.setDueDate(dueDate);

         return team->updateTask(task);
     }

     void showManagerInfo() {
         this->displayMyInfo();
     }

     void showTeamMembers() {
         cout << "-----------------------" << endl;

         team->showEmployeeInfo();

         cout << "-----------------------" << endl;
     }*/
};


#endif //PAYROLLMANEGEMENTSYSTEM_MANAGER_CPP
