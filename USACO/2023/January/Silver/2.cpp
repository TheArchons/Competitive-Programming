#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> costs;
vector<vector<bool>> grid; // true if right, false if down
vector<int> endColumn, endRow;
int totalCost = 0;
int sideLen;

bool inBounds(int column, int row) {
    return column >= 0 && column < sideLen && row >= 0 && row < sideLen;
}

void dfs(int column, int row, int cost, int originalCost) {
    totalCost -= originalCost;
    totalCost += cost;
    costs[row][column] = cost;

    // top
    row -= 1;
    if (inBounds(column, row) && !grid[row][column]) {
        dfs(column, row, cost, originalCost);
    }

    // left
    row += 1;
    column -= 1;

    if (inBounds(column, row) && grid[row][column]) {
        dfs(column, row, cost, originalCost);
    }
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    //freopen("2.input", "r", stdin); // for testing. Comment out for submissions

    cin >> sideLen;

    grid.resize(sideLen, vector<bool>(sideLen));
    endColumn.resize(sideLen);
    endRow.resize(sideLen);


    for (int i = 0; i < sideLen; i++) {
        for (int j = 0; j < sideLen; j++) {
            char c; cin >> c;
            grid[i][j] = c == 'R';
        }

        cin >> endColumn[i];
    }

    for (int i = 0; i < sideLen; i++) {
        cin >> endRow[i];
    }

    costs.resize(sideLen, vector<int>(sideLen, 0));

    for (int i = 0; i < sideLen; i++) {
        if (grid[i][sideLen - 1]) {
            dfs(sideLen - 1, i, endColumn[i], 0);
        }
    }

    for (int i = 0; i < sideLen; i++) {
        if (!grid[sideLen - 1][i]) {
            dfs(i, sideLen - 1, endRow[i], 0);
        }
    }

    cout << totalCost << endl;

    int queryNum; cin >> queryNum;

    for (int i = 0; i < queryNum; i++) {
        int queryRow; cin >> queryRow;
        int queryColumn; cin >> queryColumn;

        queryRow--; queryColumn--;

        // flip
        grid[queryRow][queryColumn] = !grid[queryRow][queryColumn];

        // traverse
        int tempRow = queryRow;
        int tempColumn = queryColumn;
        int originalCost = costs[tempRow][tempColumn];
        int newCost;

        while (true) {
            if (grid[tempRow][tempColumn]) {
                if (inBounds(tempColumn + 1, tempRow)) {
                    tempColumn += 1;
                } else {
                    break;
                }
            } else {
                if (inBounds(tempColumn, tempRow + 1)) {
                    tempRow += 1;
                } else {
                    break;
                }
            }
        }

        if (grid[tempRow][tempColumn]) {
            newCost = endColumn[tempRow];
        } else {
            newCost = endRow[tempColumn];
        }

        dfs(queryColumn, queryRow, newCost, originalCost);

        cout << totalCost << endl;
    }

    return 0;
}