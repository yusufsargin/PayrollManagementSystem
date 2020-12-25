//
// Created by yusuf_sargin on 24.12.2020.
//

#ifndef PAYROLLMANEGEMENTSYSTEM_TEAM_CPP
#define PAYROLLMANEGEMENTSYSTEM_TEAM_CPP

#include "Employee.cpp"
#include <vector>

using namespace std;

class Team {
    vector<Employee> employeeList;
public:
    Team() {
        this->employeeList = getEmployeeList();
    }

    vector<Employee> getTeamMembers() {
        Employee employee{"Yusuf", "sargin", 'M', 12312312, "12313"};

        employeeList.push_back(employee);

        return employeeList;
    }

    vector<Employee> getEmployeeList() {
        return employeeList;
    }

    Employee getEmployeeById(int id) {
        Employee returnEmployee{};

        for (Employee employee: employeeList) {
            if (id == employee.getUserId()) {
                returnEmployee = employee;
            }
        }

        return returnEmployee;
    }

    Task getTaskById(int id) {
        Task task;

        for (Employee employee: employeeList) {
            for (Task taskItem: *employee.getTasks()) {
                if (taskItem.getId() == id) {
                    task = taskItem;
                }
            }
        }

        return task;
    }

    vector<Task> getTeamTasks() {
        vector<Task> tasks;

        for (Employee employee : employeeList) {
            for (Task task : *employee.getTasks()) {
                tasks.push_back(task);
            }
        }

        return tasks;
    }

    bool updateTask(Task task) {
        vector<Task> taskList;

        for (Employee employee: employeeList) {
            for (Task taskItem: *employee.getTasks()) {
                if (taskItem.getId() == task.getId()) {
                    taskList.push_back(task);
                }else{
                    taskList.push_back(taskItem);
                }
            }

            employee.setTasks(taskList);
        }

        return true;
    }
};

#endif //PAYROLLMANEGEMENTSYSTEM_TEAM_CPP
