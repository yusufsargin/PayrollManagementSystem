//
// Created by YUSUF on 27.12.2020.
//

#include <vector>
#include <fstream>
#include "Employee.cpp"
#include "ScreenType.h"

class Storage {
    vector<Employee *> *employeeList;
public:
    vector<Employee *> *getEmployeeList() {

        return employeeList;
    }

    vector<Task *> getTasks() {

    }

    SCREEN auth() {
        SCREEN screen = IN_VALID_SCREEN;
        string userId, password;

        cout << "Enter your user ID: ";
        cin >> userId;
        cout << "Enter your password: ";
        cin >> password;

        string PeopleId, EmployeeId, HRId, ManagerId, Pass;
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
};