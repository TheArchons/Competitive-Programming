#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    //freopen("a.input", "r", stdin); // for testing
    
    int stoneNum;
    cin >> stoneNum;

    stoneNum++;

    vector<int> stones(stoneNum);
    vector<int> minCosts(stoneNum, INT_MAX);

    for (int i = 1; i < stoneNum; i++) {
        cin >> stones[i];
    }

    minCosts[1] = 0;
    
    for (int i = 1; i < stoneNum-2; i++) {
        minCosts[i+1] = min(minCosts[i+1], minCosts[i] + abs(stones[i+1] - stones[i]));
        minCosts[i+2] = min(minCosts[i+2], minCosts[i] + abs(stones[i+2] - stones[i]));
    }

    minCosts[stoneNum-1] = min(minCosts[stoneNum-1], minCosts[stoneNum-2] + abs(stones[stoneNum-1] - stones[stoneNum-2]));

    cout << minCosts[stoneNum-1] << endl;
}