//
// Created by YUSUF on 28.12.2020.
//

#include "string"
#include "../../Models/Employee.cpp"

using namespace std;

#define DAILY_WORK_HOURS 8

enum HumanResourcesOperationsTypes {
    ADD_NEW_EMPLOYEE = 1,
    REMOVE_EXIST_EMPLOYEE,
    UPDATE_EMPLOYEE,
    CHECK_SALARY,
    DETECT_HOLIDAYS
};

class HumanResourcesMainScreen {
    int dayoffNum;
    int ID;
    int password;
    int childNumber;
    int workHours;
    string firstName;
    string lastName;
    int department;
    Department dep;
    int TC;
    char sex;
    string birthDate;
    string phone;
    string email;
    string address;
    string dayoffType;
    Employee *new_employee;
    vector<string> operationsValue{
            "0.Exit",
            "1.Add New Employee",
            "2.Remove Exist Employee"
            "3.Set Holidays"
    };
    vector<Employee *> *employeeList;
public:
    HumanResourcesMainScreen() {
        this->employeeList = new vector<Employee *>;
    }

    HumanResourcesMainScreen(vector<Employee *> *employeeList) {
        this->employeeList = employeeList;
    }


    void detectHolidays() {
        int i;
        cout<<"Enter ID of employee: ";
        cin>>ID;
        cout<<"Enter day off type (Unpaid or Paid): ";
        cin>>dayoffType;
        cout<<"Enter taken day offs: ";
        cin>>dayoffNum;
        if(dayoffType == "Unpaid")
        {
            for(i = 0 ; i < employeeList->size() ; i++)
            {
                if(employeeList->at(i)->getUserId() == ID)
                {
                    employeeList->at(i)->setWorkHours(employeeList->at(i)->getWorkHours() - dayoffNum * DAILY_WORK_HOURS);
                }
            }
        }else if(dayoffType == "paid");
        {
            for(i = 0 ; i < employeeList->size() ; i++)
            {
                if(employeeList->at(i)->getUserId() == ID)
                {
                    if(employeeList->at(i)->getDayOffNumber() > 0)
                    {
                        employeeList->at(i)->setDayoffNumber(employeeList->at(i)->getDayoffNumber() - dayoffNum);
                    }
                }
            }
        }
    }

    void addNewEmployee() {
        cout<<"----------New Employee----------"<<endl;
        cout<<"Enter user ID: ";
        cin>>ID;
        cout<<"Enter password: ";
        cin>>password;
        cout<<"Enter first name: ";
        cin>>firstName;
        cout<<"Enter last name: ";
        cin>>lastName;
        cout<<"Enter TC: ";
        cin>>TC;
        cout<<"Enter sex: ";
        cin>>sex;
        cout<<"Enter birth date: ";
        cin>>birthDate;
        cout<<"Enter phone number: ";
        cin>>phone;
        cout<<"Enter e-mail address: ";
        cin>>email;
        cout<<"Enter child number: ";
        cin>>childNumber;
        cout<<"Enter work hours: ";
        cin>>workHours;
        cout<<"Enter paid day offs: ";
        cin>>dayoffNum;
        cout<<"Enter department(0-Software engineer 1-Human resources 2-Sales manager 3-Intern): ";
        cin>>department;
        cout<<endl;
        new_employee = new Employee(ID,firstName,lastName,sex,TC,phone , dayoffNum , department);
        employeeList->push_back(new_employee);
    }

    void updateEmployee() {
        int dec;
        cout<<"Enter ID of the employee: ";
        cin>>ID;
        for(int i = 0 ; i < employeeList->size() ; i++)
        {
            cout<<"1-User ID"<<endl<<"2-Password"<<endl<<"3-First name"<<endl<<"4-Last name"<<endl<<"5-TC"<<endl<<"6-Sex"<<endl;
            cout<<"7-Birth date"<<endl<<"8-Phone number"<<endl<<"9-Email address"<<endl<<"10-Child number"<<"11-Work hours"<<endl;
            cout<<"12-Day offs"<<endl<<"13-Department";
            cin>>dec;
            if(ID == employeeList->at(i)->getUserId())
            {
                switch (dec) {
                    case 1:
                        cout << "Enter new user ID: ";
                        cin >> ID;
                        employeeList->at(i)->setUserId(ID);
                        break;
                    case 2:
                        cout << "Enter password: ";
                        cin >> password;
                        employeeList->at(i)->setPassword(password);
                        break;
                    case 3:
                        cout<<"Enter first name: ";
                        cin>>firstName;
                        employeeList->at(i)->setFirstName(firstName);
                        break;
                    case 4:
                        cout<<"Enter last name: ";
                        cin>>lastName;
                        employeeList->at(i)->setLastName(lastName);
                        break;
                    case 5:
                        cout<<"Enter TC: ";
                        cin>>TC;
                        employeeList->at(i)->setTc(TC);
                        break;
                    case 6:
                        cout<<"Enter sex: ";
                        cin>>sex;
                        employeeList->at(i)->setSex(sex);
                        break;
                    case 7:
                        cout<<"Enter birth date: ";
                        cin>>birthDate;
                        employeeList->at(i)->setBirthDate(birthDate);
                        break;
                    case 8:
                        cout<<"Enter phone number: ";
                        cin>>phone;
                        employeeList->at(i)->setPhone(phone);
                        break;
                    case 9:
                        cout<<"Enter e-mail address: ";
                        cin>>email;
                        employeeList->at(i)->setEmail(email);
                        break;
                    case 10:
                        cout<<"Enter child number: ";
                        cin>>childNumber;
                        employeeList->at(i)->setChildNumber(childNumber);
                        break;
                    case 11:
                        cout<<"Enter work hours: ";
                        cin>>workHours;
                        employeeList->at(i)->setWorkHours(workHours);
                        break;
                    case 12:
                        cout<<"Enter paid day offs: ";
                        cin>>dayoffNum;
                        employeeList->at(i)->setDayOffNumber(dayoffNum);
                        break;
                    case 13:
                        cout<<"Enter department: ";
                        cin>>department;
                        employeeList->at(i)->setDepartmentWithInt(department);
                        break;
                    default:
                        cout<<"Invalid operation"<<endl;
                        break;
                }
            }
        }
    }

    void checkSalary() {
        int i;
        cout<<"Employee ID to check salary: ";
        cin>>ID;
        for(i = 0 ; i < employeeList->size() ; i++)
        {
            if(employeeList->at(i)->getUserId() == ID)
            {
                cout<<"Salary of "<<employeeList->at(i)->getFirstName()<<" "<<employeeList->at(i)->getLastName()
                    <<": "<<employeeList->at(i)->getSalary()<<endl;
            }
        }
    }

    void deleteEmployee() {
        int i;
        bool exists = false;
        cout<<"Enter employee ID to delete: ";
        cin>>ID;
        for(i = 0 ; i < employeeList->size() ; i++)
        {
            if(employeeList->at(i)->getUserId() == ID)
            {
                exists = true;
                employeeList->erase(employeeList->begin() + i);//Test etmeyi unutma!!!
            }
        }
        if(exists == false)
        {
            cout<<"Employee does not exist!"<<endl;
        }
    }

    vector<string> getHROperations() {
        return operationsValue;
    }

    vector<Employee *> *getEmployeeList() const {
        return employeeList;
    }

    void setEmployeeList(vector<Employee *> *employeeList) {
        HumanResourcesMainScreen::employeeList = employeeList;
    }
};