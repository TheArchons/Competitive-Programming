#include <bits/stdc++.h>

using namespace std;

int rowNum;
int colNum;

string alphabet = 'abdefghijklmnopqrstuvwxyz';

int findRowP(int p) {
    return rowNum - p - 1;
}

int findColP(int p) {
    return colNum - p - 1;
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    freopen("S3_2.input", "r", stdin); // For testing. Comment out for submissions

    cin >> rowNum;
    cin >> colNum;
    int rowPNum; cin >> rowPNum;
    int colPNum; cin >> colPNum;
    
    vector<vector<char>> result(rowNum, vector<char>(colNum));

    vector<bool> rowIsP(rowNum, false);
    vector<bool> colIsP(colNum, false);

    bool flip = false;

    for (int i = 0; i < rowPNum; i++) {
        if (flip) {
            rowIsP[findRowP(i/2)] = true;
        } else {
            rowIsP[i/2] = true;
        }

        flip = !flip;
    }

    flip = false;

    for (int i = 0; i < colPNum; i++) {
        if (flip) {
            colIsP[findColP(i/2)] = true;
        } else {
            colIsP[i/2] = true;
        }
        
        flip = !flip;
    }

    for (int i = 0; i < rowNum; i++) {
        bool rowBrokenP = false;

        for (int j = 0; j < colNum; j++) {
            bool colBrokenP = false;
            int rowPPos = findRowP(i);
            int colPPos = findColP(i);

            char banned = '';

            if (rowPPos < 0 && colPPos < 0) {
                // no requirements
                result[i][j] = 'a';
            }

            bool required = false;

            if (rowPPos > 0) {
                if (rowIsP[i]) {
                    result[i][j] = result[rowPPos][j];
                    required = true;
                } else {
                    // already not a palindrome, so we can repeat if we want
                    if (!rowBrokenP) {
                        banned = result[rowPPos][j];
                    }
                }
            }

            if (colPPos > 0) {
                if (colIsP[j]) {
                    char requiredVal = result[i][colPPos];

                    if (required) {
                        if (requiredVal != result[i][j]) {
                            cout << "IMPOSSIBLE" << endl;
                            return;
                        }
                    }

                    if (banned != requiredVal) {
                        // not banned, so we broke palindrome
                        // case for when we are in the middle

                    }

                    result[i][j] = requiredVal;
                } else {
                    
                }
            }
        }

    }


    return 0;
}