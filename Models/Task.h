//
// Created by YUSUF on 18.12.2020.
//

#ifndef PAYROLLMANEGEMENTSYSTEM_TASK_H
#define PAYROLLMANEGEMENTSYSTEM_TASK_H

#include <string>
#include <time.h>

using namespace std;

enum TaskLevels {
    EASY,
    MEDIUM,
    HARD,
    VERY_HARD
};

class Task {
    int id;
    string taskTitle;
    string dueDate;
    string description;
    string requirements;
    TaskLevels level;
public:
    Task() : id{0}, taskTitle{""}, dueDate{""}, description{""}, requirements{""}, level{EASY} {
        id = generateRandomNumber();
    }

    Task(string taskTitle, string dueDate, string description, TaskLevels level) : Task() {
        this->taskTitle = taskTitle;
        this->dueDate = dueDate;
        this->description = description;
        this->level = level;
    }

    double generateRandomNumber() {
        srand(time(NULL));

        return rand() % 1000 + 1;
    }

    int getId() const {
        return id;
    }

    void setId(int id) {
        Task::id = id;
    }

    const string &getTaskTitle() const {
        return taskTitle;
    }

    void setTaskTitle(const string &taskTitle) {
        Task::taskTitle = taskTitle;
    }

    const string &getDueDate() const {
        return dueDate;
    }

    void setDueDate(const string &dueDate) {
        Task::dueDate = dueDate;
    }

    const string &getDescription() const {
        return description;
    }

    void setDescription(const string &description) {
        Task::description = description;
    }

    const string &getRequirements() const {
        return requirements;
    }

    void setRequirements(const string &requirements) {
        Task::requirements = requirements;
    }

    TaskLevels getLevel() const {
        return level;
    }

    void setLevel(TaskLevels level) {
        Task::level = level;
    }
};

#endif //PAYROLLMANEGEMENTSYSTEM_TASK_H
