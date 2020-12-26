//
// Created by YUSUF on 26.12.2020.
//

#include "../../Models/Manager.cpp"

enum ManagerOperationsTypes {
    SHOW_MANAGER_INFO,
    SHOW_MANAGER_TEAM_MEMBERS,
    SHOW_MANAGER_TEAM_TASKS
};

class ManagerMainScreen {
    vector<string> operationsValue{"0.Show Manager Info",
                                   "1.Show Manager Team Members Info",
                                   "2.Show Manager Team Members All Tasks Info",
                                   "3.Exit"};
    Manager *manager;
    Employee *employeeList;
public:
    ManagerMainScreen() {
        manager = new Manager("Yusuf", "Manager", 'M', 123123, "13212312312");

        /*employeeList->push_back(Employee("Ddd","12312",'M',12312,"2312312"));*/
        /* employeeList[0] = Employee("Ddd", "12312", 'M', 12312, "2312312");

         manager->setEmployeeList(employeeList);*/
    }

    ManagerMainScreen(int employeeSize) {
        this->employeeList = new Employee[employeeSize];

        manager = new Manager("Yusuf", "Manager", 'M', 123123, "13212312312");

        collectEmployeeList(employeeSize);

        manager->setTeamMembers(employeeList, employeeSize);
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
            Employee employee{"Deneme", "Deneme", 'M', 123123, "12123123"};

            employeeList[i] = employee;
        }
    }

    void showMembersAllTasks() {
        manager->showAllTasks();
    }

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