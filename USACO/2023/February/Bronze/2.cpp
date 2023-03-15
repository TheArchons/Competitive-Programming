#include <bits/stdc++.h>

using namespace std;

void solve() {
    int gridLen; cin >> gridLen;

    vector<vector<bool>> grid(gridLen, vector<bool>(gridLen)); // true = has ink, false = no ink

    for (int i = 0; i < gridLen; i++) {
        for (int j = 0; j < gridLen; j++) {
            char c; cin >> c;

            grid[i][j] = c == '*';
        }
    }

    int stampLen; cin >> stampLen;

    vector<vector<bool>> stamp(stampLen, vector<bool>(stampLen));

    for (int i = 0; i < stampLen; i++) {
        for (int j = 0; j < stampLen; j++) {
            char c; cin >> c;

            stamp[i][j] = c == '*';
        }
    }

    vector<vector<bool>> result(gridLen, vector<bool>(gridLen, false));
    for (int rotation = 0; rotation < 4; rotation++) {
        for (int i = 0; i < gridLen - stampLen + 1; i++) {
            for (int j = 0; j < gridLen - stampLen + 1; j++) {
                bool canStamp = true;
                for (int k = 0; k < stampLen; k++) {
                    for (int l = 0; l < stampLen; l++) {
                        if (!grid[i + k][j + l] && stamp[k][l]) {
                            canStamp = false;
                            break;
                        }
                    }

                    if (!canStamp) {
                        break;
                    }
                }

                if (canStamp) {
                    for (int k = 0; k < stampLen; k++) {
                        for (int l = 0; l < stampLen; l++) {
                            if (stamp[k][l]) {
                                result[i + k][j + l] = true;
                            }
                        }
                    }
                }
            }
        }

        vector<vector<bool>> newStamp(stampLen, vector<bool>(stampLen));

        for (int i = 0; i < stampLen; i++) {
            for (int j = 0; j < stampLen; j++) {
                newStamp[j][stampLen - 1 - i] = stamp[i][j];
            }
        }

        stamp = newStamp;
    }

    for (int i = 0; i < gridLen; i++) {
        for (int j = 0; j < gridLen; j++) {
            if (grid[i][j] != result[i][j]) {
                cout << "NO" << endl;
                return;
            }
        }
    }

    cout << "YES" << endl;
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    // freopen("2.input", "r", stdin); // For testing. Comment out for submissions

    int testCases; cin >> testCases;

    while (testCases--) {
        solve();
    }

    return 0;
}