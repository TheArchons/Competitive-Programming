#include <iostream>
#include <string>
using namespace std;

int main() {
    int length, total = 0;
    string day1, day2;
    cin >> length;
    cin >> day1 >> day2;
    for (int i = 0; i < length; i++) {
        if (day1[i] == 'C' && day2[i] == 'C') {
            total++;
        }
    }
    cout << total;
}