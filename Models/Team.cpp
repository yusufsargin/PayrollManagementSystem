//
// Created by yusuf_sargin on 24.12.2020.
//

#ifndef PAYROLLMANEGEMENTSYSTEM_TEAM_CPP
#define PAYROLLMANEGEMENTSYSTEM_TEAM_CPP

#include "Employee.cpp"
#include <vector>

using namespace std;

class Team {
    Employee *employeeList;
    int employeeSize = 0;
public:

    Team() {
        this->employeeList = new Employee[employeeSize];
    }

    Team(Employee list[], int listSize) {
        collectTeamMembersFromStorage(list, listSize);
    }

    Team(Team const &obj) {
        delete employeeList;
    }

    ~Team() {
        delete employeeList;
    }

    void collectTeamMembersFromStorage(Employee list[], int employeeSize) {
        this->employeeSize = employeeSize;
        this->employeeList = new Employee[employeeSize];

        for (int i = 0; i < employeeSize; ++i) {
            employeeList[i] = list[i];
        }
    }

    void showMembersInfo() {
        employeeList[0].headerOfInfoTable();
        for (int i = 0; i < employeeSize; i++) {
            employeeList[i].displayMyInfo(true);
        }
    }

    void showMembersTaskList() {
        for (int i = 0; i < employeeSize; i++) {
            employeeList[i].showExistTasks();
        }
    }

    /* vector<Employee> getEmployeeList() {
         return *employeeList;
     }

     void setEmployeeList(vector<Employee> employeeList){
         this->employeeList = &employeeList;
     }

     void showEmployeeInfo() {
         cout << "Show Employee" << endl;
         cout << employeeList->at(0).getFirstName() << endl;
         *//*for (Employee employee:*employeeList) {
            employee.displayMyInfo();
        }*//*
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
    }*/
};

#endif //PAYROLLMANEGEMENTSYSTEM_TEAM_CPP
