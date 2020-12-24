//
// Created by yusuf_sargin on 24.12.2020.
//

#ifndef PAYROLLMANEGEMENTSYSTEM_TEAM_H
#define PAYROLLMANEGEMENTSYSTEM_TEAM_H

#include "Employee.cpp"
#include <vector>

using namespace std;

class Team {
    vector<Employee> employeeList;
public:
    Team() {
        this->employeeList = getEmployeeList();
    }

    vector<Employee> getTeamMembers() {
        Employee employee{"Yusuf", "sargin", 'M', 12312312, "12313"};

        employeeList.push_back(employee);

        return employeeList;
    }

    vector<Employee> getEmployeeList() {
        return employeeList;
    }

    Employee getEmployeeById(int id) {
        Employee returnEmployee;

        for (Employee employee: employeeList) {
            if (id == employee.getUserId()) {
                returnEmployee = employee;
            }
        }

        return returnEmployee;
    }
};

#endif //PAYROLLMANEGEMENTSYSTEM_TEAM_H
