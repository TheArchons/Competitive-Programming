#include <iostream>
#include <string>

using namespace std;

int main() {
    int columns, rows, inputs, total = 0, Rs = 0, Cs = 0, temp2 = 0;
    string temp;
    getline(cin, temp);
    rows = stoi(temp);
    getline(cin, temp);
    columns = stoi(temp);
    getline(cin, temp);
    inputs = stoi(temp);
    bool rArray[rows] = {0}, cArray[columns] = {0};
    for (int i = 0; i < inputs; i++) {
        string input;
        getline(cin, input);
        char cOrR = input[0];
        int index = stoi(input.substr(2, input.length()));
        if (cOrR == 'R') {
            if (rArray[index - 1]) {
                rArray[index - 1] = false;
            }
            else {
                rArray[index - 1] = true;
            }
        } else {
            if (cArray[index - 1]) {
                cArray[index - 1] = false;
            }
            else {
                cArray[index - 1] = true;
            }
        }
    }
    for (int i = 0; i < rows; i++) {
        if (rArray[i]) {
            Rs++;
        }
    }
    for (int i = 0; i < columns; i++) {
        if (cArray[i]) {
            Cs++;
        }
    }
    total = Cs*(rows-Rs);
    total += Rs*(columns-Cs);
    cout << total;
}