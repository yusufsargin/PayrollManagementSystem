//
// Created by yusuf_sargin on 24.12.2020.
//

#ifndef PAYROLLMANEGEMENTSYSTEM_TEAM_CPP
#define PAYROLLMANEGEMENTSYSTEM_TEAM_CPP

#include "Employee.cpp"
#include <vector>

using namespace std;

class Team {
    vector<Employee> *employeeList;
public:
    vector<Employee> getTeamMembers() {
        vector<Employee> list;

        Employee employee{"Yusuf", "sasdfsdfsrgin", 'M', 12312312, "12313"};

        employee.displayMyInfo();
        list.push_back(employee);

        return list;
    }

    Team() {
        Employee employee{"Yusuf", "sasdfsdfsrgin", 'M', 12312312, "12313"};
        vector<Employee> list{employee};

        this->employeeList = new vector<Employee>(list);
    }

    Team(Team const &obj) {
        delete employeeList;

        this->employeeList = new vector<Employee>;

        this->employeeList = obj.employeeList;
    }

    ~Team() {
        delete employeeList;
    }

    vector<Employee> getEmployeeList() {
        return *employeeList;
    }

    void showEmployeeInfo() {
        for (Employee employee: *employeeList) {
            employee.displayMyInfo();
        }
    }

    Employee getEmployeeById(int id) {
        Employee returnEmployee{};

        for (Employee employee: *employeeList) {
            if (id == employee.getUserId()) {
                returnEmployee = employee;
            }
        }

        return returnEmployee;
    }

    void setEmployeeData(Employee employee) {
        for (int i = 0; i < employeeList->size(); i++) {
            if (employee.getUserId() == employeeList->at(i).getUserId()) {
                employeeList->at(i) = employee;
            }
        }
    }

    bool assignTaskToEmployee(int employeeID, Task task) {
        Employee employee = getEmployeeById(employeeID);

        employee.assignNewTaskToEmployee(task);

        setEmployeeData(employee);

        return true;
    }

    Task getTaskById(int id) {
        Task task;

        for (Employee employee: *employeeList) {
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

        for (Employee employee : *employeeList) {
            for (Task task : *employee.getTasks()) {
                tasks.push_back(task);
            }
        }

        return tasks;
    }

    bool updateTask(Task task) {
        vector<Task> taskList;

        for (Employee employee: *employeeList) {
            for (Task taskItem: *employee.getTasks()) {
                if (taskItem.getId() == task.getId()) {
                    taskList.push_back(task);
                } else {
                    taskList.push_back(taskItem);
                }
            }

            employee.setTasks(taskList);
        }

        return true;
    }
};

#endif //PAYROLLMANEGEMENTSYSTEM_TEAM_CPP
