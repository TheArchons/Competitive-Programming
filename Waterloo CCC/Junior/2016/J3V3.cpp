#include <iostream>
#include <string>

using namespace std;

bool isPalidrome(string x) {
    for (int i = 0; i < x.length()/2; i++) {
        if (x[i] != x[x.length()-1-i]) {
            return false;
        }
    }
    return true;
}

int main() {
    string input;
    cin >> input;
    for (int i = input.length(); i > 0; i--) { //check in decreasing
        for (int j = 0; j < input.length()-i+1; j++) { //check in increasing
            string subStr = input.substr(j, i);
            if (isPalidrome(subStr)) {
                cout << i << endl;
                return 0;
            }
        }
    }
}