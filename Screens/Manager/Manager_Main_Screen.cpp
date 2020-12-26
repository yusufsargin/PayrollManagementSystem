//
// Created by YUSUF on 26.12.2020.
//

#include "../../Models/Manager.cpp"
#include "../../Models/Task.h"
#include <string>
#include <iostream>

using namespace std;

enum ManagerOperationsTypes {
    SHOW_MANAGER_INFO,
    SHOW_MANAGER_TEAM_MEMBERS,
    SHOW_MANAGER_TEAM_TASKS,
    UPDATE_MANGER_TASK_DUE_DATE,
    ASSIGN_TASK_TO_EMPLOYEE
};

class ManagerMainScreen {
    vector<string> operationsValue{"0.Show Manager Info",
                                   "1.Show Manager Team Members Info",
                                   "2.Show Manager Team Members All Tasks Info",
                                   "3.Exit"};
    Manager *manager;
    Employee *employeeList;
    vector<Employee *> *vectorEmployeeList;
public:
    ManagerMainScreen() {
        this->vectorEmployeeList = new vector<Employee *>;
        manager = new Manager("Yusuf", "Manager", 'M', 123123, "13212312312");

        /*employeeList->push_back(Employee("Ddd","12312",'M',12312,"2312312"));*/
        /* employeeList[0] = Employee("Ddd", "12312", 'M', 12312, "2312312");

         manager->setEmployeeList(employeeList);*/
    }

    ManagerMainScreen(int employeeSize) {
        this->vectorEmployeeList = new vector<Employee *>;
        this->employeeList = new Employee[employeeSize];

        manager = new Manager("Yusuf", "Manager", 'M', 123123, "13212312312");

        collectEmployeeList(employeeSize);

        manager->setTeamMembers(vectorEmployeeList, employeeSize);
    }

    ~ManagerMainScreen() {
        delete manager;
        delete employeeList;
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
            /*Task *task = new Task("Deneme Taskı", "12/12/2020", "Deneme", HARD);
            Employee *employee = new Employee("Deneme", "Deneme", 'M', 123123, "12123123");

            employee->assignNewTaskToEmployee(*task);

            employeeList[i] = *employee;

            delete employee;
            delete task;*/
            Task *task = new Task("Deneme Taskı", "12/12/2020", "Deneme", HARD);
            Employee *employee = new Employee("Deneme", "Deneme", 'M', 123123, "12123123");

            employee->assignNewTaskToEmployee(*task);

            this->vectorEmployeeList->push_back(employee);
        }
    }

    void showMembersAllTasks() {
        manager->showAllTasks();
    }

    void updateTaskDueDate() {
        int taskId = 0;
        string dueDate;
        cout << "Enter Task ID: ";
        cin >> taskId;
        cout << endl;

        cout << "Enter Due Date: ";
        cin >> dueDate;
        cout << endl;

        //manager->updateTaskDueData(taskId, dueDate);
    }

    /*void assignTaskToEmployee() {
        cout << "You can assign task one of them under the table" << endl;

        //showManagerTeamMembers();

        int employeeID = 0;
        cout << "Enter Employee ID: ";
        cin >> employeeID;

        string taskTitle, description, dueDate;
        int taskLevel;

        cout << "Enter Task Title: ";
        cin >> taskTitle;
        cout << endl;

        cout << "Enter Task Due Date: ";
        cin >> taskTitle;
        cout << endl;

        cout << "Enter Task Description: ";
        cin >> taskTitle;
        cout << endl;

        cout << "Enter Task Level" << endl;
        cout << "0.EASY" << endl;
        cout << "1.MEDIUM" << endl;
        cout << "2.HARD" << endl;
        cout << "3.VERY_HARD" << endl;
        cin >> taskLevel;

        Task task{taskTitle, dueDate, description, taskLevel};

        manager->assignTaskToEmployee(employeeID, task);
    }*/

    /* Manager *getManagerFromStorage() {
         Manager *fromStorageManager = new Manager("Yusuf", "Manager", 'M', 123123, "13212312312");

         return fromStorageManager;
     }

     vector<string> getManagerOperations() {
         return operationsValue;
     }

     void showInfo(){
         this->manager->showData();
     }*/

    /*void showManagerInfo() {
        manager->showManagerInfo();
    }

    TaskStatus checkTaskStatus(int id) {
        return manager->checkTaskStatus(id);
    }

    vector<Task> checkTeamTaskList() {
        return manager->checkTeamTaskList();
    }

    bool updateTaskDueDate(int id, string dueDate) {
        return manager->updateTaskDueDate(id, dueDate);
    }

    bool assignTaskToEmployee(int employeeId, Task task) {
        return manager->assignTaskToTeamMember(employeeId, task);
    }

    void showTeamMembers() {
        this->manager->showTeamMembers();
    }*/
};