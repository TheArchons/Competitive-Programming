#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    //freopen("1.input", "r", stdin); // for testing
    freopen("herding.in", "r", stdin); freopen("herding.out", "w", stdout); // for submission
    
    vector<int> cows(3);
    for (int i = 0; i < 3; i++) {
        cin >> cows[i];
    }

    sort(cows.begin(), cows.end());

    // get min
    // if all 3 are the same, then 0
    // if 2 cows are 1 apart, then 1
    // else, 2

    int min = 2;
    bool found = true;
    for (int i = 1; i < 3; i++) {
        if (cows[i] - cows[i - 1] != 1) {
            found = false;
            break;
        }
    }

    if (found) {
        cout << 0 << endl << 0 << endl;
        return 0;
    }

    for (int i = 1; i < 3; i++) {
        if (cows[i] - cows[i-1] == 2) {
            found = true;
            break;
        }
    }

    if (found) {
        min = 1;
    }

    cout << min << endl;

    // get max
    // max distance of two consecutive cows - 1
    cout << max(cows[1] - cows[0], cows[2] - cows[1]) - 1 << endl;
    
    return 0;
}