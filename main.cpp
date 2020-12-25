#include <iostream>
#include <string>
#include "Screens/Manager/Manager_Main_Screen.cpp"
#include "./Operations/Operations.cpp"
#include "Screens/Employee/Employee_Main_Screen.cpp"

using namespace std;

int displayOperationsValuesAndGetValue(Operations operations, string title) {
    operations.displayOperations(title);

    return operations.getInputValue();
}

int main() {
    EmployeeMainScreen employeeMainScreen;
    ManagerMainScreen managerMainScreen;
    Operations *operations = new Operations(managerMainScreen.getManagerOperations());
    bool isRun = true;

    while (isRun) {
        /*switch (employeeMainScreen.displayOperationsValuesAndGetValue()) {
            case SHOW_MY_INFO:
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
        }*/

        switch (displayOperationsValuesAndGetValue(*operations, "Manager Options")) {
            case SHOW_MANAGER_INFO:
                managerMainScreen.showManagerInfo();
                break;
            case EXIT:
                isRun = false;
                break;
            default:
                break;
        }
    }

    return 0;
}
