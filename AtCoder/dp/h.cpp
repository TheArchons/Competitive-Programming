#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    //freopen("h.input", "r", stdin); // For testing. Comment out for submissions

    int rowNum; cin >> rowNum;
    int columnNum; cin >> columnNum;

    vector<vector<bool>> grid(rowNum + 1, vector<bool>(columnNum + 1, false));
    vector<vector<int>> dp(rowNum + 1, vector<int>(columnNum + 1, 0));
    dp[1][1] = 1;

    for (int i = 1; i <= rowNum; i++) {
        for (int j = 1; j <= columnNum; j++) {
            char c; cin >> c;

            grid[i][j] = c == '.';
        }
    }

    for (int i = 1; i <= rowNum; i++) {
        for (int j = 1; j <= columnNum; j++) {
            if (i == 1 && j == 1) continue;

            if (grid[i][j]) {
                dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % 1000000007;
            }
        }
    }

    cout << dp[rowNum][columnNum] << endl;

    return 0;
}