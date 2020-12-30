//
// Created by YUSUF on 27.12.2020.
//

#ifndef PAYROLLMANEGEMENTSYSTEM_ACCOUNT_CPP
#define PAYROLLMANEGEMENTSYSTEM_ACCOUNT_CPP

#include <string>
#include <vector>
#include "Task.h"
#include "Departmans.h"
#include <chrono>
#include <ctime>

using namespace std;

typedef std::chrono::system_clock Clock;

class Account {
    int id;
    double balance;
    double dayOffsStuff;
public:
    Account() {
        this->id = 0;
        this->balance = 0;
        this->dayOffsStuff = 0;
    }

    Account(int id, double balance, double dayoffsStuff) {
        this->id = id;
        this->balance = balance;
        this->dayOffsStuff = dayoffsStuff;
    }

    Account(Account const &obj) {
        id = obj.id;
        balance = obj.balance;
        dayOffsStuff = obj.dayOffsStuff;
    }

    ~Account() {
    }

    double calcBonus(vector<Task *> tasks)//tasklardan gelen bonuslar
    {
        int k;
        double bonus = 0.0, easy = 10, medium = 15, hard = 20, very_hard = 25;
        int taskStatus;
        for (k = 0; k < tasks.capacity(); k++) {
            taskStatus = tasks.at(k)->getTaskStatus();
            if (taskStatus == DONE) {
                switch (tasks.at(k)->getLevel()) {
                    case EASY:
                        bonus += easy;
                        break;
                    case MEDIUM:
                        bonus += medium;
                        break;
                    case HARD:
                        bonus += hard;
                        break;
                    case VERY_HARD:
                        bonus += very_hard;
                        break;
                    default:
                        break;
                }
            }
        }
        //employee.setBonus(bonus);
        return bonus;
    }

    double calcSalary(Department department, double workHours, double bonus,int dayOff,double prevSal)//toplam ay sonu ödenecek maaş
    {
        double sal = 0.0;
        sal = prevSal - ((prevSal/20)*dayOff);

        /*switch (department) {
            case Software_Engineer:
                sal = soft * workHours;
                break;
            case Human_Resources:
                sal = hr * workHours;
                break;
            case Sales_Manager:
                sal = salman * workHours;
                break;
            case Intern:
                sal = inter * workHours;
                break;
            default:
                break;
        }
        //emp.setBonus(0);
        sal = sal + bonus;*/
        this->balance = sal;
        return sal;
    }

    double calcDayoffs(double workHours, Department department, int dayOffNumber)//tatil günleri ve kesilecek para
    {
        double hours = workHours, sal = 0.0, soft = 35, hr = 25, salman = 20, inter = 10;

        switch (department) {
            case Software_Engineer:
                sal -= soft * dayOffNumber * 8;
                break;
            case Human_Resources:
                sal = hr * dayOffNumber * 8;
                break;
            case Sales_Manager:
                sal = salman * dayOffNumber * 8;
                break;
            case Intern:
                sal = inter * dayOffNumber * 8;
                break;
            default:
                break;
        }
        /*emp.setDayOffNumber(0);*/
        dayOffsStuff = sal;

        return dayOffsStuff;
    }

    double calcCompensation(string enterDate)//tazminat
    {
        auto now = Clock::now();
        std::time_t now_c = Clock::to_time_t(now);
        struct tm *parts = localtime(&now_c);

        string yearStr = enterDate;
        int enterYear = 0, currentYear, k = 0, i, worked;
        double comp = 0, five = 5, ten = 10, twenty = 20, thirty = 30;

        currentYear = 1900 + parts->tm_year;
        i = yearStr.size() - 1;
        while (k < yearStr.size()) {
            enterYear += ((int) yearStr[k++] - (int) '0') * pow(10, i--);
        }
        worked = currentYear - enterYear;
        if (worked <= 5) {
            comp = worked * five;
        } else if (5 < worked && worked <= 10) {
            comp = 5 * five;
            comp += (worked - 5) * ten;
        } else if (10 < worked && worked <= 20) {
            comp = 5 * five + 5 * ten;
            comp += (worked - 9) * twenty;
        } else if (20 < worked) {
            comp = 5 * five + 5 * ten + 10 * twenty;
            comp += (worked - 20) * thirty;
        }

        return comp;
    }

    int getId() const {
        return id;
    }

    void setId(int id) {
        Account::id = id;
    }

    double getBalance() const {
        return balance;
    }

    void setBalance(double balance) {
        Account::balance = balance;
    }

    double getDayOffsStuff() const {
        return dayOffsStuff;
    }

    void setDayOffsStuff(double dayOffsStuff) {
        Account::dayOffsStuff = dayOffsStuff;
    }
};

#endif //PAYROLLMANEGEMENTSYSTEM_ACCOUNT_CPP
