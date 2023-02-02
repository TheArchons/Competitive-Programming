#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    //freopen("2.input", "r", stdin); // for testing. Comment out for submissions

    int columnNum; cin >> columnNum;
    vector<bool> row1(columnNum);
    vector<bool> row2(columnNum);

    for (int i = 0; i < columnNum; i++) {
        char c; cin >> c;
        row1[i] = c == 'S';
    }

    for (int i = 0; i < columnNum; i++) {
        char c; cin >> c;
        row2[i] = c == 'S';
    }

    int removeRequired = 0;
    for (int i = 0; i < columnNum; i++) {
        if (row1[i] && row2[i]) {
            removeRequired++;
        }
    }

    if (removeRequired > 2) {
        cout << "NO\n"; 
    } else {
        cout << "YES\n";
    }

    return 0;
}