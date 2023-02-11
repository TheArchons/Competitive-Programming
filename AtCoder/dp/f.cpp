#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    //freopen("f.input", "r", stdin); // for testing. Comment out for submissions

    string string1; cin >> string1;
    string string2; cin >> string2;

    int string1Len = string1.length();
    int string2Len = string2.length();

    vector<vector<int>> dp(string1Len + 1, vector<int>(string2Len + 1, 0));

    vector<vector<pair<int, int>>> path(string1Len + 1, vector<pair<int, int>>(string2Len + 1, {0, 0}));
    
    for (int i = 1; i <= string1Len; i++) {
        for (int j = 1; j <= string2Len; j++) {
            char char1 = string1[i - 1];
            char char2 = string2[j - 1];

            if (char1 == char2) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                path[i][j] = {i - 1, j - 1};
            } else {
                if (dp[i - 1][j] > dp[i][j - 1]) {
                    dp[i][j] = dp[i - 1][j];
                    path[i][j] = {i - 1, j};
                } else {
                    dp[i][j] = dp[i][j - 1];
                    path[i][j] = {i, j - 1};
                }
            }
        }
    }

    string lcs = "";

    int x, y;
    x = string1Len;
    y = string2Len;

    while (x != 0 && y != 0) {
        if (path[x][y] == make_pair(x - 1, y - 1)) {
            lcs += string1[x - 1];
        }

        tie(x, y) = path[x][y];
    }

    for (int i = lcs.length() - 1; i >= 0; i--) {
        cout << lcs[i];
    }

    return 0;
}