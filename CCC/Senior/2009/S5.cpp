#include <bits/stdc++.h>

using namespace std;

int calcEdge(int radius, int y) {
    return floor(sqrt(pow(radius, 2) - pow(y, 2)));
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    //freopen("5.input", "r", stdin); // for testing. Comment out for submissions

    int yCount; cin >> yCount;
    int xCount; cin >> xCount;
    int wirelessCount; cin >> wirelessCount;

    vector<vector<int>> grid(xCount, vector<int>(yCount, 0));

    for (int i = 0; i < wirelessCount; i++) {
        int x; cin >> x; int y; cin >> y; x--; y--;
        int radius; cin >> radius; int power; cin >> power;

        for (int j = y + radius; j >= y - radius; j--) {
            if (j < 0 || j >= yCount) continue;

            int edge = calcEdge(radius, j - y);

            int left = max(x - edge, 0);
            int right = x + edge + 1;
            if (right <= xCount - 1) grid[right][j] -= power;

            grid[left][j] += power;
        }
    }

    int maxPower = 0; int maxPowerCount = 0;

    for (int i = 0; i < yCount; i++) {
        int curr = 0;
        for (int j = 0; j < xCount; j++) {
            curr += grid[j][i];
            if (curr > maxPower) {
                maxPower = curr;
                maxPowerCount = 1;
            } else if (curr == maxPower) {
                maxPowerCount++;
            }
        }
    }

    cout << maxPower << endl << maxPowerCount << endl;

    return 0;
}