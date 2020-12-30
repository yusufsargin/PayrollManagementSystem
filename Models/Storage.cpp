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
#include <string>

using namespace std;

class Storage {
    vector<Employee *> *employeeList;
    vector<Task *> *tasks;
    vector<Account *> *accounts;
    string accountPath = "D:\\yukseklisansLab\\241\\yedek\\PayrollManagementSystem\\Account.txt";
    string employeePath = "D:\\yukseklisansLab\\241\\yedek\\PayrollManagementSystem\\Employee.txt";
    string peoplePath = "D:\\yukseklisansLab\\241\\yedek\\PayrollManagementSystem\\People.txt";
    string stuffPath = "D:\\yukseklisansLab\\241\\yedek\\PayrollManagementSystem\\Stuff.txt";
    string tasksPath = "D:\\yukseklisansLab\\241\\yedek\\PayrollManagementSystem\\Tasks.txt";
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
        ifstream peopleFile, employeeFile;
        peopleFile.open(peoplePath);
        employeeFile.open(employeePath);

        string line;
        int userId = 0, childNumber, dayOffNumber, password, department, taskId, bonus, workHours, isActive;
        string name, tc, lastName, birtDate, phone, email, address, enterDate;
        char sex;
        double salary;


        vector<People *> *people = new vector<People *>;
        vector<Task *> *taskList = getTasks();

        vector<int> employeeID{};
        vector<int> employeeDepartment{};
        vector<int> employeeTasksIds{};
        vector<int> employeeBonus{};
        vector<int> workHoursList{};

        if (peopleFile.is_open()) {
            while (getline(peopleFile, line)) {
                peopleFile >> userId;
                peopleFile >> password;
                peopleFile >> name;
                peopleFile >> lastName;
                peopleFile >> tc;
                peopleFile >> sex;
                peopleFile >> birtDate;
                peopleFile >> phone;
                peopleFile >> email;
                peopleFile >> address;
                peopleFile >> salary;
                peopleFile >> enterDate;
                peopleFile >> childNumber;
                peopleFile >> dayOffNumber;

                if (userId != 0) {
                    People *peoplePushItem = new People(userId, password, name, lastName, sex, tc, phone, enterDate,
                                                        childNumber,
                                                        dayOffNumber, salary, address, email, birtDate);
                    people->push_back(peoplePushItem);
                }
            }

            peopleFile.close();
        }
        string employeeLine;
        if (employeeFile.is_open()) {
            while (getline(employeeFile, employeeLine)) {
                employeeFile >> userId;
                employeeFile >> department;
                employeeFile >> taskId;
                employeeFile >> bonus;
                employeeFile >> isActive;
                employeeFile >> workHours;

                for (People *peopleItem:*people) {
                    if (peopleItem->getUserId() == userId) {
                        Employee *employee = new Employee(
                                peopleItem->getUserId(),
                                peopleItem->getPassword(),
                                peopleItem->getFirstName(),
                                peopleItem->getLastName(),
                                peopleItem->getSex(),
                                peopleItem->getTc(),
                                peopleItem->getPhone(),
                                peopleItem->getEnterDate(),
                                peopleItem->getChildNumber(),
                                peopleItem->getDayOffNumber(),
                                peopleItem->getSalary(),
                                peopleItem->getAddress(),
                                peopleItem->getEmail(),
                                peopleItem->getBirthDate(),
                                department,
                                0,
                                workHours,
                                bonus
                        );

                        this->employeeList->push_back(employee);
                        /*for (Task *task:*taskList) {
                            if (task->getId() == userId) {
                                *//*for (int i = 0; i < employeeList->size(); i++) {
                                    if (employeeList->at(i)->getUserId() == userId) {
                                        Task *taskItem = task;
                                        this->employeeList->at(i)->assignNewTaskToEmployee(taskItem);
                                    }
                                }*//*
                            }
                        }*/

                        //employee->setTasks(tasksForEmployee);
                    }
                }
            }
            employeeFile.close();
        }

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
        ifstream readWordTask(tasksPath);

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

