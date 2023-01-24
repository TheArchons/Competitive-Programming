#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    //freopen("2.input", "r", stdin); // for testing
    
    int rows, columns;
    cin >> rows >> columns;

    vector<vector<bool>> grid(rows, vector<bool>(columns));
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            bool isOn;
            cin >> isOn;

            grid[i][j] = isOn;
        }
    }

    set<vector<bool>> result;
    result.insert(grid[rows - 1]);

    for (int i = 1; i < rows; i++) {
        vector<vector<bool>> tempGrid = grid;
        for (int j = i; j < rows; j++) {
            for (int k = 0; k < columns; k++) {
                tempGrid[j][k] = tempGrid[j][k] != tempGrid[j - 1][k];
            }
        }

        result.insert(tempGrid[rows - 1]);
    }

    cout << result.size() << endl;
}