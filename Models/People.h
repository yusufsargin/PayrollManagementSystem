//
// Created by YUSUF on 17.12.2020.
//

#ifndef PAYROLLMANEGEMENTSYSTEM_PEOPLE_H
#define PAYROLLMANEGEMENTSYSTEM_PEOPLE_H

#include <string>

using namespace std;

class People {
private:
    int userId;
    int password;
    string firstName;
    string lastName;
    int TC;
    char sex;
    string birthDate;
    string phone;
    string email;
    string address;
    //Account
    double salary;
    string enterDate;
    int childNumber;
    int dayOffNumber;
public:
    int getUserId() const {
        return userId;
    }

    void setUserId(int userId) {
        this->userId = userId;
    }

    int getPassword() const {
        return password;
    }

    void setPassword(int password) {
        this->password = password;
    }

    string getFirstName() const {
        return firstName;
    }

    void setFirstName(const string firstName) {
        this->firstName = firstName;
    }

    string getLastName() const {
        return lastName;
    }

    void setLastName(const string lastName) {
        this->lastName = lastName;
    }

    int getTc() const {
        return TC;
    }

    void setTc(int tc) {
        TC = tc;
    }

    char getSex() const {
        return sex;
    }

    void setSex(char sex) {
        this->sex = sex;
    }

    string getBirthDate() const {
        return birthDate;
    }

    void setBirthDate(const string birthDate) {
        this->birthDate = birthDate;
    }

    string getPhone() const {
        return phone;
    }

    void setPhone(const string phone) {
        this->phone = phone;
    }

    string getEmail() const {
        return email;
    }

    void setEmail(const string email) {
        this->email = email;
    }

    string getAddress() const {
        return address;
    }

    void setAddress(const string address) {
        this->address = address;
    }

    double getSalary() const {
        return salary;
    }

    void setSalary(double salary) {
        this->salary = salary;
    }

    string getEnterDate() const {
        return enterDate;
    }

    void setEnterDate(const string enterDate) {
        this->enterDate = enterDate;
    }

    int getChildNumber() const {
        return childNumber;
    }

    void setChildNumber(int childNumber) {
        this->childNumber = childNumber;
    }

    int getDayOffNumber() const {
        return dayOffNumber;
    }

    void setDayOffNumber(int dayOffNumber) {
        this->dayOffNumber = dayOffNumber;
    }
};

#endif //PAYROLLMANEGEMENTSYSTEM_PEOPLE_H
