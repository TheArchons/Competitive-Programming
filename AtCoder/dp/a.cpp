#include <bits/stdc++.h>

using namespace std;

vector<int> stones;
vector<int> minCosts;

void dijkstra(int stone, int cost) {
    if (stone == stones.size() - 1) {
        return;
    }

    int nextStone = stone + 1;
    int nextNextStone = stone + 2;

    int currStoneCost = stones[stone];
    int nextStoneCost = stones[nextStone];
    int nextNextStoneCost = stones[nextNextStone];

    int nextStoneCostDiff = abs(currStoneCost - nextStoneCost);
    int nextNextStoneCostDiff = abs(currStoneCost - nextNextStoneCost);

    if (nextStone < stones.size()) {
        if (minCosts[nextStone] > nextStoneCostDiff + cost) {
            minCosts[nextStone] = nextStoneCostDiff + cost;
            dijkstra(nextStone, nextStoneCostDiff + cost);
        }
    }

    if (nextNextStone < stones.size()) {
        if (minCosts[nextNextStone] > nextNextStoneCostDiff + cost) {
            minCosts[nextNextStone] = nextNextStoneCostDiff + cost;
            dijkstra(nextNextStone, nextNextStoneCostDiff + cost);
        }
    }

    return;
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    //freopen("a.input", "r", stdin); // for testing
    
    int stoneNum;
    cin >> stoneNum;

    stones.resize(stoneNum);
    minCosts.resize(stoneNum, INT_MAX);

    for (int i = 0; i < stoneNum; i++) {
        cin >> stones[i];
    }

    minCosts[0] = 0;
    dijkstra(0, 0);

    cout << minCosts[stoneNum - 1] << "\n";
}