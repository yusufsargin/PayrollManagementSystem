//
// Created by yusuf_sargin on 24.12.2020.
//

#ifndef PAYROLLMANEGEMENTSYSTEM_MANAGER_CPP
#define PAYROLLMANEGEMENTSYSTEM_MANAGER_CPP

#include "Employee.cpp"
#include "Team.cpp"
#include "Task.h"
#include <vector>

using namespace std;

class Manager : public Employee {
    Team team;
public:
    bool assignTaskToTeamMember(int id, Task task) {

    }

    TaskStatus checkTaskStatus(int id) {
        return team.getTaskById(id).getTaskStatus();
    }

    vector<Task> checkTeamTaskList(){
        return team.getTeamTasks();
    }

    bool updateTaskDueDate(int taskId, string dueDate){
        Task task = team.getTaskById(taskId);

        task.setDueDate(dueDate);

        return team.updateTask(task);
    }

    void showManagerInfo(){
        this->displayMyInfo();
    }
};


#endif //PAYROLLMANEGEMENTSYSTEM_MANAGER_CPP
