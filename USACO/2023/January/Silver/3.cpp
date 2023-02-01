#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    //freopen("3.input", "r", stdin); // for testing

    int maxLoc;
    cin >> maxLoc;

    vector<int> crosses(maxLoc);
    int total = 0;

    for (int i = 0; i < maxLoc; i++) {
        cin >> crosses[i];
        total += crosses[i];
    }

    int currLoc = 0;
    string ans = "";

    while (total > 0) {
        // go right
        while (currLoc < maxLoc && (!currLoc || crosses[currLoc - 1]) && crosses[currLoc]) {
            currLoc++;
            crosses[currLoc - 1]--;
            total--;
            ans += "R";
        }

        // go left (if possible)
        while (currLoc > 0 && (crosses[currLoc - 1] > 1 || (currLoc == maxLoc || !crosses[currLoc]))) {
            crosses[currLoc - 1]--;
            total--;
            currLoc--;
            ans += "L";
        }
    }

    cout << ans << endl;

    return 0;
}