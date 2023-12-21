#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    // freopen("1.input", "r", stdin); // For testing. Comment out for submissions

    int cityNum; cin >> cityNum; cityNum--;

    vector<vector<int>> grid(cityNum, vector<int>(cityNum, 0));

    for (int i = 0; i < cityNum; i++) {
        for (int j = 0; j < cityNum - i; j++) {
            char c; cin >> c;
            int currNum;
            if (c == '1') {
                currNum = 1;
            } else {
                currNum = 0;
            }

            grid[i][j + i] = currNum;
        }
    }

    int directFlightNum = 0;

    // first diagonal

    int horizontal = 0;

    for (int i = 0; i < cityNum; i++) {
        directFlightNum += grid[i][horizontal];
        horizontal++;
    }

    // second diagonal

    horizontal = 1;

    for (int i = 0; i < cityNum - 1; i++) {
        int squareSum = 0;
        squareSum += grid[i][horizontal];
        squareSum += grid[i][horizontal - 1];
        squareSum += grid[i + 1][horizontal];
        squareSum += grid[i + 1][horizontal - 1];

        if (squareSum % 2 == 0) {
            directFlightNum++;
        }

        horizontal++;
    }

    // rest of the diagonals

    for (int i = 2; i < cityNum; i++) {
        horizontal = i;

        for (int j = 0; j < cityNum - i; j++) {
            int squareSum = 0;
            squareSum += grid[j][horizontal];
            squareSum += grid[j][horizontal - 1];
            squareSum += grid[j + 1][horizontal];
            squareSum += grid[j + 1][horizontal - 1];

            if (squareSum % 2) {
                directFlightNum++;
            }

            horizontal++;
        }
    }

    cout << directFlightNum << "\n";

    return 0;
}