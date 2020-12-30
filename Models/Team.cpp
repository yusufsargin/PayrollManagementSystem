//
// Created by yusuf_sargin on 24.12.2020.
//

#ifndef PAYROLLMANEGEMENTSYSTEM_TEAM_CPP
#define PAYROLLMANEGEMENTSYSTEM_TEAM_CPP

#include "Employee.cpp"
#include <vector>

using namespace std;

class Team {
    vector<Employee *> *employeeVector;
    int employeeSize = 0;
public:

    Team() {
        this->employeeVector = new vector<Employee *>();
    }

    Team(vector<Employee *> *employeeList) {
        this->employeeVector = employeeList;
    }

    Team(Team const &obj) {
        delete employeeVector;

        this->employeeVector = new vector<Employee *>(*obj.employeeVector);

    }

    ~Team() {
        delete employeeVector;
    }

    void collectTeamMembersFromStorageVector(vector<Employee *> &list, int employeeSize) {
        for (Employee *employee:list) {
            this->employeeVector->push_back(employee);
        }
    }

    void showMembersInfo() {
        for (Employee *employee:*employeeVector) {
            if (employee->getDepartment() != Sales_Manager && employee->getDepartment() != Human_Resources) {
                cout << "-------USER " << employee->getUserId() << " --------" << endl;
                employee->displayMyInfo();
            }
        }
    }

    void showMembersTaskList() {
        for (Employee *employee:*employeeVector) {
            if (employee->getDepartment() != Sales_Manager && employee->getDepartment() != Human_Resources) {
                employee->showExistTasks();
            }
        }
    }

    void updateTaskDueDate(int id, string dueDate) {
        for (Employee *employee: *employeeVector) {
            if (employee->getTasks() != nullptr) {
                for (Task *task: *employee->getTasks()) {
                    if (task->getId() == id) {
                        task->setDueDate(dueDate);
                    }
                }
            }
        }

        showMembersTaskList();
    }

    void assignTaskToEmployee(int employeeID, Task *task) {
        for (Employee *employee:*employeeVector) {
            if (employee->getUserId() == employeeID) {
                if (employee->getTasks() != nullptr) {
                    employee->assignNewTaskToEmployee(task);

                    employee->showExistTasks();
                } else {
                    cout << "Wrong Operation" << endl;
                }
            }
        }
    }
};

#endif //PAYROLLMANEGEMENTSYSTEM_TEAM_CPP
