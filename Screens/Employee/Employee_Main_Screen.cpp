//
// Created by YUSUF on 17.12.2020.
//

#include <iostream>
#include <string>
#include <vector>
#include "../../Models/Employee.cpp"
#include "../../Models/Task.h"

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
    SHOW_EMPLOYEE_INFO = 1,
    SHOW_ASSIGNED_TASKS,
    SHOW_DONE_TASKS,
    SHOW_BONUS_AMOUNT,
    UPDATE_TASK_STATUS
};

class EmployeeMainScreen {
    vector<string> operationsValue{
            "0.Exit",
            "1.Show My Info",
            "2.Show Assigned Tasks",
            "3.Show Done Tasks",
            "4.Show Bonus Amount",
            "5.Update Task Status"};
    Employee *employee;
public:
    EmployeeMainScreen(Employee *employeeItem) {
        this->employee = employeeItem;
        /*Task *task = new Task(100, "Deneme", "19/12/2020", "Deneme Tasks", HARD);

        this->employee->assignNewTaskToEmployee(*task);*/

        /* delete task;*/
    }

    ~EmployeeMainScreen() {
        delete employee;
    }

    /*Employee *getEmployeeValueFromStorage() {
        //Buradaki değerler file dan alınan değerler ile değiştirilecek.


        Employee *employee1 = new Employee(100, "Yusuf", "Sargin", 'M', 123123123, "12321312",0,0);

        return employee1;
    }*/

    vector<string> getEmployeeOperations() {
        return operationsValue;
    }

    void showEmployeeInfo() {
        cout << "---------------------------------" << endl;
        this->employee->displayMyInfo();
        cout << "---------------------------------" << endl;
    }

    void updateMyInfo(Employee employeeData) {
        cout << "Enter Employee Info" << endl;

        this->employee = &employeeData;
    }

    void showAssignedTasks() {
        cout << "Your Tasks" << endl;

        employee->showExistTasks();
    }

    void showBonusAmount() {
        cout << "Your Bonus Amount: " << employee->getBonus() << endl;
    }

    void updateTaskStatus() {
        employee->showExistTasks();

        int taskId = 0;
        int status = 0;
        TaskStatus taskStatus;

        cout << "Enter task id you want to update: ";
        cin >> taskId;
        cout << endl;

        cout << "0.WAITING" << endl;
        cout << "1.IN_PROGRESS" << endl;
        cout << "2.DONE" << endl;

        cout << "Enter task status: ";
        cin >> status;
        cout << endl;

        switch (status) {
            case WAITING:
                taskStatus = WAITING;
                break;
            case IN_PROGRESS:
                taskStatus = IN_PROGRESS;
                break;
            case DONE:
                taskStatus = DONE;
                break;
            default:
                cout << "Value is not valid" << endl;
        }

        if (employee->getTasks() != nullptr) {
            for (int i = 0; i < employee->getTasks()->size(); i++) {
                if (employee->getTasks()->at(i)->getId() == taskId) {
                    employee->getTasks()->at(i)->setTaskStatus(taskStatus);
                }
            }
        }

        employee->showExistTasks();
    }

    void filterTaskByStatus(TaskStatus taskStatus) {
        employee->showAccordingToStatus(taskStatus);
    }
};