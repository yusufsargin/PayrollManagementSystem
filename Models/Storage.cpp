//
// Created by YUSUF on 27.12.2020.
//

#include <vector>
#include <iostream>
#include <fstream>
#include "Task.h"
#include "Employee.cpp"
#include "ScreenType.h"

using namespace std;

class Storage {
    vector<Employee *> *employeeList;
public:
    vector<Employee *> *getEmployeeList() {

        return employeeList;
    }

    TaskStatus convertTaskStatusTypes(int taskStatus) {
        switch (taskStatus) {
            case 0:
                return WAITING;
            case 1:
                return IN_PROGRESS;
            case 2:
                return DONE;
            default:
                return IN_VALID_STATUS;
        }
    }

    TaskLevels convertTaskLevelTypes(int taskLevels) {
        switch (taskLevels) {
            case 0:
                return EASY;
            case 1:
                return MEDIUM;
            case 2:
                return HARD;
            case 3:
                return VERY_HARD;
            default:
                return IN_VALID_LEVEL;
        }
    }

    void getTasks() {
        vector<Task *> *tasks = new vector<Task *>();
        vector<int> taskIds{};
        vector<string> taskTitles{};
        vector<string> taskDueDates{};
        vector<string> taskDescriptions{};
        vector<TaskLevels> taskLevels{};
        vector<TaskStatus> taskStatus{};

        string taskTitle, dueDate, description, requirment;
        int taskId;
        int level;
        int status;
        string line;
        ifstream readWordTask("D:\\yukseklisansLab\\241\\yedek\\PayrollManagementSystem\\Tasks.txt");

        while (getline(readWordTask, line) && !readWordTask.eof()) {
            readWordTask >> taskId;
            readWordTask >> taskTitle;
            readWordTask >> dueDate;
            readWordTask >> description;
            readWordTask >> requirment;
            readWordTask >> level;
            readWordTask >> status;

            taskIds.push_back(taskId);
            taskTitles.push_back(taskTitle);
            taskDueDates.push_back(dueDate);
            taskLevels.push_back(convertTaskLevelTypes(level));
            taskStatus.push_back(convertTaskStatusTypes(status));
            taskDescriptions.push_back(description);
        }

        readWordTask.close();

        for (int i = 0; i < taskIds.size(); i++) {
            tasks->push_back(new Task(taskIds.at(i), taskTitles.at(i), taskDueDates.at(i), taskDescriptions.at(i),
                                      taskLevels.at(i)));
        }

        for (Task *task:*tasks) {
            cout << "ID:" << task->getId() << endl;
            cout << task->getTaskTitle() << endl;
            cout << task->getDescription() << endl;
            cout << task->getDueDate() << endl;
            cout << task->getLevel() << endl;
            cout << task->getTaskStatus() << endl;
        }

        delete tasks;
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

        cout << "SCREEEEEEEN " << screen << endl;
        return screen;
    }
};