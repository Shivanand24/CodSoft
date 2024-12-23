#include <iostream>
#include <cmath> n
#include <string>

using namespace std;

void calc_ulator() {
    int num1, num2;
    cout << "Enter 'A' as your 1st no. \n";
    cin >> num1;
    cout << "Enter 'B' as your 2nd no. \n";
    cin >> num2;

    cout << "So, What do you want? + , - , * , / , ** . \n Other options will be coming soon." << endl;
    string operation;
    cin >> operation;

    if (operation == "+") {
        cout << (num1 + num2) << endl;
    } else if (operation == "-") {
        cout << (num1 - num2) << endl;
    } else if (operation == "*") {
        cout << (num1 * num2) << endl;
    } else if (operation == "/") {
        if (num2 != 0) {
            cout << (static_cast<double>(num1) / num2) << endl; 
        } else {
            cout << "Error! Division by zero." << endl;
        }
    } else if (operation == "") {
        cout << pow(num1, num2) << endl; 
    } else {
        cout << "Error! Please check your input. \n Other options will be available soon." << endl;
    }

    cout << "Calculate again? (y/n): ";
    char again;
    cin >> again;
    if (tolower(again) == 'y') {
        calc_ulator();
    } else {
        cout << "Please be back for more calculations..." << endl;
    }
}

int main() {
    calc_ulator();
    return 0;
}