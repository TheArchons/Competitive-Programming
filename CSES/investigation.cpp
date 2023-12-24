#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
ll ll_MAX = LONG_LONG_MAX;

struct flight {
    ll start;
    ll end;
    ll cost;
};

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    freopen("investigation.input", "r", stdin); // For testing. Comment out for submissions

    ll cityNum; cin >> cityNum; ll flightNum; cin >> flightNum;

    vector<vector<flight>> flights(cityNum);

    for (ll i = 0; i < flightNum; i++) {
        ll start; cin >> start;
        ll end; cin >> end;
        start--; end--;
        ll cost; cin >> cost;

        flight currFlight;
        currFlight.start = start;
        currFlight.end = end;
        currFlight.cost = cost;

        flights[start].push_back(currFlight);
    }

    vector<set<ll>> minimumFlights(cityNum);

    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> q;
    q.push({0, 0});

    vector<ll> minCosts(cityNum, ll_MAX);
    minCosts[0] = 0;

    while(!q.empty()) {
        ll curr = q.top().second;
        ll currCost = q.top().first;
        q.pop();

        for (ll i = 0; i < flights[curr].size(); i++) {
            flight next = flights[curr][i];
            ll nextCost = currCost + next.cost;

            if (minCosts[next.end] > nextCost) {
                minimumFlights[next.end].clear();
                q.push({nextCost, next.end});
                minCosts[next.end] = nextCost;
            } else if (minCosts[next.end] < nextCost) continue;

            minimumFlights[next.end].insert(curr);
        }
    }

    cout << minCosts[cityNum - 1] << " ";

    // construct graph based on minimumFlights
    vector<vector<ll>> minFlightGraph(cityNum);

    for (ll i = 0; i < cityNum; i++) {
        for (auto it : minimumFlights[i]) {
            minFlightGraph[it].push_back(i);
        }
    }

    // # of minimum-price routes

    // topo sort
    vector<ll> topoGraph;
    vector<bool> visited(cityNum, false);

    for (ll i = 0; i < cityNum; i++) {
        if (visited[i]) continue;

        visited[i] = true;

        stack<ll> path;

        path.push(i);

        while (!path.empty()) {
            ll curr = path.top();

            bool found = false;

            for (ll j = 0; j < minFlightGraph[curr].size(); j++) {
                ll next = minFlightGraph[curr][j];

                if (visited[next]) continue;
                visited[next] = true;

                found = true;
                path.push(next);

                break;
            }

            if (!found) {
                topoGraph.push_back(curr);
                path.pop();
            }
        }
    }

    reverse(topoGraph.begin(), topoGraph.end());

    // dp
    vector<ll> routeNum(cityNum, 0);
    routeNum[0] = 1;

    vector<ll> shortestPath(cityNum, ll_MAX);
    shortestPath[0] = 0;

    vector<ll> longestPath(cityNum, 0);

    for (ll i = 0; i < cityNum; i++) {
        ll curr = topoGraph[i];
        ll currShortest = shortestPath[curr] + 1;
        ll currLongest = longestPath[curr] + 1;

        for (ll j = 0; j < minFlightGraph[curr].size(); j++) {
            ll next = minFlightGraph[curr][j];

            routeNum[next] += routeNum[curr];
            routeNum[next] = routeNum[next] % ll(pow(10, 9) + 7);

            if (shortestPath[next] > currShortest) {
                shortestPath[next] = currShortest;
            }

            if (longestPath[next] < currLongest) {
                longestPath[next] = currLongest;
            }
        }
    }

    cout << routeNum[cityNum - 1] << " " << shortestPath[cityNum - 1] << " " << longestPath[cityNum - 1] << endl;

    return 0;
}