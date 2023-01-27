#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    //freopen("3.input", "r", stdin); // for testing
    freopen("art.in", "r", stdin); freopen("art.out", "w", stdout); // for submission

    int gridSideLength;
    cin >> gridSideLength;

    vector<vector<int>> grid(gridSideLength, vector<int>(gridSideLength));
    set<int> potentialColors;

    for (int i = 0; i < gridSideLength; i++) {
        for (int j = 0; j < gridSideLength; j++) {
            char c;
            cin >> c;

            grid[i][j] = c - '0';

            if (grid[i][j]) potentialColors.insert(grid[i][j]);
        }
    }

    set<int> seenColors;

    for (int i = 0; i < gridSideLength; i++) {
        for (int j = 0; j < gridSideLength; j++) {
            if (grid[i][j] && seenColors.find(grid[i][j]) == seenColors.end()) {
                int maxRight, maxBottom;
                maxRight = j;
                maxBottom = i;
                int currColor = grid[i][j];

                seenColors.insert(currColor);

                for (int k = i; k < gridSideLength; k++) {
                    for (int l = j; l < gridSideLength; l++) {
                        if (grid[k][l] == currColor) {
                            maxRight = max(maxRight, l);
                            maxBottom = max(maxBottom, k);
                        }
                    }
                }

                for (int k = i; k < maxBottom + 1; k++) {
                    for (int l = j; l < maxRight + 1; l++) {
                        if (grid[k][l] != currColor) {
                            potentialColors.erase(grid[k][l]);
                        }
                    }
                }
            }
        }
    }

    cout << potentialColors.size() << endl;

    return 0;
}