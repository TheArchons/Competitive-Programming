#include <bits/stdc++.h>

using namespace std;

int total, currPrice, sideLen;

vector<vector<bool>> grid; // true = right, false = down

bool checkValid(int row, int col) {
    return row >= 0 && row < sideLen && col >= 0 && col < sideLen;
}

void dfs(int row, int col){
    total += currPrice;
    // up
    if (checkValid(row - 1, col)) {
        if (!grid[row - 1][col]) {
            dfs(row - 1, col);
        }
    }

    // left
    if (checkValid(row, col - 1)) {
        if (grid[row][col - 1]) {
            dfs(row, col - 1);
        }
    }
}


int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    //freopen("2.input", "r", stdin); // for testing

    cin >> sideLen;
    grid.resize(sideLen, vector<bool>(sideLen));
    vector<int> rightVats(sideLen);
    for (int i = 0; i < sideLen; i++) {
        for (int j = 0; j < sideLen; j++) {
            char c;
            cin >> c;
            grid[i][j] = c == 'R';
        }

        int vat;
        cin >> vat;

        rightVats[i] = vat;
    }

    vector<int> bottomVats(sideLen);
    for (int i = 0; i < sideLen; i++) {
        int vat;
        cin >> vat;

        bottomVats[i] = vat;
    }

    int flips;
    cin >> flips;
    map<vector<vector<bool>>, int> visited;
    vector<vector<int>> carries(sideLen, vector<int>(sideLen));

    for (int j = 0; j <= flips; j++) {
        if (j != 0) {
            int row, col;
            cin >> row >> col;
            row--;
            col--;

            grid[row][col] = !grid[row][col];
        }

        if (visited.find(grid) != visited.end()) {
            cout << visited[grid] << endl;
            continue;
        }

        total = 0;
        for (int i = 0; i < sideLen; i++) {
            if (grid[i][sideLen - 1]) {
                currPrice = rightVats[i];
                dfs(i, sideLen - 1);
            }
        }

        for (int i = 0; i < sideLen; i++) {
            if (!grid[sideLen - 1][i]) {
                currPrice = bottomVats[i];
                dfs(sideLen - 1, i);
            }
        }

        visited[grid] = total;

        cout << total << endl;
    }

    return 0;
}