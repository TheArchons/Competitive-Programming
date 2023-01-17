#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> grid;

int maxArea, minPerimeter;
int currArea, currPerimeter;

bool checkInvalid(int i, int j) {
    return (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size());
}

void floodFill(int i, int j) {
    // if invalid, return
    if (checkInvalid(i, j) || grid[i][j] != 1) return;

    grid[i][j] = 2; // visited = 2 because im lazy
    currArea++;
    
    if (checkInvalid(i + 1, j) || !grid[i + 1][j]) currPerimeter++;
    if (checkInvalid(i - 1, j) || !grid[i - 1][j]) currPerimeter++;
    if (checkInvalid(i, j + 1) || !grid[i][j + 1]) currPerimeter++;
    if (checkInvalid(i, j - 1) || !grid[i][j - 1]) currPerimeter++;

    // update max
    if (currArea > maxArea) {
        maxArea = currArea;
        minPerimeter = currPerimeter;
    } else if (currArea == maxArea) {
        minPerimeter = min(minPerimeter, currPerimeter);
    }

    // search all 4 directions
    floodFill(i + 1, j);
    floodFill(i - 1, j);
    floodFill(i, j + 1);
    floodFill(i, j - 1);

    return;
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    freopen("3.input", "r", stdin);
    freopen("perimeter.in", "r", stdin);
    freopen("perimeter.out", "w", stdout);

    maxArea = 0;
    minPerimeter = INT_MAX;
    
    int sideLen;
    cin >> sideLen;

    grid.resize(sideLen, vector<int>(sideLen));

    for (int i = 0; i < sideLen; i++) {
        for (int j = 0; j < sideLen; j++) {
            char c;
            cin >> c;
            grid[i][j] = c == '#';
        }
    }

    for (int i = 0; i < sideLen; i++) {
        for (int j = 0; j < sideLen; j++) {
            if (grid[i][j] == 1) {
                currArea = currPerimeter = 0;
                floodFill(i, j);
            }
        }
    }

    cout << maxArea << " " << minPerimeter << endl;
}