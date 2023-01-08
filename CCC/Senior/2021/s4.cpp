#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> walkways;
int stationOne;

void solve(vector<int> stations) {
    // BFS
    queue<pair<int, int>> q;
    q.push(make_pair(stations[0], 0));

    set<int> visited;

    while (true) {
        pair<int, int> current = q.front();
        q.pop();

        visited.insert(current.first);

        // check if current station is the end station
        if (current.first == stations.size()) {
            cout << current.second << endl;
            return;
        }

        // add train to queue
        if (stations[current.second] == current.first) {
            q.push(make_pair(stations[current.second + 1], current.second + 1));
        }

        // add walkways
        for (int j = 0; j < walkways[current.first].size(); j++) {
            if (visited.find(walkways[current.first][j]) == visited.end()) {
                q.push(make_pair(walkways[current.first][j], current.second + 1));
            }
        }

    }

    //! SHOULD NEVER HAPPEN
    cout << stations.size() << endl;
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