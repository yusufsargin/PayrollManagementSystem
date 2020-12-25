//
// Created by YUSUF on 26.12.2020.
//

#include "../../Models/Manager.cpp"

enum ManagerOperationsTypes {
    SHOW_MANAGER_INFO
};

class ManagerMainScreen {
    vector<string> operationsValue{"0.Show My Info",
                                   "1.Show Assigned Tasks",
                                   "2.Show Done Tasks",
                                   "3.Show Bonus Amount",
                                   "4.Update Task Status",
                                   "5.Exit"};
    Manager *manager;
public:
    ManagerMainScreen() {
        manager = new Manager;
    }

    ~ManagerMainScreen() {
        delete manager;
    }

    vector<string> getManagerOperations() {
        return operationsValue;
    }

    void showManagerInfo(){
        manager->showManagerInfo();
    }
};