        /*for (Task *task:*tasks) {
            cout << "ID:" << task->getId() << endl;
            cout << task->getTaskTitle() << endl;
            cout << task->getDescription() << endl;
            cout << task->getDueDate() << endl;
            cout << task->getLevel() << endl;
            cout << task->getTaskStatus() << endl;
        }*/

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
        ifstream readWordAccount(accountPath);

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

        /* for (Account *account:*accounts) {
             cout << "Account ID: " << account->getId() << endl;
             cout << "Balance: " << account->getBalance() << endl;
             cout << "DayOffs Stuff: " << account->getDayOffsStuff() << endl;
         }*/

        return accounts;
    }

    void setStorageAccount(vector<Account *> *accountList) {
        ofstream accountFile;
        accountFile.open(accountPath);

        if (accountFile.is_open()) {
            accountFile << "AccountId " << "Balance " << "DayOffStuff \n";
            //accountList->push_back(new Account(4,500,20));
            for (Account *account:*accountList) {
                accountFile << account->getId() << " " << account->getBalance() << " " << account->getDayOffsStuff()
                            << "\n";
            }

            accountFile.close();
        }
    }

    void setEmployeeList(vector<Employee *> *employeeListInput) {
        ofstream employeeFile, peopleFile;
        employeeFile.open(employeePath);
        peopleFile.open(peoplePath);

        if (employeeFile.is_open()) {
            /*"userID    Department\tTasks\tbonus\tisActive    stuff\tsigorta\t workHours";*/
            employeeFile << "UserId " << "Department " << "Tasks " << "Bonus " << "isActive " << "workHours" << endl;
            for (Employee *employee:*employeeListInput) {
                employeeFile << employee->getUserId() << " " << employee->getDepartment() << " " <<
                             "null" << " " << employee->getBonus() << " " <<
                             employee->isActive1() << " " << employee->getWorkHours() << endl;
                //Task devre dışı
            }

            employeeFile.close();
        }

        if (peopleFile.is_open()) {
            /*userId    password   name    lastName   tc         	sex	birthDate	phone		email			address		    salary      enterDate     childNumber   izinMiktarı*/
            peopleFile << "UserId " << "Password " << "Name " << "LastName " << "TC " << "Sex " << "Birth_Date "
                       << "Phone " << "Email " << "Address " << "Salary " << "Enter_Date " << "ChildNumber "
                       << "DayOffNumber" << endl;
            for (Employee *employee:*employeeListInput) {
                peopleFile << employee->getUserId() << " ";
                peopleFile << employee->getPassword() << " ";
                peopleFile << employee->getFirstName() << " ";
                peopleFile << employee->getLastName() << " ";
                peopleFile << employee->getTc() << " ";
                peopleFile << employee->getSex() << " ";
                peopleFile << employee->getBirthDate() << " ";
                peopleFile << employee->getPhone() << " ";
                peopleFile << employee->getEmail() << " ";
                peopleFile << employee->getAddress() << " ";
                peopleFile << employee->getSalary() << " ";
                peopleFile << employee->getEnterDate() << " ";
                peopleFile << employee->getChildNumber() << " ";
                peopleFile << employee->getDayoffNumber() << " " << endl;
            }

            peopleFile.close();
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

        ifstream readWordPeople(peoplePath);
        while (getline(readWordPeople, line)) {
            readWordPeople >> peopleID;
            cout << peopleID << endl;

            readWordPeople >> Pass;
            //cout << Pass<<endl;

            if (userID == peopleID && password == Pass) {
                cout << "Enterance is successful!" << endl;


                ifstream readWordEmployee(employeePath);
                while (getline(readWordEmployee, line)) {
                    int dept;
                    readWordEmployee >> employeeID;

                    readWordEmployee >> dept;
                    if (userID == employeeID) {
                        if (dept == 1) {
                            screen = HR_SCREEN;
                        } else if (dept == 2) {
                            screen = MANAGER_SCREEN;
                        } else {
                            screen = EMPLOYEE_SCREEN;
                        }
                    }
                }
                readWordEmployee.close();


                /*ifstream readWordHR("D:\\yukseklisansLab\\241\\yedek\\PayrollManagementSystem\\HR.txt");
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
                }*/

            }
        }
        readWordPeople.close();

        cout << "SCREEEEEEEN " << screen << endl;
        return screen;
    }
};