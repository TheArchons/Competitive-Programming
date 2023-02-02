#include <bits/stdc++.h>

using namespace std;

struct itemStruct {
    int weight;
    int value;
};

#define ll long long

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    freopen("e.input", "r", stdin); // for testing

    int itemNum, maxWeight;
    cin >> itemNum >> maxWeight;

    // first = weight, second = value
    vector<itemStruct> items(itemNum);
    for (int i = 0; i < itemNum; i++) {
        cin >> items[i].weight >> items[i].value;
    }

    vector<vector<ll>> dp(itemNum + 1, vector<ll>(pow(10, 5) + 1, -1));

    for (int i = 0; i < itemNum; i++) {
        itemStruct currItem = items[i];
        for (int j = 0; j <= pow(10, 5); j++) {
            if (j - currItem.value < 0) {
                dp[i + 1][j] = dp[i][j];
            } else if (dp[i][j - currItem.value] != -1) {
                if (!dp[i][j] || dp[i][j] == -1) {
                    dp[i + 1][j] = dp[i][j - currItem.value] + currItem.weight;
                } else {
                    dp[i + 1][j] = min(dp[i][j - currItem.value] + currItem.weight, dp[i][j]);
                }
            } else if (j == currItem.value) {
                dp[i + 1][j] = currItem.weight;
            } else {
                dp[i + 1][j] = dp[i][j];
            }
        }
    }

    int maxVal = 0;
    for (int i = 0; i <= pow(10, 5); i++) {
        if (dp[itemNum][i] != -1 && dp[itemNum][i] <= maxWeight) {
            maxVal = max(maxVal, i);
        }
    }

    cout << maxVal << endl;

    return 0;
}