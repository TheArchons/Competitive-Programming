#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> walkways;
int stationOne;

void solve(vector<int> stations) {
    // dijkstra
    vector<int> dist(stations.size() + 1);

    queue<int> q;

    // set the distances to the time it takes the train to get to the station and add each station to the queue
    for (int i = 0; i < stations.size(); i++) {
        dist[stations[i]] = i;
        q.push(stations[i]);
    }

    while (!q.empty()) {
        int current = q.front();
        int currentDist = dist[current];
        q.pop();

        // add walkways
        for (int i = 0; i < walkways[current].size(); i++) {
            int next = walkways[current][i];
            int nextDist = dist[next];
            if (nextDist > currentDist + 1) {
                dist[next] = currentDist + 1;
                q.push(next);
            }
        }
    }

    int endDist = dist[stations.size()];
    cout << endDist << endl;

    return;
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    //freopen("4.input", "r", stdin); // for testing
    
    int subwayStationNum, walkwayNum, dayNum;
    cin >> subwayStationNum >> walkwayNum >> dayNum;

    walkways.resize(subwayStationNum + 1);

    for (int i = 0; i < walkwayNum; i++) {
        int a, b;
        cin >> a >> b;
        walkways[a].push_back(b);
    }

    vector<int> stations(subwayStationNum);
    for (int i = 0; i < subwayStationNum; i++) {
        int a;
        cin >> a;
        stations[i] = a;
        if (a == 1) stationOne = i;
    }

    for (int i = 0; i < dayNum; i++) {
        int a, b;
        cin >> a >> b;
        // swap stations
        a--; b--;
        if (stations[a] == 1) stationOne = b;
        int temp = stations[a];
        stations[a] = stations[b];
        stations[b] = temp;

        solve(stations);
    }

    return 0;
}