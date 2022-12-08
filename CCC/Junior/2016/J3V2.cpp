#include <iostream>
#include <string>
using namespace std;

bool isPalidrome(string i) {
    for (int j = 0; j < i.length() / 2; j++) {
        if (i[j] != i[i.length() - 1 - j]) {
            return false;
        }
    }
    return true;
}

int main() {
    string input;
    cin >> input;
    string curr = input;
    if (isPalidrome(input)) {
        cout << input.length() << endl;
        return 0;
    }
    for (int currLen = input.length(); currLen > 0; currLen--){
        for (int j = input.length() - currLen + 1; j > 0; j--){
            string sub = input.substr(j, currLen);
            if (isPalidrome(sub)) {
                cout << sub.length() << endl;
                return 0;
            }
        }
    }
}