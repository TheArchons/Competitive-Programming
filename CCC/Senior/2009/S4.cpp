#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    //freopen("4.input", "r", stdin); // for testing
    
    int cityNum, tradeRouteNum;
    cin >> cityNum >> tradeRouteNum;

    vector<vector<pair<int, int>>> connections(cityNum + 1);

    for (int i = 0; i < tradeRouteNum; i++) {
        int city1, city2, cost;
        cin >> city1 >> city2 >> cost;

        connections[city1].push_back({city2, cost});
        connections[city2].push_back({city1, cost});
    }

    int pencilCityNum;
    cin >> pencilCityNum;

    vector<pair<int, int>> pencilCities;
    for (int i = 0; i < pencilCityNum; i++) {
        int city, cost;
        cin >> city >> cost;

        pencilCities.push_back({city, cost});
    }

    int destinationCity;
    cin >> destinationCity;

    // dijkstra
    vector<int> dist(cityNum + 1, INT_MAX);
    dist[destinationCity] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, destinationCity});

    while (!pq.empty()) {
        pair<int, int> curr = pq.top();
        pq.pop();

        int currCity = curr.second;
        int currDist = curr.first;

        for (pair<int, int> next : connections[currCity]) {
            int nextCity = next.first;
            int nextDist = next.second;

            if (dist[nextCity] > currDist + nextDist) {
                dist[nextCity] = currDist + nextDist;
                pq.push({dist[nextCity], nextCity});
            }
        }
    }

    int minCost = INT_MAX;
    for (pair<int, int> city : pencilCities) {
        minCost = min(minCost, dist[city.first] + city.second);
    }

    cout << minCost << endl;
}