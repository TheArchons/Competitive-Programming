// https://cses.fi/problemset/task/1636

#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    //freopen("CoinCombinations2.input", "r", stdin); // for testing
    
    int coinNum, target;

    cin >> coinNum >> target;

    vector<int> coins(coinNum);

    for (int i = 0; i < coinNum; i++) {
        cin >> coins[i];
    }

    vector<int> maxInt(target+1, 0);
    vector<int> dp(target+1, 0);

    dp[0] = 1;

    for (int i = 0; i < coinNum; i++) {
        int coin = coins[i];

        for (int j = 0; j < target; j++) {
            if (j + coin > target) {
                continue;
            }

            dp[j+coin] += dp[j];
            dp[j+coin] %= 1000000007;
        }
    }

    cout << dp[target];
}