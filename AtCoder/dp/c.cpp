#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    //freopen("c.input", "r", stdin); // for testing

    int dayNum;
    cin >> dayNum;

    vector<vector<int>> activities(dayNum, vector<int>(3));
    for (int i = 0; i < dayNum; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> activities[i][j];
        }
    }

    vector<vector<int>> dp(dayNum, vector<int>(3));
    dp[0] = activities[0];

    for (int i = 1; i < dayNum; i++) {
        dp[i][0] = activities[i][0] + max(dp[i - 1][1], dp[i - 1][2]);
        dp[i][1] = activities[i][1] + max(dp[i - 1][0], dp[i - 1][2]);
        dp[i][2] = activities[i][2] + max(dp[i - 1][0], dp[i - 1][1]);
    }

    int maxScore = 0;
    for (int i = 0; i < 3; i++) {
        maxScore = max(maxScore, dp[dayNum - 1][i]);
    }

    cout << maxScore << endl;

    return 0;
}