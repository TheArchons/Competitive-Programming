#include <iostream>
using namespace std;

int main() {
    int number;
    int prevNum;
    for (int i = 0; i <  4; i++) {
        cin >> number;
        if (i == 0 || i == 3) {
            if (number == 8 || number == 9) {
                continue;
            }
            else {
                cout << "answer";
                return 0;
            }
        }
        else if (i == 1) {
            prevNum = number;
        }
        else {
            if (number == prevNum) {
                continue;
            }
            else {
                cout << "answer";
                return 0;
            }
        }
    }
    cout << "ignore";
    return 0;
}
