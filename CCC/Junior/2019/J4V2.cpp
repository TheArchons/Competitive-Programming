#include <iostream>
#include <string>
using namespace std;

pair<bool, bool> countFlips(string flip) {
    bool HEven, VEven;
    HEven = VEven = true;
    for (int i = 0; i < flip.length(); i++) {
        if (flip[i] == 'H') {
            HEven = !HEven;
        } else {
            VEven = !VEven;
        }
    }
    return make_pair(HEven, VEven);
}

void printFlips(bool H, bool V) {
    if (H && V) {
        cout << "1 2" << endl << "3 4";
    }
    else if (H) {
        cout << "2 1" << endl << "4 3";
    }
    else if (V) {
        cout << "3 4" << endl << "1 2";
    }
    else {
        cout << "4 3" << endl << "2 1";
    }
}

int main() {
    string flipDs;
    cin >> flipDs;
    pair<bool, bool> flip = countFlips(flipDs);
    printFlips(flip.first, flip.second);
}