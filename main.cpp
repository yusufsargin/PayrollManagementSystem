#include <iostream>
#include <string>
#include "Screens/Employee/Employee_Main_Screen.cpp"

int main() {
    EmployeeMainScreen employeeMainScreen;
    bool isRun = true;

    while (isRun) {
        switch (employeeMainScreen.displayOperationsValuesAndGetValue()) {
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
        }
    }

    return 0;
}
