#include <bits/stdc++.h>

using namespace std;

int sideLen;

bool isOutOfBounds(int x, int y) {
    return x < 0 || x >= sideLen || y < 0 || y >= sideLen;
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    //freopen("GridPaths.input", "r", stdin); // for testing
    
    cin >> sideLen;

    vector<vector<bool>> grid(sideLen, vector<bool>(sideLen, true));

    for (int i = 0; i < sideLen; i++) {
        for (int j = 0; j < sideLen; j++) {
            char c;
            cin >> c;
            grid[i][j] = c == '.';
        }
    }

    vector<vector<int>> dp(sideLen, vector<int>(sideLen, 0));
    dp[0][0] = grid[0][0] ? 1 : 0;

    for (int i = 0; i < sideLen; i++) {
        for (int j = 0; j < sideLen; j++) {
            if (grid[i][j]) {
                if (!isOutOfBounds(i - 1, j)) {
                    dp[i][j] += dp[i - 1][j];
                    dp[i][j] %= 1000000007;
                }

                if (!isOutOfBounds(i, j - 1)) {
                    dp[i][j] += dp[i][j - 1];
                    dp[i][j] %= 1000000007;
                }
            }
        }
    }

    cout << dp[sideLen - 1][sideLen - 1] << endl;
    
    return 0;
}