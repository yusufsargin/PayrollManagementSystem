//
// Created by yusuf_sargin on 24.12.2020.
//

#ifndef PAYROLLMANEGEMENTSYSTEM_MANAGER_CPP
#define PAYROLLMANEGEMENTSYSTEM_MANAGER_CPP

#include "Employee.cpp"
#include "Team.cpp"
#include "Task.h"
#include <vector>

using namespace std;

class Manager : public Employee {
    Team team;
public:
    bool assignTaskToTeamMember(int id, Task task) {

    }

    Employee getMemberById(int id) {
        return team.getEmployeeById(id);
    }
};


#endif //PAYROLLMANEGEMENTSYSTEM_MANAGER_CPP
