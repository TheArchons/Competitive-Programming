#include <iostream>
#include <string>
using namespace std;

int main() {
    string temp;
    int length, count = 0;
    getline(cin, temp);
    length = stoi(temp);
    int ins[length][length] = {0};
    temp = "";
    for (int i = 0; i < length; i++) {
        char c = getchar();
        while (c != '\n') {
            if (c == ' ') {
                ins[i][count] = stoi(temp);
                temp = "";
                count++;
            } else {
                temp += c;
            }
            c = getchar();
        }
        ins[i][count] = stoi(temp);
        temp = "";
        count = 0;
    }
    for (int i = 0; i < 4; i++) {
        bool testFail = false;
        for (int i = 0; i < length; i++) { //tests for table validity
            int prevVal = 0;
            for (int j = 0; j < length; j++) {
                if (ins[i][j] < prevVal) { //checks if each value is greater than the previous value
                    testFail = true;
                    break;
                }
                if (i != 0) { //checks if each row is larger than the previous row
                    if (ins[i][j] <= ins[i - 1][j]) {
                        testFail = true;
                        break;
                    }
                }
                prevVal = ins[i][j];
            }
        }
        if (testFail) {
            int ins2[length][length] = {0};
            for(int i = 0; i < length; i++) { //rotation
                for(int j = 0; j < length; j++) {
                    ins2[j][length-i-1] = ins[i][j];
                }
            }
            for(int i = 0; i < length; i++) { //cloning
                for(int j = 0; j < length; j++) {
                    ins[i][j] = ins2[i][j];
                }
            }
        } else { //if table is valid, prints the table
            for(int i = 0; i < length; i++) {
                for(int j = 0; j < length; j++) {
                    cout << ins[i][j] << " ";
                }
                cout << endl;
            }
            return 0;
        }
    }
}