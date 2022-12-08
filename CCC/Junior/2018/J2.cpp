#include <iostream>
#include <string>
using namespace std;

int main() {
    int length, commonSpaces = 0;
    string day1, day2;
    cin >> length;
    cin >> day1;
    cin >> day2;
    int day1Pos[length];
    for (int i = 0; i < length; i++) {
        if (day1[i] == 'C') {
            day1Pos[i] = 1;
        } else {
            day1Pos[i] = 0;
        }
    }
    for (int i = 0; i < length; i++) {
        if (day2[i] == 'C') {
            if (day1Pos[i] == 1) {
                commonSpaces++;
            }
        }
    }
    cout << commonSpaces;
    return 0;
}