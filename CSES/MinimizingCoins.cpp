// https://cses.fi/problemset/task/1634

#include <bits/stdc++.h>

using namespace std;

int dp[1000001];

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    //freopen("MinimizingCoins.input", "r", stdin); // for testing

    memset(dp, -1, sizeof(dp));
    
    int coinNum, target;
    cin >> coinNum >> target;

    vector<int> coins(coinNum);
    for (int i = 0; i < coinNum; i++) {
        cin >> coins[i];
    }

    dp[0] = 0;

    for (int i = 0; i < target; i++) {
        if (dp[i] == -1) {
            continue;
        }

        for (int j = 0; j < coinNum; j++) {
            int coin = coins[j];

            if (i + coin > target) {
                continue;
            }

            if (dp[i+coin] == -1) {
                dp[i+coin] = dp[i] + 1;
            } else {
                dp[i+coin] = min(dp[i+coin], dp[i] + 1);
            }
        }
    }

    cout << dp[target];
}