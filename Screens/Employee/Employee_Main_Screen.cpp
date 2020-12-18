//
// Created by YUSUF on 17.12.2020.
//

#include <iostream>
#include <string>
#include <vector>
#include "../../Operations/Operations.cpp"
#include "../../Models/Employee.h"

/*
Önüne Menu çıkacak
1.Bilgilerini görüntüle
2.Bilgilerini güncelle
3.Tasklarımı görüntüle
4.Biten taskımın bilgilerini gir
5.Bonus mikarımı görüntüle
*/

using namespace std;

enum EmployeeOperationsTypes {
    SHOW_MY_INFO,
    UPDATE_MY_INFO,
    SHOW_ASSIGNED_TASKS,
    SHOW_DONE_TASKS,
    SHOW_BONUS_AMOUNT,
    EXIT
};

class EmployeeMainScreen {
    vector<string> operationsValue{"0.Show My Info",
                                   "1.Update My Info",
                                   "2.Show Assigned Tasks",
                                   "3.Show Done Tasks",
                                   "4.Show Bonus Amount",
                                   "5.Exit"};
    Employee *employee;
public:
    int displayOperationsValuesAndGetValue() {
        Operations operations{operationsValue};

        operations.displayOperations("Employee");

        return operations.getInputValue();
    }

    void createEmployee() {
        employee = new Employee("Yusuf", "Sargın", 'M', 123123, "12312312");

        employee->displayMyInfo();

        delete employee;
    }
};