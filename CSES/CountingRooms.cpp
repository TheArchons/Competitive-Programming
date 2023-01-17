// https://cses.fi/problemset/task/1192

#include <bits/stdc++.h>

using namespace std;

vector<vector<bool>> grid;
int rooms = 0;

bool floodFill(int i, int j) {
    // if invalid, return
    bool curr = grid[i][j];
    if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || !curr) return false;

    grid[i][j] = false;

    // search all 4 directions
    floodFill(i + 1, j);
    floodFill(i - 1, j);
    floodFill(i, j + 1);
    floodFill(i, j - 1);

    return true;
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    //freopen("CountingRooms.input", "r", stdin); // for testing
    
    int height, width;
    cin >> height >> width;

    grid.resize(height, vector<bool>(width));

    for (int i = 0; i < height; i++) {        for (int j = 0; j < width; j++) {
            char c;
            cin >> c;
            grid[i][j] = c == '.';
        }
    }

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (floodFill(i, j)) rooms++;
        }
    }

    cout << rooms << endl;
}