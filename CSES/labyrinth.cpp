// https://cses.fi/problemset/task/1193
#include <bits/stdc++.h>

using namespace std;

vector<vector<pair<int, char>>> minPath;
queue<pair<int, int>> q;
vector<vector<int>> grid;

void check(int height, int width, int curr, char dir) {
    if (height < 0 || height >= grid.size() || width < 0 || width >= grid[0].size() || grid[height][width] == -1) {
        return;
    }

    if (minPath[height][width].first > curr + 1) {
        minPath[height][width] = {curr + 1, dir};
        q.push({height, width});
    }

    return;
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    // freopen("labyrinth.input", "r", stdin); // For testing. Comment out for submissions

    int height; cin >> height;
    int width; cin >> width;

    grid.resize(height, vector<int>(width, 0));

    int startHeight, startWidth, endHeight, endWidth;

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            char c; cin >> c;

            if (c == '#') {
                grid[i][j] = -1;
            } else if (c == 'A') {
                startHeight = i;
                startWidth = j;
            } else if (c == 'B') {
                endHeight = i;
                endWidth = j;
            }
        }
    }

    minPath.resize(height, vector<pair<int, char>>(width, {INT_MAX, 'x'}));
    minPath[startHeight][startWidth] = {0, 'x'};

    q.push({startHeight, startWidth});

    while (!q.empty()) {
        int height = q.front().first;
        int width = q.front().second;
        int curr = minPath[height][width].first;

        q.pop();

        // up
        check(height - 1, width, curr, 'U');

        // down
        check(height + 1, width, curr, 'D');

        // left
        check(height, width - 1, curr, 'L');

        // right
        check(height, width + 1, curr, 'R');
    }

    int endDist = minPath[endHeight][endWidth].first;

    if (endDist == INT_MAX) {
        cout << "NO" << endl;
        return 0;
    }

    cout << "YES" << endl;
    cout << endDist << endl;

    string path = "";

    int currHeight = endHeight;
    int currWidth = endWidth;

    while (!(currHeight == startHeight && currWidth == startWidth)) {
        char dir = minPath[currHeight][currWidth].second;
        path.push_back(dir);

        if (dir == 'U') {
            currHeight++;
        } else if (dir == 'D') {
            currHeight--;
        } else if (dir == 'L') {
            currWidth++;
        } else if (dir == 'R') {
            currWidth--;
        }
    }

    reverse(path.begin(), path.end());

    cout << path << endl;

    return 0;
}