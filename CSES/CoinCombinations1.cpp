// https://cses.fi/problemset/task/1635

#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    //freopen("CoinCombinations1.input", "r", stdin); // for testing
    
    int coinNum, target;
    cin >> coinNum >> target;

    vector<int> coins(coinNum);

    for (int i = 0; i < coinNum; i++) {
        cin >> coins[i];
    }

    vector<long long int> dp(target+1, 0);
    dp[0] = 1;

    for (int i = 0; i < target; i++) {
        for (int j = 0; j < coinNum; j++) {
            int coin = coins[j];

            if (i + coin > target) {
                continue;
            }

            dp[i+coin] += dp[i];
            dp[i+coin] %= 1000000007;
        }
    }

    cout << dp[target];
}