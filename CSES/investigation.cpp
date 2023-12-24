#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct flight {
    int start;
    int end;
    int cost;
};

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    // freopen("investigation.input", "r", stdin); // For testing. Comment out for submissions

    int cityNum; cin >> cityNum; int flightNum; cin >> flightNum;

    vector<vector<flight>> flights(cityNum);

    for (int i = 0; i < flightNum; i++) {
        int start; cin >> start;
        int end; cin >> end;
        start--; end--;
        int cost; cin >> cost;

        flight currFlight;
        currFlight.start = start;
        currFlight.end = end;
        currFlight.cost = cost;

        flights[start].push_back(currFlight);

        // reverse flight
        currFlight.start = end;
        currFlight.end = start;

        flights[end].push_back(currFlight);
    }

    vector<vector<int>> minimumFlights(cityNum);

    queue<int> q;
    q.push(0);

    vector<int> minCosts(cityNum, INT_MAX);
    minCosts[0] = 0;

    while(!q.empty()) {
        int curr = q.front(); q.pop();
        int currCost = minCosts[curr];

        for (int i = 0; i < flights[curr].size(); i++) {
            flight next = flights[curr][i];
            int nextCost = currCost + next.cost;

            if (minCosts[next.end] > nextCost) {
                minimumFlights[next.end].clear();
                q.push(next.end);
                minCosts[next.end] = nextCost;
            } else if (minCosts[next.end] < nextCost) continue;

            minimumFlights[next.end].push_back(curr);
        }
    }

    cout << minCosts[cityNum - 1] << " ";

    // construct graph based on minimumFlights
    vector<vector<int>> minFlightGraph(cityNum);

    for (int i = 0; i < cityNum; i++) {
        for (int j = 0; j < minimumFlights[i].size(); j++) {
            int start = minimumFlights[i][j];

            minFlightGraph[start].push_back(i);
        }
    }

    // # of minimum-price routes

    // topo sort
    vector<int> topoGraph;
    vector<bool> visited(cityNum, false);

    for (int i = 0; i < cityNum; i++) {
        if (visited[cityNum]) continue;

        visited[cityNum] = true;

        stack<int> path;

        path.push(i);

        while (!path.empty()) {
            int curr = path.top();

            bool found = false;

            for (int j = 0; j < minFlightGraph[curr].size(); j++) {
                int next = minFlightGraph[curr][j];

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
    vector<int> routeNum(cityNum, 0);
    routeNum[0] = 1;

    vector<int> shortestPath(cityNum, INT_MAX);
    shortestPath[0] = 0;

    vector<int> longestPath(cityNum, 0);

    for (int i = 0; i < cityNum; i++) {
        int curr = topoGraph[i];
        int currShortest = shortestPath[curr] + 1;
        int currLongest = longestPath[curr] + 1;

        for (int j = 0; j < minFlightGraph[curr].size(); j++) {
            int next = minFlightGraph[curr][j];

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