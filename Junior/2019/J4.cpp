#include <iostream>
#include <string>
#include <chrono>
using namespace std::chrono;
using namespace std;

int main() {
    string flips;
    int hFlips = 0, vFlips = 0;
    bool h = false, v = false;
    cin >> flips;
    for (int i = 0; i < flips.length(); i++) {
        if (flips[i] == 'H') {
            hFlips++;
        }
        else {
            vFlips++;
        }
    }
    if (hFlips % 2 != 0) {
        h = true;
    }
    if (vFlips % 2 != 0) {
        v = true;
    }
    if (h && v) {
        cout << "4 3" << endl << "2 1";
    }
    else if (h) {
        cout << "3 4" << endl << "1 2";
    }
    else if (v) {
        cout << "2 1" << endl << "4 3";
    }
    else {
        cout << "1 2" << endl << "3 4";
    }
}