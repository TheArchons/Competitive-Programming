//https://cses.fi/problemset/task/1674

#include <bits/stdc++.h>

using namespace std;

vector<int> subordinatesCount;
vector<vector<int>> tree;

int dfs(int node) {
    int subordinates = 0;
    for (int child : tree[node]) {
        subordinates += dfs(child) + 1;
    }
    subordinatesCount[node] = subordinates;
    return subordinates;
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    //freopen("Subordinates.input", "r", stdin); // for testing
    
    int subordinates;
    cin >> subordinates;

    subordinatesCount.resize(subordinates + 1, 0);
    tree.resize(subordinates + 1);


    for (int i = 2; i <= subordinates; i++) {
        int boss;
        cin >> boss;
        tree[boss].push_back(i);
    }

    dfs(1);

    for (int i = 1; i <= subordinates; i++) {
        cout << subordinatesCount[i] << " ";
    }
}