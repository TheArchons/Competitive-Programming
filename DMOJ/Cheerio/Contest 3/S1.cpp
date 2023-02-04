#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> grid;

void addCone(int i, int j) {
    // if out of bounds, return
    if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size()) return;

    // if not empty, return
    if (grid[i][j]) return;

    // add cone
    grid[i][j] = 2;
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    //freopen("1.input", "r", stdin); // for testing. Comment out for submissions

    int height; cin >> height;
    int width; cin >> width;

    // 0 = empty, 1 = water, 2 = cone
    grid.resize(height, vector<int>(width, 0));

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            char c; cin >> c;

            grid[i][j] = c == 'W';
        }
    }

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (grid[i][j] == 1) {
                addCone(i + 1, j);
                addCone(i, j + 1);
                addCone(i - 1, j);
                addCone(i, j - 1);
            }
        }
    }

    // print grid
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int curr = grid[i][j];

            if (curr == 0) cout << '.';
            else if (curr == 1) cout << 'W';
            else if (curr == 2) cout << 'C';
        }
        
        cout << "\n";
    }

    return 0;
}