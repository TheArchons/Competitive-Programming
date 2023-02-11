#include <bits/stdc++.h>

using namespace std;

int maxRiceBall = 0;

set<vector<int>> visited;

void combineBalls(vector<int> riceBalls, int currMaxRiceBall) {
    maxRiceBall = max(maxRiceBall, currMaxRiceBall);

    if (riceBalls.size() == 1) {
        return;
    }

    if (visited.find(riceBalls) != visited.end()) {
        return;
    }

    visited.insert(riceBalls);

    int riceBallNum = riceBalls.size();

    for (int i = 1; i < riceBallNum; i++) {
        if (riceBalls[i] == riceBalls[i - 1]) {
            vector<int> newRiceBalls(riceBalls);
            newRiceBalls.erase(newRiceBalls.begin() + i);
            newRiceBalls[i - 1] *= 2;
            combineBalls(newRiceBalls, max(currMaxRiceBall, newRiceBalls[i - 1]));
        }
    }
    
    for (int i = 2; i < riceBallNum; i++) {
        if (riceBalls[i] == riceBalls[i - 2]) {
            vector<int> newRiceBalls(riceBalls);
            newRiceBalls[i - 2] += riceBalls[i] + riceBalls[i - 1];
            newRiceBalls.erase(newRiceBalls.begin() + i);
            newRiceBalls.erase(newRiceBalls.begin() + i - 1);
            combineBalls(newRiceBalls, max(currMaxRiceBall, newRiceBalls[i - 2]));
        }
    }

    return;
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    //freopen("4.input", "r", stdin); // for testing. Comment out for submissions

    int riceBallNum; cin >> riceBallNum;

    vector<int> riceBalls(riceBallNum);

    for (int i = 0; i < riceBallNum; i++) {
        cin >> riceBalls[i];
        maxRiceBall = max(maxRiceBall, riceBalls[i]);
    }

    combineBalls(riceBalls, 0);

    cout << maxRiceBall << endl;

    return 0;
}