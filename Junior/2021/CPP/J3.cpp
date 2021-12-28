#include <iostream>
#include <string>
using namespace std;

int main() {
    string prevDirection = "";
    while (true) {
        string input;
        cin >> input;
        if (input == "99999") {
            break;
        }
        if ((int(input[0]) + int(input[1])) == 0) {
            cout << prevDirection;
        }
        else if ((int(input[0]) + int(input[1])) % 2 == 0) {
            cout << "right ";
            prevDirection = "right ";
        }
        else if ((int(input[0]) + int(input[1])) % 2 != 0) {
            cout << "left ";
            prevDirection = "left ";
        }
        cout << input.substr(2, 4) << endl;
    }
}