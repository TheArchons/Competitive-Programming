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
    for (int i = 0; i < cyclicLen; i++) {
        cyclics[i] = cyclic_c;
        tempChar = cyclic_c[0];
        rotate(&cyclic_c[0], &cyclic_c[1], &cyclic_c[10]);
        cyclic_c[cyclicLen-1] = tempChar;
    }
    for (int i = cyclicLen; i < inputLen; i++) {
        cyclicSubstr = input.substr(i - cyclicLen, cyclicLen);
        for (int j = 0; j < cyclicLen; j++) {
            if (cyclicSubstr == cyclics[j]) {
                cout << "yes";
                return 0;
            }
        }
    }
    cout << "no";
}