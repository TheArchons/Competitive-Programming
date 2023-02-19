#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    //freopen("1.input", "r", stdin); // For testing. Comment out for submissions

    int columnNum; cin >> columnNum;

    vector<vector<int>> columns(columnNum);

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < columnNum; j++) {
            int temp; cin >> temp;
            columns[j].push_back(temp);
        }
    }

    int total = 0;

    // top row
    for (int i = 0; i < columnNum; i++) {
        if (columns[i][0] == 1) {
            if (i && columns[i - 1][0]) {
                total += 1;
            } else {
                total += 3;
            }
        }
    }

    // bottom row
    for (int i = 0; i < columnNum; i++) {
        if (columns[i][1]) {
            if (columns[i][0]) {
                if (i % 2 == 0) {
                    if (i && columns[i - 1][1]) {
                        total -= 1;
                    } else {
                        total += 1;
                    }
                } else {
                    if (columns[i - 1][1]) {
                        total += 1;
                    } else {
                        total += 3;
                    }
                }
            } else {
                if (i && columns[i - 1][1]) {
                    total += 1;
                } else {
                    total += 3;
                }
            }
        }
    }

    cout << total << endl;

    return 0;
}