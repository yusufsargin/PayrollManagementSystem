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
    VERY_HARD,
    IN_VALID_LEVEL
};

enum TaskStatus {
    WAITING,
    IN_PROGRESS,
    DONE,
    IN_VALID_STATUS
};

class Task {
    int id;
    string taskTitle;
    string dueDate;
    string description;
    string requirements;
    TaskLevels level;
    TaskStatus taskStatus;
public:
    static void showLevelOptions() {
        cout << "0.EASY" << endl;
        cout << "0.MEDIUM" << endl;
        cout << "0.HARD" << endl;
        cout << "0.VERY_HARD" << endl;
    }

    Task() : id{0}, taskTitle{""}, dueDate{""}, description{""}, requirements{""}, level{EASY}, taskStatus{WAITING} {
    }

    Task(int id, string taskTitle, string dueDate, string description, TaskLevels level) : Task() {
        this->id = id;
        this->taskTitle = taskTitle;
        this->dueDate = dueDate;
        this->description = description;
        this->level = level;
    }

    Task(int id, string taskTitle, string dueDate, string description, int level) : Task() {
        this->id = id;
        this->taskTitle = taskTitle;
        this->dueDate = dueDate;
        this->description = description;

        switch (level) {
            case 0:
                this->level = EASY;
                break;
            case 1:
                this->level = MEDIUM;
                break;
            case 2:
                this->level = HARD;
                break;
            case 3:
                this->level = VERY_HARD;
                break;
            default:
                this->level = EASY;
                break;
        }
    }

    Task(Task const &obj) {
        this->id = obj.id;
        this->taskTitle = obj.taskTitle;
        this->dueDate = obj.dueDate;
        this->description = obj.description;
        this->requirements = obj.requirements;
        this->level = obj.level;
        this->taskStatus = obj.taskStatus;
    }

    double generateRandomNumber() {
        srand(time(NULL));

        return rand() % 1000 + 1;
    }

    TaskStatus getTaskStatus() const {
        return taskStatus;
    }

    void setTaskStatus(TaskStatus taskStatus) {
        Task::taskStatus = taskStatus;
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

    /* Task &operator=(const Task &obj);*/
};

/*Task &Task::operator=(const Task &obj) {
    this->id = obj.id;
    this->taskTitle = obj.taskTitle;
    this->dueDate = obj.dueDate;
    this->description = obj.description;
    this->requirements = obj.requirements;
    this->level = obj.level;
    this->taskStatus = obj.taskStatus;

    return *this;
}*/

#endif //PAYROLLMANEGEMENTSYSTEM_TASK_H
