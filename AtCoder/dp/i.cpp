#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    //freopen("i.input", "r", stdin); // For testing. Comment out for submissions

    int coinNum; cin >> coinNum;

    vector<double> coins(coinNum);

    for (int i = 0; i < coinNum; i++) {
        cin >> coins[i];
    }

    vector<vector<double>> dp(coinNum + 2, vector<double>(coinNum + 2, 0));

    dp[1][1] = 1;

    for (int i = 1; i <= coinNum + 1; i++) {
        for (int j = 1; j <= i; j++) {
            if (i == 1 && j == 1) continue;

            double currP = coins[i - 2];

            dp[i][j] = dp[i - 1][j - 1] * currP + dp[i - 1][j] * (1 - currP);
        }
    }

    double ans = 0;

    for (int i = (coinNum + 1) / 2 + 1; i <= coinNum + 1; i++) {
        ans += dp[coinNum + 1][i];
    }

    cout << fixed << setprecision(10) << ans << endl;

    return 0;
}