#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    //freopen("1.input", "r", stdin); // For testing. Comment out for submissions

    map<char, int> found_chars;

    char ans[3][3];

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            char c; cin >> c;

            if (found_chars.find(c) == found_chars.end()) {
                found_chars[c] = 1;
            } else {
                found_chars[c]++;
            }

            ans[i][j] = c;
        }
    }

    char attempt[3][3];
    int green, yellow;
    green = yellow = 0;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            char c; cin >> c;

            // find greens first
            if (c == ans[i][j]) {
                green++;
                found_chars[c]--;
                attempt[i][j] = '.';
            } else {
                attempt[i][j] = c;
            }
        }
    }

    // find yellows
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            char c = attempt[i][j];
            if (c == '.') {
                continue;
            }

            if (found_chars[c] > 0) {
                yellow++;
                found_chars[c]--;
            }
        }
    }

    cout << green << endl;
    cout << yellow << endl;

    return 0;
}