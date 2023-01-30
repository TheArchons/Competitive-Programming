#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    //freopen("b.input", "r", stdin); // for testing

    int stoneNum, maxJump;
    cin >> stoneNum >> maxJump;

    vector<int> stones(stoneNum);
    for (int i = 0; i < stoneNum; i++) {
        cin >> stones[i];
    }

    vector<int> dp(stoneNum, INT_MAX);
    dp[0] = 0;

    for (int i = 0; i < stoneNum; i++) {
        for (int j = 1; j <= maxJump && j + i < stoneNum; j++) {
            int diff = abs(stones[i] - stones[i+j]);
            dp[i+j] = min(dp[i+j], dp[i] + diff);
        }
    }

    cout << dp[stoneNum-1] << endl;

    return 0;
}