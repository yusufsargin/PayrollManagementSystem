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
    vector<Employee *> *employeeVector;
    int employeeSize = 0;
public:

    Team() {
        this->employeeList = new Employee[employeeSize];
        this->employeeVector = new vector<Employee *>();
    }

    Team(Employee list[], int listSize) {
        this->employeeVector = new vector<Employee *>();
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

    void collectTeamMembersFromStorageVector(vector<Employee *> &list, int employeeSize) {
        for (Employee *employee:list) {
            this->employeeVector->push_back(employee);
        }
    }

    void showMembersInfo() {
        for (Employee *employee:*employeeVector) {
            employee->displayMyInfo();
        }
    }

    void showMembersTaskList() {
        for (Employee *employee:*employeeVector) {
            employee->showExistTasks();
        }
    }

    void updateTaskDueDate(int id, string dueDate) {
        /*for (int i = 0; i < employeeSize; i++) {
            for (int j = 0; j < employeeList[i].getTasks()->size(); i++) {
                if (employeeList[i].getTasks()->at(j)->getId() == id) {
                    employeeList[i].getTasks()->at(j)->setDueDate(dueDate);
                }
            }
        }*/
        for (Employee *employee: *employeeVector) {
            for (Task *task: *employee->getTasks()) {
                if (task->getId() == id) {
                    task->setDueDate(dueDate);
                }
            }
        }

        showMembersTaskList();
    }

    void assignTaskToEmployee(int employeeID, Task task) {
        /*for (int i = 0; i < employeeSize; ++i) {
            if (employeeList[i].getUserId() == employeeID) {
                employeeList[i].assignNewTaskToEmployee(task);

                employeeList[i].showExistTasks();
            }
        }*/
        for(Employee *employee:*employeeVector){
            if(employee->getUserId()==employeeID){
                employee->assignNewTaskToEmployee(task);

                employee->showExistTasks();
            }
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
