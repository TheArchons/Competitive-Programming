#include <bits/stdc++.h>

using namespace std;

// subtask 1 + 2

int getMax(vector<int> pies, int pieNum) {
    vector<int> dp(pieNum, 0);

    dp[0] = pies[0];

    if (pieNum == 1) {
        cout << dp[0] << endl;
        return 0;
    }

    dp[1] = max(pies[0], pies[1]);

    if (pieNum == 2) {
        cout << dp[1] << endl;
        return 0;
    }
    
    for (int i = 2; i < pieNum; i++) {
        dp[i] = max(dp[i - 1], dp[i - 2] + pies[i]);
    }

    return dp[pieNum - 1];
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    //freopen("5.input", "r", stdin); // for testing

    int originalPieNum;
    cin >> originalPieNum;

    vector<int> originalPies(originalPieNum);

    for (int i = 0; i < originalPieNum; i++) {
        cin >> originalPies[i];
    }

    int newPieNum;
    cin >> newPieNum;

    vector<int> newPies(newPieNum);

    for (int i = 0; i < newPieNum; i++) {
        cin >> newPies[i];
    }

    if (!newPieNum) {
        cout << getMax(originalPies, originalPieNum) << endl;
        return 0;
    }

    int max = 0;

    // insert first pie at all possible positions
    for (int i = 0; i <= originalPieNum; i++) {
        vector<int> pies = originalPies;
        pies.insert(pies.begin() + i, newPies[0]);
        int temp = getMax(pies, pies.size());
        if (temp > max) max = temp;
    }

    cout << max << endl;

    return 0;
}