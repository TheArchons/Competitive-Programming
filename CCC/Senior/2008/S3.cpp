#include <bits/stdc++.h>

using namespace std;

void solve() {
    int rows; cin >> rows;
    int columns; cin >> columns;

    vector<vector<char>> grid(rows, vector<char>(columns));

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            char c; cin >> c;
            grid[i][j] = c;
        }
    }

    vector<vector<int>> dijkstra(rows, vector<int>(columns, -1));

    priority_queue<tuple<int, int, int>> pq; // x, y, distance
    pq.push({0, 0, 1});

    while (!pq.empty()) {
        auto [x, y, distance] = pq.top();
        pq.pop();

        if (x < 0 || x >= rows || y < 0 || y >= columns) continue;
        if (grid[x][y] == '*') continue;
        if (dijkstra[x][y] <= distance && dijkstra[x][y] != -1) continue;

        dijkstra[x][y] = distance;

        if (grid[x][y] == '|' || grid[x][y] == '+') {
            pq.push({x + 1, y, distance + 1});
            pq.push({x - 1, y, distance + 1});
        }

        if (grid[x][y] == '-' || grid[x][y] == '+') {
            pq.push({x, y + 1, distance + 1});
            pq.push({x, y - 1, distance + 1});
        }
    }

    cout << dijkstra[rows - 1][columns - 1] << endl;
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    //freopen("3.input", "r", stdin); // for testing. Comment out for submissions

    int testCases; cin >> testCases;

    while (testCases--) {
        solve();
    }

    return 0;
}