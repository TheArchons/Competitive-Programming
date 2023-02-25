#include <bits/stdc++.h>

using namespace std;

// 0R 0C - all Bs except for the first row and column, [0][0] is B
// 1R 0C - all Bs except for the first row/column, [1][0] is C
// 0R 1C - all Bs except for the first row/column, [0][1] is C

struct Point {
    int row;
    int column;
};

int rowNum;
int columnNum;
int wantedRows;
int wantedColumns;
vector<vector<char>> grid;

void setC(Point p1, Point p2, char c) {
    for (int i = p1.row; i <= p2.row; i++) {
        for (int j = p1.column; j <= p2.column; j++) {
            grid[i][j] = c;
        }
    }
}

void pGrid() {
    for (int i = 0; i < rowNum; i++) {
        for (int j = 0; j < columnNum; j++) {
            cout << grid[i][j];
        }
        cout << endl;
    }
}

void setCELR(int mid, int currWanted) {
    Point lStart = {rowNum, mid - currWanted};
    Point lEnd = {rowNum, mid - 1};
    Point rStart = {rowNum, mid};
    Point rEnd = {rowNum, mid + currWanted - 1};

    setC(lStart, lEnd, 'b');
    setC(rStart, rEnd, 'b');
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    //freopen("3.input", "r", stdin); // For testing. Comment out for submissions

    cin >> rowNum;
    cin >> columnNum;
    cin >> wantedRows;
    cin >> wantedColumns;

    grid.resize(rowNum, vector<char>(columnNum, 'a'));

    // first deal with edge cases

    if (!wantedRows || !wantedColumns) {
        setC({1, 1}, {rowNum - 1, columnNum - 1}, 'b');
        
        if (!wantedRows && !wantedColumns) {
            grid[0][0] = 'b';
        } else if (!wantedRows) {
            grid[0][1] = 'c';
        } else {
            grid[1][0] = 'c';
        }

        pGrid();

        return 0;
    }

    if (wantedRows == rowNum && wantedColumns == columnNum) {
        pGrid();

        return 0;
    }

    if (wantedRows == rowNum) {
        if (wantedColumns % 2) {
            if (columnNum % 2) {
                // odd wanted, odd total
                int mid = (columnNum + 1) / 2;
                int currWanted = wantedColumns / 2;

                setCELR(mid, currWanted);

                grid[rowNum][mid] = 'b';
            } else {
                // odd wanted, even total
                cout << "IMPOSSIBLE" << endl;
            }
        } else {
            if (columnNum % 2) {
                // even wanted, odd total
                int mid = (columnNum + 1) / 2;
                int currWanted = wantedColumns / 2;

                setCELR(mid, currWanted);
            } else {
                // even wanted, even total
                int lMid = columnNum / 2;
                int rMid = lMid + 1;

                int currWanted = wantedColumns / 2;

                while (currWanted > 0) {
                    grid[rowNum][lMid] = 'b';
                    grid[rowNum][rMid] = 'b';

                    lMid--;
                    rMid++;

                    currWanted -= 2;
                }
            }
        }

        return 0;
    }

    if (wantedColumns == columnNum) {
        if (wantedRows % 2) {
            if (rowNum % 2) {
                // odd wanted, odd total
                int mid = (rowNum + 1) / 2;
                int currWanted = wantedRows / 2;

                setCELR(mid, currWanted);

                grid[mid][columnNum] = 'b';
            } else {
                // odd wanted, even total
                cout << "IMPOSSIBLE" << endl;
            }
        } else {
            if (rowNum % 2) {
                // even wanted, odd total
                int mid = (rowNum + 1) / 2;
                int currWanted = wantedRows / 2;

                setCELR(mid, currWanted);
            } else {
                // even wanted, even total
                int lMid = rowNum / 2;
                int rMid = lMid + 1;

                int currWanted = wantedRows / 2;

                while (currWanted > 0) {
                    grid[lMid][columnNum] = 'b';
                    grid[rMid][columnNum] = 'b';

                    lMid--;
                    rMid++;

                    currWanted -= 2;
                }
            }
        }

        return 0;
    }

    // now deal with the general case
    Point start = {wantedRows, wantedColumns};
    Point end = {rowNum - 1, columnNum - 1};

    setC(start, end, 'b');

    pGrid();

    return 0;
}