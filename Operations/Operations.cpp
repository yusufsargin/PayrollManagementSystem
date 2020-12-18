//
// Created by YUSUF on 18.12.2020.
//
#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Operations {
    vector<string> operations;
public:
    Operations() {}

    Operations(vector<string> operationsValue) {
        this->operations = operationsValue;
    }

    Operations(Operations &obj) {
        operations = obj.operations;
    }

    void displayOperations(string header = "Operations") {
        cout << "----------------------------------" << endl;

        cout << header << endl;

        for (string operation:operations) {
            cout << operation << endl;
        }

        cout << "----------------------------------" << endl;
    }

    int getInputValue() {
        int operation = 0;

        cin >> operation;

        if (operation > operations.size()) {
            cout << "Invalid value. Please try again" << endl;
            getInputValue();
        }

        return operation;
    }
};