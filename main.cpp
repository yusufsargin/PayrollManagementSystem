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

void ManagerOperations(Operations *operations, ManagerMainScreen *managerMainScreen, bool &isRun, Storage &storage) {
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
            storage.setEmployeeList(managerMainScreen->getEmployeeListFromMangerScreen());
            isRun = false;
            break;
        default:
            break;
    }
}

void HumanResourcesOperations(Operations *operations, HumanResourcesMainScreen *humanResourcesMainScreen, bool &isRun,
                              Storage &storage) {
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
        case HR_SHOW_ALL_EMPLOYEE:
            humanResourcesMainScreen->showAllEmployees();
            break;
        case EXIT:
            storage.setEmployeeList(humanResourcesMainScreen->getEmployeeList());
            isRun = false;
            break;
        default:
            break;
    }
}

void matchAccountToEmployee(vector<Employee *> &employeeList, vector<Account *> *accountList) {
    for (Employee *employee:employeeList) {
        for (Account *account:*accountList) {
            if (account->getId() == employee->getUserId()) {
                employee->setAccount(account);
            }
        }
    }
}

int main() {
    Storage storage;

    vector<Employee *> *employeeList = storage.getEmployeeList();
    vector<Account *> *accountList = storage.getAccounts();

    matchAccountToEmployee(*employeeList, accountList);

    employeeList->at(0)->headerOfInfoTable();

    cout << "Employee Size " <<employeeList->size() <<endl;

    for (int i=0;i<employeeList->size();i++) {
        employeeList->at(i)->displayMyInfo(true);
    }

    EmployeeMainScreen *employeeMainScreen = nullptr;
    ManagerMainScreen *managerMainScreen = nullptr;
    HumanResourcesMainScreen *humanResourcesMainScreen = nullptr;
    Operations *operations = nullptr;

    bool isRun = true;
    SCREEN screen = storage.auth();

    if (screen == EMPLOYEE_SCREEN) {
        employeeMainScreen = new EmployeeMainScreen(employeeList->at(0));
        operations = new Operations(employeeMainScreen->getEmployeeOperations());
    } else if (screen == MANAGER_SCREEN) {
        managerMainScreen = new ManagerMainScreen(employeeList);
        operations = new Operations(managerMainScreen->getManagerOperations());
    } else if (screen == HR_SCREEN) {
        humanResourcesMainScreen = new HumanResourcesMainScreen(employeeList);
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
                ManagerOperations(operations, managerMainScreen, isRun, storage);
                break;
            case HR_SCREEN:
                HumanResourcesOperations(operations, humanResourcesMainScreen, isRun, storage);
                break;
            default:
                break;
        }
    }

    delete managerMainScreen;
    delete employeeMainScreen;
    delete operations;
    delete humanResourcesMainScreen;
    delete [] accountList;
    delete [] employeeList;

    return 0;
}
