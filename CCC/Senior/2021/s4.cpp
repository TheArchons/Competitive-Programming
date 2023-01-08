#include <bits/stdc++.h>

using namespace std;

void solve(vector<vector<int>> walkways, vector<int> stations) {
    printf("1");
    return;
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    freopen("4.input", "r", stdin); // for testing
    
    int subwayStationNum, walkwayNum, dayNum;
    cin >> subwayStationNum >> walkwayNum >> dayNum;

    vector<vector<int>> walkways(subwayStationNum + 1);

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
    }

    for (int i = 0; i < dayNum; i++) {
        int a, b;
        cin >> a >> b;
        // swap stations
        int temp = stations[a - 1];
        stations[a - 1] = stations[b - 1];
        stations[b - 1] = temp;

        solve(walkways, stations);
    }

    return 0;
}