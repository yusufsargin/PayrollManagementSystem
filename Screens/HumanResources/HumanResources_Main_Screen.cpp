//
// Created by YUSUF on 28.12.2020.
//

#include "../../Operations/Operations.cpp"
#include "../../Models/Storage.cpp"
#include "../../Models/Employee.cpp"
#include "string"

using namespace std;

enum HumanResourcesOperationsTypes {
    ADD_NEW_EMPLOYEE = 1,
    REMOVE_EXIST_EMPLOYEE,
    SET_HOLIDAYS,
    DETECT_HOLIDAYS
};

class HumanResourcesMainScreen {
    vector<string> operationsValue{
            "0.Exit",
            "1.Add New Employee",
            "2.Remove Exist Employee"
            "3.Set Holidays"
    };
    vector<Employee *> *employeeList;
public:
    HumanResourcesMainScreen() {
        this->employeeList = new vector<Employee *>;
    }

    HumanResourcesMainScreen(vector<Employee *> *employeeList) {
        this->employeeList = employeeList;
    }


    void detectHolidays(int userID) {

    }

    void addNewEmployee(int userId,) {

    }

    void updateEmployee() {

    }

    void checkSalary() {

    }

    void deleteEmployee(int userId) {

    }
};