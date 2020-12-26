//
// Created by YUSUF on 26.12.2020.
//

#include "../../Models/Manager.cpp"

enum ManagerOperationsTypes {
    SHOW_MANAGER_INFO,
    SHOW_MANAGER_TEAM_MEMBERS
};

class ManagerMainScreen {
    vector<string> operationsValue{"0.Show My Info",
                                   "1.Check Task Status",
                                   "2.Check Team Status",
                                   "3.Update Task Due Date",
                                   "4.Delete Task",
                                   "5.Assign Task",
                                   "4.Exit"};
    Manager *manager;
public:
    ManagerMainScreen() {
        manager = getManagerFromStorage();
    }

    ~ManagerMainScreen() {
        delete manager;
    }

    Manager *getManagerFromStorage() {
        Manager *fromStorageManager = new Manager("Yusuf", "Manager", 'M', 123123, "13212312312");

        return fromStorageManager;
    }

    vector<string> getManagerOperations() {
        return operationsValue;
    }

    void showManagerInfo() {
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

    void showTeamMembers(){
        manager->showTeamMembers();
    }
};