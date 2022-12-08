#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    string input, cyclic, cyclic_c, cyclicSubstr;
    char tempChar, end;
    cin >> input >> cyclic;
    int inputLen = input.length();
    const int cyclicLen = cyclic.length();
    cyclic_c = cyclic;
    string cyclics[cyclicLen];
    //rotation
    for (int i = 0; i < cyclicLen; i++) {
        cyclics[i] = cyclic_c.substr(i, cyclicLen) + cyclic_c.substr(0, i);
    }
    //check if cyclic is input
    /*if (cyclics[0].length() == inputLen) {
        for (string i : cyclics) {
            if (input == i) {
                cout << "yes" << endl;
                return 0;
            }
        }
    }*/
    for (int i = cyclicLen; i <= inputLen; i++) {
        cyclicSubstr = input.substr(i - cyclicLen, cyclicLen);
        for (string j : cyclics) {
            if (cyclicSubstr == j) {
                cout << "yes" << endl;
                return 0;
            }
        }
    }
    cout << "no";
}