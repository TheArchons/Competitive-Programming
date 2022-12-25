#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    //freopen("2.input", "r", stdin); // for testing
    
    int charNum;
    cin >> charNum;

    map<string, char> codes;

    for (int i = 0; i < charNum; i++) {
        char c;
        cin >> c;

        string code;
        cin >> code;

        codes[code] = c;
    }

    string code;
    cin >> code;

    int tail, head;
    tail = head = 0;

    while (head < code.length()) {
        string currCode = code.substr(tail, head - tail + 1);
        if (codes.find(currCode) != codes.end()) {
            cout << codes[currCode];
            tail = head + 1;
        }
        head++;
    }

    cout << endl;
    return 0;
}