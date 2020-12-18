//
// Created by YUSUF on 18.12.2020.
//

#ifndef PAYROLLMANEGEMENTSYSTEM_TASK_H
#define PAYROLLMANEGEMENTSYSTEM_TASK_H

#include <string>

using namespace std;

class Task {
public:
    int id;
    string taskTitle;
    string dueDate;
    string description;
    string requirements;
    int level;
};

#endif //PAYROLLMANEGEMENTSYSTEM_TASK_H
