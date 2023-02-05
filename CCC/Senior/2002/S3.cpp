#include <bits/stdc++.h>

using namespace std;

set<pair<int, int>> checkPositions;
int rowNum, columnNum;
int finalAddRow, finalAddColumn;

vector<vector<int>> grid;

void traverse(int row, int column, int direction) {
    for (auto it = checkPositions.begin(); it != checkPositions.end(); it++) {
        int currRow, currColumn;
        
        if (direction == 0) {
            currRow = row - it->first;
            currColumn = column + it->second;
        } else if (direction == 1) {
            currRow = row + it->second;
            currColumn = column + it->first;
        } else if (direction == 2) {
            currRow = row + it->first;
            currColumn = column - it->second;
        } else if (direction == 3) {
            currRow = row - it->second;
            currColumn = column - it->first;
        }

        if (currRow < 0 || currRow >= rowNum || currColumn < 0 || currColumn >= columnNum || !grid[currRow][currColumn]) {
            return;
        }
    }

    if (direction == 0) {
        grid[row - finalAddRow][column + finalAddColumn] = 2;
    } else if (direction == 1) {
        grid[row + finalAddColumn][column + finalAddRow] = 2;
    } else if (direction == 2) {
        grid[row + finalAddRow][column - finalAddColumn] = 2;
    } else if (direction == 3) {
        grid[row - finalAddColumn][column - finalAddRow] = 2;
    }

    return;
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    //freopen("3.input", "r", stdin); // for testing. Comment out for submissions

    cin >> rowNum;

    cin >> columnNum;

    grid.resize(rowNum, vector<int>(columnNum)); // 0 is blocked, 1 is open, 2 is a final position

    for (int i = 0; i < rowNum; i++) {
        for (int j = 0; j < columnNum; j++) {
            char c; cin >> c;

            grid[i][j] = c == '.';
        }
    }

    checkPositions.insert({0, 0});

    int currentRow, currentColumn, currDirection; // starting at 0, 0, facing north
    currentRow = currentColumn = currDirection = 0;

    int moveNum; cin >> moveNum;

    for (int i = 0; i < moveNum; i++) {
        char currMove; cin >> currMove;

        if (currMove == 'F') {
            if (currDirection == 0) {
                currentRow++;
            } else if (currDirection == 1) {
                currentColumn++;
            } else if (currDirection == 2) {
                currentRow--;
            } else if (currDirection == 3) {
                currentColumn--;
            }
        } else if (currMove == 'R') {
            currDirection = (currDirection + 1) % 4;
        } else if (currMove == 'L') {
            currDirection = (currDirection + 3) % 4;
        }

        checkPositions.insert({currentRow, currentColumn});
    }

    finalAddColumn = currentColumn;
    finalAddRow = currentRow;

    for (int i = 0; i < rowNum; i++) {
        for (int j = 0; j < columnNum; j++) {
            for (int k = 0; k < 4; k++) {
                traverse(i, j, k);
            }
        }
    }

    for (int i = 0; i < rowNum; i++) {
        for (int j = 0; j < columnNum; j++) {
            if (!grid[i][j]) {
                cout << 'X';
            } else if (grid[i][j] == 1) {
                cout << '.';
            } else {
                cout << '*';
            }
        }

        cout << endl;
    }

    return 0;
}