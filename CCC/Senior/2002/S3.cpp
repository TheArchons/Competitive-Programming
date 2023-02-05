#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> grid;

vector<char> directions;

int directionNum, rowNum, columnNum;
int rightDiff = 0;
int forwardDiff = 0;

// 0 = up, 1 = right, 2 = down, 3 = left
void traverse(int row, int column, int direction) {
    int endRow, endColumn;
    endRow = row; endColumn = column;
    if (direction == 0) {
        endRow -= forwardDiff;
        endColumn += rightDiff;
    } else if (direction == 1) {
        endRow += rightDiff;
        endColumn += forwardDiff;
    } else if (direction == 2) {
        endRow += forwardDiff;
        endColumn -= rightDiff;
    } else {
        endRow -= rightDiff;
        endColumn -= forwardDiff;
    }

    if (endRow < 0 || endRow >= rowNum || endColumn < 0 || endColumn >= columnNum || !grid[endRow][endColumn]) {
        return;
    }

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

    // calculateDiff
    int currFacing = 0;

    for (int i = 0; i < directionNum; i++) {
        char currDirection = directions[i];

        if (currDirection == 'L') {
            currFacing -= 1;
            if (currFacing < 0) currFacing = 3;
        } else if (currDirection == 'R') {
            currFacing += 1;
            if (currFacing > 3) currFacing = 0;
        } else {
            if (currFacing == 0) {
                forwardDiff += 1;
            } else if (currFacing == 1) {
                rightDiff += 1;
            } else if (currFacing == 2) {
                forwardDiff -= 1;
            } else {
                rightDiff -= 1;
            }
        }
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