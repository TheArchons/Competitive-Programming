#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    //freopen("g.input", "r", stdin); // for testing. Comment out for submissions

    int nodes; cin >> nodes;
    int edges; cin >> edges;

    vector<vector<int>> connections(nodes + 1);

    for (int i = 0; i < edges; i++) {
        int start; cin >> start;
        int end; cin >> end;

        connections[start].push_back(end);
    }

    set<int> notVisited;
    for (int i = 1; i <= nodes; i++) {
        notVisited.insert(i);
    }

    for (int i = 1; i <= nodes; i++) {
        queue<int> q;
        q.push(i);

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (auto connection : connections[node]) {
                if (notVisited.find(connection) != notVisited.end()) {
                    notVisited.erase(connection);
                    q.push(connection);
                }
            }
        }
    }

    int maxPath = 0;

    for (auto root : notVisited) {
        vector<vector<int>> longestPath(nodes + 1, vector<int>(nodes + 1, 0));

        priority_queue<pair<int, int>> pq;
        pq.push({root, 0});
        
        while (!pq.empty()) {
            auto [node, pathLength] = pq.top();
            pq.pop();

            maxPath = max(maxPath, pathLength);

            for (auto connection : connections[node]) {
                if (pathLength + 1 > longestPath[connection][node]) {
                    longestPath[connection][node] = pathLength + 1;
                    pq.push({connection, pathLength + 1});
                }
            }
        }
    }



    cout << maxPath << endl;

    return 0;
}