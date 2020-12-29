#include <iostream>
#include <string>
#include <fstream>
#include "./Models/Storage.cpp"
#include "./Screens/Manager/Manager_Main_Screen.cpp"
#include "./Operations/Operations.cpp"
#include "./Screens/Employee/Employee_Main_Screen.cpp"
#include "./Screens/HumanResources/HumanResources_Main_Screen.cpp"

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

void HumanResourcesOperations(Operations *operations, HumanResourcesMainScreen *humanResourcesMainScreen, bool &isRun) {
    switch (displayOperationsValuesAndGetValue(*operations, "´Human Resources Options")) {
        case ADD_NEW_EMPLOYEE:
            humanResourcesMainScreen->addNewEmployee();
            break;
        case DETECT_HOLIDAYS:
            humanResourcesMainScreen->detectHolidays();
            break;
        case REMOVE_EXIST_EMPLOYEE:
            humanResourcesMainScreen->deleteEmployee();
            break;
        case UPDATE_EMPLOYEE:
            humanResourcesMainScreen->updateEmployee();
            break;
        case CHECK_SALARY:
            humanResourcesMainScreen->checkSalary();
            break;
        case EXIT:
            isRun = false;
            break;
        default:
            break;
    }
}

int main() {
    Storage storage;

    storage.getTasks();

    vector<Account *> *account = storage.getAccounts();
    vector<Employee *> *employeeList = storage.getEmployeeList();

    account->push_back(new Account(100, 100, 0));

    storage.setStorageAccount(account);

    EmployeeMainScreen *employeeMainScreen = nullptr;
    ManagerMainScreen *managerMainScreen = nullptr;
    HumanResourcesMainScreen *humanResourcesMainScreen = nullptr;

    Operations *operations = nullptr;
    bool isRun = true;
    SCREEN screen = storage.auth();
/*
    cout << "Enter Screen Type:" << endl;
    cout << "0.Employee Screen" << endl;
    cout << "1.Manager Screen" << endl;

    cin >> screen;*/

    if (screen == EMPLOYEE_SCREEN) {
        employeeMainScreen = new EmployeeMainScreen(employeeList->at(0));
        operations = new Operations(employeeMainScreen->getEmployeeOperations());
    } else if (screen == MANAGER_SCREEN) {
        managerMainScreen = new ManagerMainScreen(1);
        operations = new Operations(managerMainScreen->getManagerOperations());
    } else if (screen == HR_SCREEN) {
        humanResourcesMainScreen = new HumanResourcesMainScreen();
        operations = new Operations(humanResourcesMainScreen->getHROperations());
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
            case HR_SCREEN:
                HumanResourcesOperations(operations, humanResourcesMainScreen, isRun);
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
    delete humanResourcesMainScreen;

    return 0;
}
