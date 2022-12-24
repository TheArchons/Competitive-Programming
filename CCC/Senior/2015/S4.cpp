#include <bits/stdc++.h>

using namespace std;

struct route {
    int island, time, hullDamage;
};

struct island {
    int minHullDamage, time;
    int hullDamage, minTime;

    bool visited;
};

struct shipStatus {
    int island, hullDamage, time;
};

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    //freopen("4.input", "r", stdin); // for testing
    
    int hullThickness, numIslands, seaRoutes;
    cin >> hullThickness >> numIslands >> seaRoutes;

    vector<vector<route>> routes(numIslands + 1);
    for (int i = 0; i < seaRoutes; i++) {
        int island1, island2, time, hullDamage;
        cin >> island1 >> island2 >> time >> hullDamage;
        
        routes[island1].push_back({island2, time, hullDamage});
        routes[island2].push_back({island1, time, hullDamage});
    }

    int start, end;
    cin >> start >> end;

    vector<island> islands(numIslands + 1, {-1, -1, -1, -1, false});
    islands[start] = {0, 0, 0, 0, true};

    queue<shipStatus> q;
    q.push({start, 0, 0});

    while (!q.empty()) {
        shipStatus curr = q.front();
        q.pop();

        for (auto it : routes[curr.island]) {
            if (curr.hullDamage + it.hullDamage >= hullThickness) continue;

            island next = islands[it.island];
            int nextDamage = curr.hullDamage + it.hullDamage;
            int nextTime = curr.time + it.time;
            bool added = false;

            if (!next.visited || next.minHullDamage > nextDamage) {
                next.minHullDamage = nextDamage;
                next.time = nextTime;

                added = true;
            }

            if (!next.visited || next.minTime > nextTime) {
                next.minTime = nextTime;
                next.hullDamage = nextDamage;

                added = true;
            }

            if (added) {
                next.visited = true;
                islands[it.island] = next;
                q.push({it.island, nextDamage, nextTime});
            }
        }
    }

    cout << islands[end].minTime << endl;
}