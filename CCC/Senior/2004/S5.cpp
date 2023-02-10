#include <bits/stdc++.h>

using namespace std;

int rowNum; int columnNum;

// for each column (except for the first), try both going up and going down.
// Starting from any row not at the bottommost or topmost is never better than starting from the top/bottom
//    because the previous rows can only increase the score, not decrease it

bool inBounds(int row, int column) {
    return column >= 0 && column < columnNum && row >= 0 && row < rowNum;
}

void solve() {
    int grid[rowNum][columnNum] = {0};
    int dp[rowNum][columnNum] = {0};

    for (int i = 0; i < rowNum; i++) {
        for (int j = 0; j < columnNum; j++) {
            char c; cin >> c;

            if (c == '.') {
                grid[i][j] = 0;
            } else if (c == '*') {
                grid[i][j] = -1;
            } else {
                grid[i][j] = c - '0';
            }
        }
    }

    for (int column = 0; column < columnNum; column++) {
        int downMaxVals[rowNum] = {0};

        if (column) {
            for (int row = 0; row < rowNum; row++) {
                if (grid[row][column] == -1) {
                    continue;
                }

                int maxVal = 0;

                if (inBounds(row, column - 1)) {
                    maxVal = max(maxVal, dp[row][column - 1]);
                }

                if (inBounds(row - 1, column)) {
                    maxVal = max(maxVal, downMaxVals[row - 1]);
                }

                downMaxVals[row] = maxVal + grid[row][column];
            }
        }

        int upMaxVals[rowNum] = {0};
        for (int row = rowNum - 1; row >= 0; row--) {
            if (grid[row][column] == -1) {
                continue;
            }

            int maxVal = 0;

            if (inBounds(row, column - 1)) {
                maxVal = max(maxVal, dp[row][column - 1]);
            }

            if (inBounds(row + 1, column)) {
                maxVal = max(maxVal, upMaxVals[row + 1]);
            }

            upMaxVals[row] = maxVal + grid[row][column];
        }

        for (int i = 0; i < rowNum; i++) {
            dp[i][column] = max(downMaxVals[i], upMaxVals[i]);
        }
    }

    cout << dp[rowNum - 1][columnNum - 1] << endl;

    return;
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    //freopen("5.input", "r", stdin); // for testing. Comment out for submissions

    cin >> rowNum >> columnNum;

    while (rowNum != 0 && columnNum != 0) {
        solve();

        cin >> rowNum >> columnNum;
    }

    return 0;
}