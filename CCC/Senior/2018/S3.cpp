#include <bits/stdc++.h>

using namespace std;

void printGrid(vector<vector<char>> grid) { // DEBUG
    for (auto row : grid) {
        for (auto col : row) {
            cout << col << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int main() {
    //freopen("3.input", "r", stdin); // for testing
    int height, width;
    cin >> height >> width;

    vector<vector<char>> grid;
    pair<int, int> start;

    vector<vector<int>> distances(height, vector<int>(width, -1));
    vector<pair<int, int>> empties;
    for (int i = 0; i < height; i++) {
        vector<char> row;
        for (int j = 0; j < width; j++) {
            char temp;
            cin >> temp;
            if (temp == '.') {
                empties.push_back({i, j});
            }
            if (temp == 'S') {
                start = {i, j};
                temp = '.';
            }
            row.push_back(temp);
        }
        grid.push_back(row);
    }

    // mark all cameras as walls
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (grid[i][j] == 'C') {
                grid[i][j] = 'T';

                // travel through all four directions
                
                // up
                for (int k = i - 1; k >= 0; k--) {
                    if (grid[k][j] == 'W') {
                        break;
                    }
                    if (grid[k][j] == '.' || grid[k][j] == 'T') {
                        grid[k][j] = 'T';
                    }
                }

                // down
                for (int k = i + 1; k < height; k++) {
                    if (grid[k][j] == 'W') {
                        break;
                    }
                    if (grid[k][j] == '.' || grid[k][j] == 'T') {
                        grid[k][j] = 'T';
                    }
                }

                // left
                for (int k = j - 1; k >= 0; k--) {
                    if (grid[i][k] == 'W') {
                        break;
                    }
                    if (grid[i][k] == '.' || grid[i][k] == 'T') {
                        grid[i][k] = 'T';
                    }
                }

                // right
                for (int k = j + 1; k < width; k++) {
                    if (grid[i][k] == 'W') {
                        break;
                    }
                    if (grid[i][k] == '.' || grid[i][k] == 'T') {
                        grid[i][k] = 'T';
                    }
                }
            }
        }
    }

    // set all temps to walls
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (grid[i][j] == 'T') {
                grid[i][j] = 'W';
            }
        }
    }

    // BFS
    queue<tuple<int, int, int>> q; // y, x, distance
    q.push({start.first, start.second, 0});

    while (!q.empty()) {
        auto [y, x, distance] = q.front();
        q.pop();

        char curr = grid[y][x];

        if (curr == '.') distance++;

        // travel through all four directions if the curr distance is less than the distance at the neyt position
        
        int newY = y - 1, newX = x;
        if (grid[newY][newX] != 'W' && (distances[newY][newX] > distance || distances[newY][newX] == -1) && (curr == '.' || curr == 'U')) {
            q.push({newY, newX, distance});
            distances[newY][newX] = distance;
        }

        newY = y + 1, newX = x;

        if (grid[newY][newX] != 'W' && (distances[newY][newX] > distance || distances[newY][newX] == -1) && (curr == '.' || curr == 'D')) {
            q.push({newY, newX, distance});
            distances[newY][newX] = distance;
        }

        newY = y, newX = x - 1;

        if (grid[newY][newX] != 'W' && (distances[newY][newX] > distance || distances[newY][newX] == -1) && (curr == '.' || curr == 'L')) {
            q.push({newY, newX, distance});
            distances[newY][newX] = distance;
        }

        newY = y, newX = x + 1;

        if (grid[newY][newX] != 'W' && (distances[newY][newX] > distance || distances[newY][newX] == -1) && (curr == '.' || curr == 'R')) {
            q.push({newY, newX, distance});
            distances[newY][newX] = distance;
        }
    }

    // print distances
    for (auto [y, x] : empties) {
        cout << distances[y][x] << endl;
    }

    return 0;
}