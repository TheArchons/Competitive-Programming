#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    // freopen("GameRoutes.input", "r", stdin); // For testing. Comment out for submissions

    int levelNum; cin >> levelNum;
    int teleporterNum; cin >> teleporterNum;

    vector<vector<int>> teleports(levelNum);

    for (int i = 0; i < teleporterNum; i++) {
        int a; cin >> a; int b; cin >> b; a--; b--;

        teleports[a].push_back(b);
    }

    vector<bool> visited(levelNum, false);
    vector<int> topoLevels;

    for (int i = 0; i < levelNum; i++) {
        if (visited[i]) {
            continue;
        }

        visited[i] = true;

        stack<int> path;
        path.push(i);

        while (!path.empty()) {
            int curr = path.top();

            bool found = false;

            for (int j = 0; j < teleports[curr].size(); j++) {
                int next = teleports[curr][j];

                if (visited[next]) continue;

                found = true;

                path.push(next);
            }

            if (!found) {
                topoLevels.push_back(curr);
                visited[curr] = true;
                path.pop();
            }
        }
    }

    reverse(topoLevels.begin(), topoLevels.end());

    vector<ll> dp(levelNum, 0);

    dp[0] = 1;

    for (int i = 0; i < levelNum; i++) {
        ll curr = topoLevels[i];

        for (int j = 0; j < teleports[curr].size(); j++) {
            int next = teleports[curr][j];

            dp[next] += dp[curr];
            dp[next] = dp[next] % ll(pow(10, 9) + 7);
        }
    }

    cout << dp[levelNum - 1] << endl;

    return 0;
}