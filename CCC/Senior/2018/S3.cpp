#include <bits/stdc++.h>

using namespace std;

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
                grid[i][j] = 'W';

                // travel through all four directions
                
                // up
                for (int k = i - 1; k >= 0; k--) {
                    if (grid[k][j] == 'W') {
                        break;
                    }
                    if (grid[k][j] == '.') {
                        grid[k][j] = 'W';
                    }
                }

                // down
                for (int k = i + 1; k < height; k++) {
                    if (grid[k][j] == 'W') {
                        break;
                    }
                    if (grid[k][j] == '.') {
                        grid[k][j] = 'W';
                    }
                }

                // left
                for (int k = j - 1; k >= 0; k--) {
                    if (grid[i][k] == 'W') {
                        break;
                    }
                    if (grid[i][k] == '.') {
                        grid[i][k] = 'W';
                    }
                }

                // right
                for (int k = j + 1; k < width; k++) {
                    if (grid[i][k] == 'W') {
                        break;
                    }
                    if (grid[i][k] == '.') {
                        grid[i][k] = 'W';
                    }
                }
            }
        }
    }

    // BFS
    queue<tuple<int, int, int>> q; // x, y, distance
    q.push({start.first, start.second, 0});

    while (!q.empty()) {
        auto [x, y, distance] = q.front();
        q.pop();

        char curr = grid[x][y];

        if (curr == 'W') {
            continue;
        }

        distances[x][y] = distance;

        if (curr == '.') distance++;

        // travel through all four directions if the curr distance is less than the distance at the next position
        
        if (x - 1 >= 0 && (distances[x - 1][y] > distance || distances[x - 1][y] == -1) && (curr == '.' || curr == 'U')) {
            q.push({x - 1, y, distance});
        }

        if (x + 1 < height && (distances[x + 1][y] > distance || distances[x + 1][y] == -1) && (curr == '.' || curr == 'D')) {
            q.push({x + 1, y, distance});
        }

        if (y - 1 >= 0 && (distances[x][y - 1] > distance || distances[x][y - 1] == -1) && (curr == '.' || curr == 'L')) {
            q.push({x, y - 1, distance});
        }

        if (y + 1 < width && (distances[x][y + 1] > distance || distances[x][y + 1] == -1) && (curr == '.' || curr == 'R')) {
            q.push({x, y + 1, distance});
        }
    }

    // print distances
    for (auto [x, y] : empties) {
        cout << distances[x][y] << endl;
    }

    return 0;
}