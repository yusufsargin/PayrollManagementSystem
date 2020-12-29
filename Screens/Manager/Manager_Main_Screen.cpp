//
// Created by YUSUF on 26.12.2020.
//

#include "../../Models/Manager.cpp"
#include "../../Models/Task.h"
#include <string>
#include <iostream>

using namespace std;

enum ManagerOperationsTypes {
    EXIT = 0,
    SHOW_MANAGER_INFO = 1,
    SHOW_MANAGER_TEAM_MEMBERS,
    SHOW_MANAGER_TEAM_TASKS,
    UPDATE_MANGER_TASK_DUE_DATE,
    ASSIGN_TASK_TO_EMPLOYEE,
};

class ManagerMainScreen {
    vector<string> operationsValue{
            "0.EXIT",
            "1.Show Manager Info",
            "2.Show Manager Team Members Info",
            "3.Show Manager Team Members All Tasks Info",
            "4.Change Task Due Date",
            "5.Assign Task To Employee"};
    Manager *manager;
    vector<Employee *> *vectorEmployeeList;
public:
    ManagerMainScreen() {
        this->vectorEmployeeList = new vector<Employee *>;
        //manager = new Manager(001, "Yusuf", "Manager", 'M', 123123, "13212312312");
    }

    ManagerMainScreen(int employeeSize) {
        this->vectorEmployeeList = new vector<Employee *>;

        //manager = new Manager(001, "Yusuf", "Manager", 'M', 123123, "13212312312");

        collectEmployeeList(employeeSize);

        manager->setTeamMembers(vectorEmployeeList, employeeSize);
    }

    ~ManagerMainScreen() {
        delete manager;
    }

    void showManagerInfo() {
        this->manager->showManagerInfo();
    }

    void showManagerTeamMembers() {
        manager->showTeamMembers();
    }

    vector<string> getManagerOperations() {
        return operationsValue;
    }

    void collectEmployeeList(int size) {
        for (int i = 0; i < size; i++) {
            Task *task = new Task(1000, "Deneme Taskı", "12/12/2020", "Deneme", HARD);
           /* Employee *employee = new Employee(100, "Deneme", "Deneme", 'M', 123123, "12123123",0,0);

            employee->assignNewTaskToEmployee(*task);

            this->vectorEmployeeList->push_back(employee);*/
        }
    }

    void showMembersAllTasks() {
        manager->showAllTasks();
    }

    void updateTaskDueDate() {
        manager->showAllTasks();
        int taskId = 0;
        string dueDate;
        cout << "Enter Task ID: ";
        cin >> taskId;
        cout << endl;

        cout << "Enter Due Date: ";
        cin >> dueDate;
        cout << endl;

        manager->updateTaskDueData(taskId, dueDate);
    }

    void assignTaskToEmployee() {
        cout << "You can assign task one of them under the table" << endl;

        showManagerTeamMembers();

        int employeeID = 0;
        cout << "Enter Employee ID: ";
        cin >> employeeID;

        string taskTitle, description, dueDate;
        int taskLevel;

        cout << "Enter Task Title: ";
        cin >> taskTitle;
        cout << endl;

        cout << "Enter Task Due Date: ";
        cin >> dueDate;
        cout << endl;

        cout << "Enter Task Description: ";
        cin >> description;
        cout << endl;

        cout << "Enter Task Level" << endl;
        cout << "0.EASY" << endl;
        cout << "1.MEDIUM" << endl;
        cout << "2.HARD" << endl;
        cout << "3.VERY_HARD" << endl;
        cin >> taskLevel;

        Task task{100, taskTitle, dueDate, description, taskLevel};

        manager->assignTaskToEmployee(employeeID, task);
    }
};