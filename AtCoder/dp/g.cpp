#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> grid;
vector<int> dp;

int solve(int curr) {
    if (dp[curr] != -1) return dp[curr];

    int maxPath = 0;

    for (int i = 0; i < grid[curr].size(); i++) {
        maxPath = max(maxPath, solve(grid[curr][i]) + 1);
    }

    return dp[curr] = maxPath;
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    //freopen("g.input", "r", stdin); // For testing. Comment out for submissions

    int vertexNum; cin >> vertexNum;
    int edgeNum; cin >> edgeNum;

    grid.resize(vertexNum + 1);

    for (int i = 0; i < edgeNum; i++) {
        int a, b; cin >> a >> b;
        grid[a].push_back(b);
    }

    dp.resize(vertexNum + 1, -1);

    int maxPath = 0;

    for (int i = 1; i <= vertexNum; i++) {
        maxPath = max(maxPath, solve(i));
    }

    cout << maxPath << endl;

    return 0;
}