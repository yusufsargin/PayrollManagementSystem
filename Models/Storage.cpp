//
// Created by YUSUF on 27.12.2020.
//

#include <vector>
#include <iostream>
#include <fstream>
#include "Task.h"
#include "Employee.cpp"
#include "ScreenType.h"
#include "Account.h"

using namespace std;

class Storage {
    vector<Employee *> *employeeList;
    vector<Task *> *tasks;
    vector<Account *> *accounts;
public:
    Storage() {
        this->employeeList = new vector<Employee *>();
        this->tasks = new vector<Task *>;
        this->accounts = new vector<Account *>;
    }

    ~Storage() {
        delete employeeList;
        delete tasks;
        delete accounts;
    }

    Storage(Storage const &obj) {
        delete employeeList;
        delete tasks;
        delete accounts;

        this->employeeList = new vector<Employee *>;
        for (Employee *employee:*obj.employeeList) {
            this->employeeList->push_back(employee);
        }

        this->tasks = new vector<Task *>;
        for (Task *task:*obj.tasks) {
            this->tasks->push_back(task);
        }

        this->accounts = new vector<Account *>;
        for (Account *acc:*accounts) {
            this->accounts->push_back(acc);
        }
    }

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

    vector<Task *> *getTasks() {
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
            this->tasks->push_back(new Task(taskIds.at(i), taskTitles.at(i), taskDueDates.at(i), taskDescriptions.at(i),
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

        return tasks;
    }

    //for Account
    vector<Account *> *getAccounts() {
        vector<int> accountIds{}; //sanırım bizim yazdığımız yerde yok ama olması gerek
        vector<double> accountBalances{};
        vector<double> accountDayOffsStuffs{};

        double balance, dayOffsStuff;
        int accountId;
        string line;
        ifstream readWordAccount("C:\\Users\\yusuf_sargin\\Desktop\\yuksekLisans\\PayrollManagementSystem\\Account.txt");

        while (getline(readWordAccount, line) && !readWordAccount.eof()) {
            readWordAccount >> accountId;
            readWordAccount >> balance;
            readWordAccount >> dayOffsStuff;


            accountIds.push_back(accountId);
            accountBalances.push_back(balance);
            accountDayOffsStuffs.push_back(dayOffsStuff);

        }

        readWordAccount.close();

        for (int i = 0; i < accountIds.size(); i++) {
            this->accounts->push_back(new Account(accountIds.at(i), accountBalances.at(i), accountDayOffsStuffs.at(i)));
        }

        for (Account *account:*accounts) {
            cout << "Account ID: " << account->getId() << endl;
            cout << "Balance: " << account->getBalance() << endl;
            cout << "DayOffs Stuff: " << account->getDayOffsStuff() << endl;
        }

        return accounts;
    }

    void setStorageAccount(vector<Account*> *accountList){
        ofstream accountFile;
        accountFile.open("C:\\Users\\yusuf_sargin\\Desktop\\yuksekLisans\\PayrollManagementSystem\\Account.txt");

        if(accountFile.is_open()){
            accountFile << "AccountId " << "Balance " << "DayOffStuff \n";
            for(Account *account:*accountList){
                accountFile  << account->getId() << " " << account->getBalance() << " "  <<  account->getDayOffsStuff() << "\n";
            }

            accountFile.close();
        }
    }

    SCREEN auth() {
        SCREEN screen = IN_VALID_SCREEN;
        int userID;
        string userId, password;

        cout << "Enter your user ID: ";
        cin >> userID;
        cout << "Enter your password: ";
        cin >> password;

        int peopleID, employeeID, hrID;
        string PeopleId, EmployeeId, HRId, ManagerId, Pass;
        string line;

        ifstream readWordPeople("D:\\yukseklisansLab\\241\\yedek\\PayrollManagementSystem\\People.txt");
        while (getline(readWordPeople, line)) {
            readWordPeople >> peopleID;
            cout << peopleID << endl;

            readWordPeople >> Pass;
            //cout << Pass<<endl;

            if (userID == peopleID && password == Pass) {
                cout << "Enterance is successful!" << endl;

                ifstream readWordEmployee("D:\\yukseklisansLab\\241\\yedek\\PayrollManagementSystem\\Employee.txt");
                while (getline(readWordEmployee, line)) {
                    readWordEmployee >> employeeID;

                    if (userID == employeeID) {
                        screen = EMPLOYEE_SCREEN;
                    }
                }
                readWordEmployee.close();


                ifstream readWordHR("D:\\yukseklisansLab\\241\\yedek\\PayrollManagementSystem\\HR.txt");
                while (getline(readWordHR, line)) {
                    readWordHR >> hrID;
                    //cout << HRId << endl;

                    if (userID == hrID) {
                        if (userId == HRId) {
                            screen = HR_SCREEN;
                        }
                    }
                    readWordHR.close();

                    break;
                }

            }
        }
        readWordPeople.close();

        cout << "SCREEEEEEEN " << screen << endl;
        return screen;
    }
};