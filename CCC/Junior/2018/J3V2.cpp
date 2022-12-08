#include <iostream>
#include <string>
using namespace std;

int main() {
    string input;
    int count = 0, prevPos = 0;
    getline(cin, input);
    int cities[4] = {0}, cityDis[5] = {0};
    for (int i = 0; i < input.length(); i++) {
        if (input[i] == ' ') {
            cities[count] = stoi(input.substr(prevPos, i));
            prevPos = i + 1;
            count++;
        }
    }
    cities[count] = stoi(input.substr(prevPos, input.length()));
    for (int i = 0; i < 5; i++) {
        int iCopy = i, temp = 0;
        for (int j = 0; j < iCopy; j++) {
            temp += cities[j];
        }
        cityDis[i] = temp;
    }
    for (int i = 0; i < 5; i++) {
        cout << cityDis[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 5; j++) {
            cityDis[j] -= cities[i];
            cout << abs(cityDis[j]) << " ";
        }
        cout << endl;
    }
    return 0;
}