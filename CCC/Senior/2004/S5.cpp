#include <bits/stdc++.h>

using namespace std;

int rowNum; int columnNum;

// for each column (except for the first), try both going up and going down.
// Starting from any row not at the bottommost or topmost is never better than starting from the top/bottom
//    because the previous rows can only increase the score, not decrease it

vector<vector<int>> grid;
vector<vector<int>> dp;

bool inBounds(int row, int column) {
    return column >= 0 && column < columnNum && row >= 0 && row < rowNum;
}

vector<int> calcDP(int row, int column, bool goingUp, vector<int> maxVals) {
    if (grid[row][column] == -1) {
        return maxVals;
    }

    int maxVal = 0;

    if (inBounds(row, column - 1)) {
        maxVal = max(maxVal, dp[row][column - 1]);
    }

    if (goingUp) {
        if (inBounds(row + 1, column)) {
            maxVal = max(maxVal, maxVals[row + 1]);
        }
    } else {
        if (inBounds(row - 1, column)) {
            maxVal = max(maxVal, maxVals[row - 1]);
        }
    }

    maxVals[row] = maxVal + grid[row][column];

    return maxVals;
}

void solve() {
    grid.resize(rowNum, vector<int>(columnNum, 0));
    dp.resize(rowNum, vector<int>(columnNum, 0));

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
        vector<int> downMaxVals(rowNum, 0);
        if (column) {
            for (int row = 0; row < rowNum; row++) {
                downMaxVals = calcDP(row, column, false, downMaxVals);
            }
        }

        vector<int> upMaxVals(rowNum, 0);
        for (int row = rowNum - 1; row >= 0; row--) {
            upMaxVals = calcDP(row, column, true, upMaxVals);
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