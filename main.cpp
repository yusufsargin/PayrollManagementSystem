#include <iostream>
#include <string>
#include <fstream>
#include "Models/Storage.cpp"
#include "Screens/Manager/Manager_Main_Screen.cpp"
#include "./Operations/Operations.cpp"
#include "Screens/Employee/Employee_Main_Screen.cpp"

using namespace std;


int displayOperationsValuesAndGetValue(Operations operations, string title) {
    operations.displayOperations(title);

    return operations.getInputValue();
}

void EmployeeOperations(Operations *operations, EmployeeMainScreen *employeeMainScreen, bool &isRun) {
    switch (displayOperationsValuesAndGetValue(*operations, "Employee Operations")) {
        case SHOW_EMPLOYEE_INFO:
            employeeMainScreen->showEmployeeInfo();
            break;
        case SHOW_ASSIGNED_TASKS:
            employeeMainScreen->showAssignedTasks();
            break;
        case SHOW_BONUS_AMOUNT:
            employeeMainScreen->showBonusAmount();
            break;
        case UPDATE_TASK_STATUS:
            employeeMainScreen->updateTaskStatus();
            break;
        case SHOW_DONE_TASKS:
            employeeMainScreen->filterTaskByStatus(DONE);
            break;
        case EXIT:
            isRun = false;
            break;
        default:
            break;
    }
}

void ManagerOperations(Operations *operations, ManagerMainScreen *managerMainScreen, bool &isRun) {
    switch (displayOperationsValuesAndGetValue(*operations, "Manager Options")) {
        case SHOW_MANAGER_INFO:
            managerMainScreen->showManagerInfo();
            break;
        case SHOW_MANAGER_TEAM_MEMBERS:
            managerMainScreen->showManagerTeamMembers();
            break;
        case SHOW_MANAGER_TEAM_TASKS:
            managerMainScreen->showMembersAllTasks();
            break;
        case UPDATE_MANGER_TASK_DUE_DATE:
            managerMainScreen->updateTaskDueDate();
            break;
        case ASSIGN_TASK_TO_EMPLOYEE:
            managerMainScreen->assignTaskToEmployee();
            break;
        case EXIT:
            isRun = false;
            break;
        default:
            break;
    }
}

SCREEN auth() {
    SCREEN screen = IN_VALID_SCREEN;
    string userId, password;

    cout << "Enter your user ID: ";
    cin >> userId;
    cout << "Enter your password: ";
    cin >> password;

    string PeopleId, EmployeeId, HRId, ManagerId, Pass, empty;
    string line;

    ifstream readWordPeople("D:\\yukseklisansLab\\241\\yedek\\PayrollManagementSystem\\People.txt");
    while (getline(readWordPeople, line)) {
        readWordPeople >> PeopleId;
        cout << PeopleId << endl;

        readWordPeople >> Pass;
        //cout << Pass<<endl;

        if (userId == PeopleId && password == Pass) {
            cout << "Enterance is successful!" << endl;

            ifstream readWordEmployee("D:\\yukseklisansLab\\241\\yedek\\PayrollManagementSystem\\Employee.txt");
            while (getline(readWordEmployee, line)) {
                readWordEmployee >> EmployeeId;

                if (userId == EmployeeId) {
                    screen = EMPLOYEE_SCREEN;
                }
            }
            readWordEmployee.close();


            ifstream readWordHR("D:\\yukseklisansLab\\241\\yedek\\PayrollManagementSystem\\HR.txt");
            while (getline(readWordHR, line)) {
                readWordHR >> HRId;
                //cout << HRId << endl;

                if (userId == HRId) {
                    if (userId == HRId) {
                        screen = HR_SCREEN;
                    }
                }
                readWordHR.close();

                break;
            }

        }
        readWordPeople.close();

    }

    cout << "SCREEEEEEEN " <<screen << endl;
    return screen;
}

int main() {
    Storage storage;

    storage.getTasks();
    EmployeeMainScreen *employeeMainScreen = nullptr;
    ManagerMainScreen *managerMainScreen = nullptr;
    Operations *operations = nullptr;
    bool isRun = true;
    SCREEN screen = auth();
/*
    cout << "Enter Screen Type:" << endl;
    cout << "0.Employee Screen" << endl;
    cout << "1.Manager Screen" << endl;

    cin >> screen;*/

    if (screen == EMPLOYEE_SCREEN) {
        employeeMainScreen = new EmployeeMainScreen;
        operations = new Operations(employeeMainScreen->getEmployeeOperations());
    } else if (screen == MANAGER_SCREEN) {
        managerMainScreen = new ManagerMainScreen(1);
        operations = new Operations(managerMainScreen->getManagerOperations());
    } else if (screen == IN_VALID_SCREEN) {
        isRun = false;
    }

    while (isRun) {
        switch (screen) {
            case EMPLOYEE_SCREEN:
                EmployeeOperations(operations, employeeMainScreen, isRun);
                break;
            case MANAGER_SCREEN:
                ManagerOperations(operations, managerMainScreen, isRun);
                break;
            default:
                break;
        }
        /* *//*switch (displayOperationsValuesAndGetValue(*operations,"Employee Operations")) {
            case SHOW_EMPLOYEE_INFO:
                employeeMainScreen.showEmployeeInfo();
                break;
            case SHOW_ASSIGNED_TASKS:
                employeeMainScreen.showAssignedTasks();
                break;
            case SHOW_BONUS_AMOUNT:
                employeeMainScreen.showBonusAmount();
                break;
            case UPDATE_TASK_STATUS:
                employeeMainScreen.updateTaskStatus();
                break;
            case SHOW_DONE_TASKS:
                employeeMainScreen.filterTaskByStatus(DONE);
                break;
            case EXIT:
                isRun = false;
                break;
            default:
                break;
        }*//*
        EmployeeOperations(operations, employeeMainScreen, isRun);
        switch (displayOperationsValuesAndGetValue(*operations, "Manager Options")) {
            case SHOW_MANAGER_INFO:
                managerMainScreen.showManagerInfo();
                break;
            case SHOW_MANAGER_TEAM_MEMBERS:
                managerMainScreen.showManagerTeamMembers();
                break;
            case SHOW_MANAGER_TEAM_TASKS:
                managerMainScreen.showMembersAllTasks();
                break;
            case UPDATE_MANGER_TASK_DUE_DATE:
                managerMainScreen.updateTaskDueDate();
                break;
            case ASSIGN_TASK_TO_EMPLOYEE:
                managerMainScreen.assignTaskToEmployee();
                break;
            case EXIT:
                isRun = false;
                break;
            default:
                break;
        }*/
    }

    delete managerMainScreen;
    delete employeeMainScreen;
    delete operations;

    return 0;
}
