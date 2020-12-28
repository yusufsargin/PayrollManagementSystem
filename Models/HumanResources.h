//
// Created by YUSUF on 28.12.2020.
//

#ifndef PAYROLLMANEGEMENTSYSTEM_HUMANRESOURCES_H
#define PAYROLLMANEGEMENTSYSTEM_HUMANRESOURCES_H

class HumanResources{
    HumanResources();
    HumanResources(string, string,string);
    string getName();
    void setName(string);
    string getLastName();
    void setLastName(string);
    string getID();
    void setID(string);
    void print(string);
private:
    string name;
    string lastname;
    string id;
};

HumanResources::HumanResources() {
    name = "Unknown";
    lastname = "Unknown";
    id = "0";
}

HumanResources::HumanResources(string _name, string _lastname, string _id) {
    name = _name;
    lastname = _lastname;
    id = _id;
}

string HumanResources::getName() {
    return name;
}

void HumanResources::setName(string name) {
    this->name = name;
}
string HumanResources::getLastName() {
    return lastname;
}

void HumanResources::setLastName(string lastname) {
    this->lastname = lastname;
}

string HumanResources::getID() {
    return id;
}

void HumanResources::setID(string id ){
    this->id = id;
}

void HumanResources::print(string type) {
    if (type == "light")
        cout << left << setw(20) << name << setw(20) << lastname <<  setw(20) << id << endl;
    else if (type == "headers")
        cout << left << setw(10) << "Name: " << name << endl << setw(10) << "Last Name: " << lastname << endl << setw(10)
             << "ID:" << id << endl;
}

#endif //PAYROLLMANEGEMENTSYSTEM_HUMANRESOURCES_H
