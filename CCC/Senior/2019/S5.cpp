#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    //freopen("5.input", "r", stdin); // for testing. Comment out for submissions

    int triangleHeight; cin >> triangleHeight;
    int subTriangleHeight; cin >> subTriangleHeight;

    vector<vector<int>> triangle(triangleHeight);

    for (int i = 0; i < triangleHeight; i++) {
        triangle[i].resize(i + 1);
        for (int j = 0; j < i + 1; j++) {
            cin >> triangle[i][j];
        }
    }

    int total = 0;

    for (int i = 0; i < triangleHeight - subTriangleHeight + 1; i++) {
        for (int j = 0; j < triangle[i].size(); j++) {
            int maxSize = 0;
            for (int k = 0; k < subTriangleHeight; k++) {
                for (int l = 0; l < k + 1; l++) {
                    maxSize = max(maxSize, triangle[i + k][j + l]);
                }
            }
            total += maxSize;
        }
    }

    cout << total << endl;

    return 0;
}