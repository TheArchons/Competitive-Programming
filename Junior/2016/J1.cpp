#include <iostream>
#include <string>
using namespace std;

int main() {
    string temp;
    int wins = 0;
    for (int i = 0; i < 6; i++){
        cin >> temp;
        if (temp == "W") {
            wins++;
        }
    }
    if (wins > 4) {
        cout << "1";
    }
    else if (wins == 3 || wins == 4){
        cout << "2";
    }
    else if (wins != 0) {
        cout << "3";
    }
    else {
        cout << "-1";
    }
}