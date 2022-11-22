#include <iostream>
#include <string>

using namespace std;

int main() {
    int computerNum;
    cin >> computerNum;

    int first, second;
    first = second = 0;
    string firstName, secondName;

    for (int i = 0; i < computerNum; i++) {
        string name;
        int ram, cpu, disk;
        cin >> name >> ram >> cpu >> disk;

        int score = ram * 2 + cpu * 3 + disk;
        if (score > first) {
            secondName = firstName;
            firstName = name;
            second = first;
            first = score;
        } else if (score > second) {
            secondName = name;
            second = score;
        }
    }

    cout << firstName << endl << secondName << endl;
}