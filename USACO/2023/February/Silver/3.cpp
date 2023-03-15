#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct Flight {
    ll startTime;
    ll endTime;
    ll endAirport;
};

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    // freopen("3.input", "r", stdin); // For testing. Comment out for submissions

    ll airportNum; cin >> airportNum;

    ll flightNum; cin >> flightNum;

    vector<vector<Flight>> flights(airportNum + 1);

    for (ll i = 0; i < flightNum; i++) {
        ll startAirport; cin >> startAirport;
        ll startTime; cin >> startTime;

        ll endAirport; cin >> endAirport;
        ll endTime; cin >> endTime;

        flights[startAirport].push_back({startTime, endTime, endAirport});
    }

    for (ll i = 1; i <= airportNum; i++) {
        ll layoverTime; cin >> layoverTime;

        if (i == 1) {
            continue;
        }

        for (ll j = 0; j < flights[i].size(); j++) {
            flights[i][j].startTime -= layoverTime;
        }
    }

    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;

    pq.push({0, 1});

    vector<ll> minTimes(airportNum + 1, -1);

    while (!pq.empty()) {
        ll time = pq.top().first;
        ll airport = pq.top().second;

        pq.pop();

        if (minTimes[airport] != -1 && minTimes[airport] <= time) {
            continue;
        }

        minTimes[airport] = time;

        for (ll i = 0; i < flights[airport].size(); i++) {
            Flight flight = flights[airport][i];

            if (flight.startTime >= time) {
                pq.push({flight.endTime, flight.endAirport});
            }
        }
    }

    for (ll i = 1; i <= airportNum; i++) {
        cout << minTimes[i] << "\n";
    }

    return 0;
}