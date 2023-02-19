#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    //freopen("3.input", "r", stdin); // For testing. Comment out for submissions

    int rowNum; cin >> rowNum;
    int columnNum; cin >> columnNum;

    int pRows; cin >> pRows;
    int pColumns; cin >> pColumns;

    if (pRows == 1 && pColumns == 1) {
        vector<vector<char>> grid(rowNum, vector<char>(columnNum, 'a'));

        // set last row to palindrome
        for (int i = 0; i < columnNum; i++) {
            grid[rowNum - 1][i] = 'd';
        }

        // set last column to palindrome
        for (int i = 0; i < rowNum; i++) {
            grid[i][columnNum - 1] = 'd';
        }

        for (int i = 0; i < rowNum; i++) {
            for (int j = 0; j < columnNum; j++) {
                cout << grid[i][j];
            }

            cout << endl;
        }
    } else if (rowNum == 2 && columnNum == 2) {
        if (!pRows && !pColumns) {
            cout << "ab\ncd";
        } else if (pRows == 1 && !pColumns) {
            cout << "aa\nbd";
        } else if (pRows == 1 && pColumns == 1) {
            cout << "aa\nac";
        } else if (pRows == 2 && pColumns == 2) {
            cout << "aa\naa";
        } else if (!pRows && pColumns == 1) {
            cout << "ba\nda";
        } else if (pRows == 2 && !pColumns) {
            cout << "aa\nbb";
        } else if (!pRows && pColumns == 2) {
            cout << "ab\nab";
        } else {
            cout << "IMPOSSIBLE";
        }
    } else if (rowNum == 2) {
        vector<vector<char>> grid(rowNum, vector<char>(columnNum, 'a'));

        if (!pRows && ! pColumns) {
            grid[1][0] = 'c';

            // set all in first row to b
            for (int i = 0; i < columnNum; i++) {
                grid[0][i] = 'b';
            }
        } else if (pRows == 1) {
            int nNeeded = columnNum - pColumns;
            if (pColumns) {
                grid[0][0] = 'b';
                grid[1][0] = 'b';
                pColumns--;
            } else {
                grid[0][0] = 'b';
                grid[1][0] = 'c';
            }

            for (int i = 1; i < nNeeded; i++) {
                grid[0][i] = 'c';
            }
        } else if (pRows == 2) {
            int nNeeded = columnNum - pColumns;
            for (int i = 1; i < nNeeded; i++) {
                grid[0][i] = 'b';
            }
        } else {
            cout << "IMPOSSIBLE";
            return 0;
        }

        for (int i = 0; i < rowNum; i++) {
            for (int j = 0; j < columnNum; j++) {
                cout << grid[i][j];
            }

            cout << endl;
        }
    }

    return 0;
}