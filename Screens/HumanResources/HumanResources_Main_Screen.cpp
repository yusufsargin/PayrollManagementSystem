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
    UPDATE_EMPLOYEE,
    CHECK_SALARY,
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


    void detectHolidays() {

    }

    void addNewEmployee() {

    }

    void updateEmployee() {

    }

    void checkSalary() {

    }

    void deleteEmployee() {

    }

    vector<string> getHROperations() {
        return operationsValue;
    }

    vector<Employee *> *getEmployeeList() const {
        return employeeList;
    }

    void setEmployeeList(vector<Employee *> *employeeList) {
        HumanResourcesMainScreen::employeeList = employeeList;
    }
};