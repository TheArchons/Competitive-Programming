#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    //freopen("3.input", "r", stdin); // for testing

    int cases;
    cin >> cases;

    for (int j = 0; j < cases; j++) {
        vector<bool> letters; // true = M, false = O
        bool found = false;
        
        string s;
        cin >> s;
        int letterNum = s.length();
        for (int j = 0; j < letterNum; j++) {
            letters.push_back(s[j] == 'M');
        }

        if (letterNum < 3) {
            cout << -1 << endl;
            continue;
        }

        // find MOO
        for (int i = 2; i < letterNum; i++) {
            if (!letters[i] && !letters[i - 1] && letters[i - 2]) {
                cout << letterNum - 3 << endl;
                found = true;
                break;
            }
        }

        if (found) continue;

        // find MOM
        for (int i = 2; i < letterNum; i++) {
            if (letters[i] && !letters[i - 1] && letters[i - 2]) {
                cout << letterNum - 2 << endl;
                found = true;
                break;
            }
        }

        if (found) continue;

        // find OOO
        for (int i = 2; i < letterNum; i++) {
            if (!letters[i] && !letters[i - 1] && !letters[i - 2]) {
                cout << letterNum - 2 << endl;
                found = true;
                break;
            }
        }

        if (found) continue;

        // find OOM
        for (int i = 2; i < letterNum; i++) {
            if (letters[i] && !letters[i - 1] && !letters[i - 2]) {
                cout << letterNum - 1 << endl;
                found = true;
                break;
            }
        }

        if (found) continue;

        cout << -1 << endl;
    }

    return 0;
}