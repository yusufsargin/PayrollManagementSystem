#ifndef Account_H
#define Account_H

#include <vector>
#include <chrono>
#include <ctime>
#include "Employee.h"

typedef std::chrono::system_clock Clock;

class Account
{
private:
    double balance;
public:
    double  calcBonus(Employee &emp)//tasklardan gelen bonuslar
    {
        int k;
        double bonus = 0.0,easy = 10 , medium = 15 , hard = 20 , very_hard = 25;
        vector<Task> *tasks;
        int taskStatus;
        tasks = emp.getTasks();
        for(k = 0 ; k < tasks->capacity() ; k++)
        {
            taskStatus = tasks->at(k).getTaskStatus();
            if(taskStatus == DONE)
            {
                switch (tasks->at(k).getLevel())
                {
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
        emp.setBonus(bonus);
    }
    double calcSalary(Employee &emp)//toplam ay sonu ödenecek maaş
    {
        double hours = emp.getWorkHours() , sal = 0.0 , soft = 35 , hr = 25 , salman = 20 , inter = 10;
        int department = emp.getDepartment();
        switch (department)
        {
            case 0:
                sal = soft * emp.getWorkHours();
                break;
            case 1:
                sal = hr * emp.getWorkHours();
                break;
            case 2:
                sal = salman * emp.getWorkHours();
                break;
            case 3:
                sal = inter * emp.getWorkHours();
                break;
            default:
                break;
        }
        sal = emp.getBonus();
        emp.setBonus(0);
        balance = sal;
    }
    double calcDayoffs(Employee &emp)//tatil günleri ve kesilecek para
    {
        double hours = emp.getWorkHours() , sal = 0.0 , soft = 35 , hr = 25 , salman = 20 , inter = 10;
        int department = emp.getDepartment();
        switch (department)
        {
            case 0:
                sal -= soft * emp.getDayOffNumber() * 8;
                break;
            case 1:
                sal = hr * emp.getDayOffNumber() * 8;
                break;
            case 2:
                sal = salman * emp.getDayOffNumber() * 8;
                break;
            case 3:
                sal = inter * emp.getDayOffNumber() * 8;
                break;
            default:
                break;
        }
        emp.setDayOffNumber(0);
    }
    double calcCompensation(Employee &emp)//tazminat
    {
        auto now = Clock::now();
        std::time_t now_c = Clock::to_time_t(now);
        struct tm *parts = std::localtime(&now_c);

        string yearStr = emp.getEnterDate();
        int enterYear = 0, currentYear , k = 0 , i , worked;
        double comp = 0, five = 5 , ten = 10 , twenty = 20 , thirty = 30;

        currentYear = 1900 + parts->tm_year;
        i = yearStr.size() - 1;
        while(k < yearStr.size())
        {
            enterYear += ((int)yearStr[k++] - (int)'0') * pow(10 , i--);
        }
        worked = currentYear - enterYear;
        if(worked <= 5)
        {
            comp = worked * five;
        }
        else if(5 < worked && worked <= 10)
        {
            comp = 5 * five;
            comp += (worked - 5) * ten;
        }
        else if(10 < worked && worked <= 20)
        {
            comp = 5 * five + 5 * ten;
            comp += (worked - 9) * twenty;
        }
        else if(20 < worked)
        {
            comp = 5 * five + 5 * ten + 10 * twenty;
            comp += (worked - 20) * thirty;
        }

    }
};

#endif