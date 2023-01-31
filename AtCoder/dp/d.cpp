#include <bits/stdc++.h>

using namespace std;

#define ll long long int

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    //freopen("d.input", "r", stdin); // for testing

    int itemNum, maxWeight;
    cin >> itemNum >> maxWeight;

    vector<pair<int, int>> items(itemNum);
    for (int i = 0; i < itemNum; i++) {
        cin >> items[i].first >> items[i].second;
    }

    vector<vector<ll>> dp(itemNum + 1, vector<ll>(maxWeight + 1, 0));

    for (int i = 1; i <= itemNum; i++) {
        pair<int, int> item = items[i - 1];
        for (int j = 1; j <= maxWeight; j++) {
            if (j - item.first >= 0) {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - item.first] + item.second);
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    cout << dp[itemNum][maxWeight] << endl;

    return 0;
}