#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    //freopen("5.input", "r", stdin); // for testing. Comment out for submissions

    int height; cin >> height;
    int subHeight; cin >> subHeight;

    vector<vector<int>> triangle;
    for (int i = 0; i < height; i++) {
        vector<int> row;
        for (int j = 0; j < i + 1; j++) {
            int temp; cin >> temp;

            row.push_back(temp);
        }
        triangle.push_back(row);
    }

    ll total = 0;

    for (int i = 0; i < height - subHeight + 1; i++) {
        for (int j = 0; j < i + 1; j++) {
            ll max = 0;
            for (int k = 0; k < subHeight; k++) {
                for (int l = 0; l < k + 1; l++) {
                    ll current = triangle[i + k][j + l];
                    if (current > max) {
                        max = current;
                    }
                }
            }

            total += max;
        }
    }

    cout << total << endl;

    return 0;
}