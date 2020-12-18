#include <iostream>
#include <string>
#include "Screens/Employee/Employee_Main_Screen.cpp"

int main() {
    EmployeeMainScreen employeeMainScreen;

    switch (employeeMainScreen.displayOperationsValuesAndGetValue()) {
        case SHOW_MY_INFO:
            break;
        default:
            break;
    }

    employeeMainScreen.createEmployee();

    return 0;
}
