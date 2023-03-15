#include <bits/stdc++.h>

using namespace std;

struct Flight {
    int startTime;
    int endTime;
    int endAirport;
};

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    freopen("3.input", "r", stdin); // For testing. Comment out for submissions

    int airportNum; cin >> airportNum;

    int flightNum; cin >> flightNum;

    vector<vector<Flight>> flights(airportNum + 1);

    for (int i = 0; i < flightNum; i++) {
        int startAirport; cin >> startAirport;
        int startTime; cin >> startTime;

        int endAirport; cin >> endAirport;
        int endTime; cin >> endTime;

        flights[startAirport].push_back({startTime, endTime, endAirport});
    }

    for (int i = 1; i <= airportNum; i++) {
        int layoverTime; cin >> layoverTime;

        if (i == 1) {
            continue;
        }

        for (int j = 0; j < flights[i].size(); j++) {
            flights[i][j].startTime -= layoverTime;
        }
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    pq.push({0, 1});

    vector<int> minTimes(airportNum + 1, -1);

    while (!pq.empty()) {
        int time = pq.top().first;
        int airport = pq.top().second;

        pq.pop();

        if (minTimes[airport] != -1 && minTimes[airport] <= time) {
            continue;
        }

        minTimes[airport] = time;

        for (int i = 0; i < flights[airport].size(); i++) {
            Flight flight = flights[airport][i];

            if (flight.startTime >= time) {
                pq.push({flight.endTime, flight.endAirport});
            }
        }
    }

    for (int i = 1; i <= airportNum; i++) {
        cout << minTimes[i] << "\n";
    }

    return 0;
}