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
    SHOW_EMPLOYEE_INFO,
    SHOW_ASSIGNED_TASKS,
    SHOW_DONE_TASKS,
    SHOW_BONUS_AMOUNT,
    UPDATE_TASK_STATUS,
    EXIT
};

class EmployeeMainScreen {
    vector<string> operationsValue{"0.Show My Info",
                                   "1.Show Assigned Tasks",
                                   "2.Show Done Tasks",
                                   "3.Show Bonus Amount",
                                   "4.Update Task Status",
                                   "5.Exit"};
    Employee *employee;
public:
    EmployeeMainScreen() {
        /*this->employee = new Employee("Yusuf", "Sargin", 'M', 123123123, "12321312");*/
        this->employee = getEmployeeValueFromStorage();
        Task task{"Deneme", "19/12/2020", "Deneme Tasks", HARD};

        this->employee->assignNewTaskToEmployee(task);
    }

    ~EmployeeMainScreen() {
        delete employee;
    }

    Employee *getEmployeeValueFromStorage() {
        //Buradaki değerler file dan alınan değerler ile değiştirilecek.

        Employee employeeValue{"Yusuf", "Sargin", 'M', 123123123, "12321312"};

        Employee *employee1 = new Employee("Yusuf", "Sargin", 'M', 123123123, "12321312");

        return employee1;
    }

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

        for (int i = 0; i < employee->getTasks()->size(); i++) {
            if (employee->getTasks()->at(i).getId() == taskId) {
                employee->getTasks()->at(i).setTaskStatus(taskStatus);
            }
        }

        employee->showExistTasks();
    }

    void filterTaskByStatus(TaskStatus taskStatus) {
        employee->showAccordingToStatus(taskStatus);
    }
};