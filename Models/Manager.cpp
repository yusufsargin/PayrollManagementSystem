//
// Created by yusuf_sargin on 24.12.2020.
//

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
    Team *team;
public:
    Manager() : Employee() {
        this->team = new Team();
    }

    Manager(string firstName, string lastName, char sex, int tc, string phone) : Employee(firstName, lastName, sex, tc,
                                                                                          phone) {
    }

    Manager(Manager const &obj) {
        delete team;
        team = new Team();
    }

    ~Manager() {
        delete team;
    }

    bool assignTaskToTeamMember(int id, Task task) {
        return team->assignTaskToEmployee(id,task);
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

    void showTeamMembers(){
        cout << "-----------------------" << endl;

        team->showEmployeeInfo();

        cout << "-----------------------" << endl;
    }
};


#endif //PAYROLLMANEGEMENTSYSTEM_MANAGER_CPP
