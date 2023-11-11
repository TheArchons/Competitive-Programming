// https://cses.fi/problemset/task/1675
// Road Reparation but using Prim's instead of Kruskal
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct road {
    int city1, city2, cost;

    bool operator<(road otherRoad) const {
        return this->cost > otherRoad.cost;
    }
};

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    // freopen("RoadReparationPrims.input", "r", stdin); // For testing. Comment out for submissions

    int cityNum; cin >> cityNum;
    int roadNum; cin >> roadNum;

    vector<vector<road>> adj(cityNum);

    for (int i = 0; i < roadNum; i++) {
        int city1; cin >> city1; city1--;
        int city2; cin >> city2; city2--;
        int cost; cin >> cost;

        for (int i = 0; i < 2; i++) {
            road currRoad;
            currRoad.city1 = city1;
            currRoad.city2 = city2;
            currRoad.cost = cost;

            adj[city1].push_back(currRoad);

            swap(city1, city2);
        }
    }

    priority_queue<road> pq;
    vector<bool> visited(cityNum, false);
    int connectedCityNum = 1;
    ll totalCost = 0;
    for (int i = 0; i < adj[0].size(); i++) {
        pq.push(adj[0][i]);
    }
    visited[0] = true;

    while(!pq.empty()) {
        road minRoad = pq.top();
        pq.pop();
        if (visited[minRoad.city1] && visited[minRoad.city2]) continue; // skip if both are visited
        connectedCityNum++;
        totalCost += minRoad.cost;
        if (visited[minRoad.city1]) {
            swap(minRoad.city1, minRoad.city2);
        }

        visited[minRoad.city1] = true;
        visited[minRoad.city2] = true;

        for (int i = 0; i < adj[minRoad.city1].size(); i++) {
            road nextRoad = adj[minRoad.city1][i];   
      
            pq.push(nextRoad);
        }
    };

    if (connectedCityNum != cityNum) {
        cout << "IMPOSSIBLE" << endl;
    } else {
        cout << totalCost << endl;
    }

    return 0;
}