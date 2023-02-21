#include <bits/stdc++.h>

using namespace std;

vector<char> searchV;
vector<vector<char>> grid;
int searchLen;
int rowNum; int columnNum;
int total = 0;

// directions
// 0 = up
// 1 = right
// 2 = down
// 3 = left
// 4 = up right
// 5 = down right
// 6 = down left
// 7 = up left

pair<int ,int> nextDir(int row, int column, int direction) {
    if (direction == 0) {
        return make_pair(row - 1, column);
    } else if (direction == 1) {
        return make_pair(row, column + 1);
    } else if (direction == 2) {
        return make_pair(row + 1, column);
    } else if (direction == 3) {
        return make_pair(row, column - 1);
    } else if (direction == 4) {
        return make_pair(row - 1, column + 1);
    } else if (direction == 5) {
        return make_pair(row + 1, column + 1);
    } else if (direction == 6) {
        return make_pair(row + 1, column - 1);
    } else if (direction == 7) {
        return make_pair(row - 1, column - 1);
    }

    return make_pair(-1, -1);
}

void dfs(int row, int column, vector<char> currString, bool hasTurned, int direction) {
    if (row < 0 || row >= rowNum || column < 0 || column >= columnNum) {
        return;
    }

    currString.push_back(grid[row][column]);

    if (currString.size() == searchLen) {
        if (currString == searchV) {
            total++;
        }

        return;
    }

    pair<int, int> next = nextDir(row, column, direction);
    dfs(next.first, next.second, currString, hasTurned, direction);

    if (!hasTurned && currString.size() < searchLen && currString.size() != 1) {
        if (direction < 4) {
            for (int i = 0; i < 4; i++) {
                if (i != direction) {
                    pair<int, int> next = nextDir(row, column, i);
                    dfs(next.first, next.second, currString, true, i);
                }
            }
        } else {
            for (int i = 4; i < 8; i++) {
                if (i != direction) {
                    pair<int, int> next = nextDir(row, column, i);
                    dfs(next.first, next.second, currString, true, i);
                }
            }
        }
    }

    return;
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    //freopen("5.input", "r", stdin); // For testing. Comment out for submissions

    string searchStr; cin >> searchStr;

    searchLen = searchStr.length();
    
    for (int i = 0; i < searchStr.length(); i++) {
        searchV.push_back(searchStr[i]);
    }

    cin >> rowNum;
    cin >> columnNum;

    grid.resize(rowNum, vector<char>(columnNum));

    for (int i = 0; i < rowNum; i++) {
        for (int j = 0; j < columnNum; j++) {
            cin >> grid[i][j];
        }
    }

    vector<char> currString;

    for (int i = 0; i < rowNum; i++) {
        for (int j = 0; j < columnNum; j++) {
            for (int k = 0; k < 8; k++) {
                dfs(i, j, currString, false, k);
            }
        }
    }

    cout << total << endl;

    return 0;
}