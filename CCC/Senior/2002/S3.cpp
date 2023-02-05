#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> grid;

vector<char> directions;

int directionNum, rowNum, columnNum;

// 0 = up, 1 = right, 2 = down, 3 = left
void traverse(int row, int column, int direction) {
    for (int i = 0; i < directionNum; i++) {
        char currDirection = directions[i];

        if (currDirection == 'L') {
            direction -= 1;
            if (direction < 0) direction = 3;
        } else if (currDirection == 'R') {
            direction += 1;
            if (direction > 3) direction = 0;
        } else {
            if (direction == 0) {
                row -= 1;
            } else if (direction == 1) {
                column += 1;
            } else if (direction == 2) {
                row += 1;
            } else {
                column -= 1;
            }

            // if out of bounds or blocked
            if (row < 0 || row >= rowNum || column < 0 || column >= columnNum || !grid[row][column]) {
                return;
            }
        }
    }

    grid[row][column] = 2;

    return;
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    //freopen("3.input", "r", stdin); // for testing. Comment out for submissions

    rowNum; cin >> rowNum; columnNum; cin >> columnNum;

    grid.resize(rowNum, vector<int>(columnNum)); // 0 = blocked, 1 = open, 2 = possible end position

    for (int i = 0; i < rowNum; i++) {
        for (int j = 0; j < columnNum; j++) {
            char c; cin >> c;

            grid[i][j] = c == '.';
        }
    }

    directionNum; cin >> directionNum;

    directions.reserve(directionNum);

    for (int i = 0; i < directionNum; i++) {
        cin >> directions[i];
    }

    for (int i = 0; i < rowNum; i++) {
        for (int j = 0; j < columnNum; j++) {
            if (!grid[i][j]) continue;

            traverse(i, j, 0);
            traverse(i, j, 1);
            traverse(i, j, 2);
            traverse(i, j, 3);
        }
    }

    for (int i = 0; i < rowNum; i++) {
        for (int j = 0; j < columnNum; j++) {
            int curr = grid[i][j];
            if (curr == 0) {
                cout << 'X';
            } else if (curr == 1) {
                cout << '.';
            } else {
                cout << '*';
            }
        }
        cout << '\n';
    }

    return 0;
}