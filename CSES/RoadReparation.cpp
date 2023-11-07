#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct road {
    int city1;
    int city2;
    int repairCost;

    bool operator<(const road& r) const {
        return this->repairCost > r.repairCost;
    }
};

const int maxCity = pow(10, 5) + 5;

vector<int> ds(maxCity);
vector<int> dsh(maxCity);
vector<vector<int>> roadsV(maxCity);
vector<bool> visited(maxCity, false);

void printRoads(priority_queue<road> roads) {
    // print pq
    while (!roads.empty()) {
        cout << roads.top().repairCost << endl;
        cout << roads.top().city1 << endl;
        cout << roads.top().city2 << endl << endl;

        roads.pop();
    }
}

int findRep(int city) {
    while (ds[city] != city) {
        city = ds[city];
    }

    return city;
}

bool same(int city1, int city2) {
    return findRep(city1) == findRep(city2);
}

void cityUnion(int city1, int city2) {
    int city1Rep = findRep(city1);
    int city2Rep = findRep(city2);

    if (city1Rep != city2Rep) {
        // union by height
        if (dsh[city1Rep] < dsh[city2Rep]) {
            swap(city1Rep, city2Rep);
        }

        ds[city2Rep] = city1Rep;
        
        if (dsh[city1Rep] == dsh[city2Rep]) {
            dsh[city1Rep]++;
        }
    }

    return;
}

void dfs(int city) {
    vector<int> currCityRoads = roadsV[city];
    for (int i = 0; i < currCityRoads.size(); i++) {
        int nextCity = currCityRoads[i];

        if (!visited[nextCity]) {
            visited[nextCity] = true;
            dfs(nextCity);
        }
    }

    return;
}

void initDs() {
    for (int i = 0; i < maxCity; i++) {
        ds[i] = i;
    }

    return;
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    // freopen("RoadReparation.input", "r", stdin); // For testing. Comment out for submissions

    initDs();

    int cityNum; cin >> cityNum;
    int roadNum; cin >> roadNum;

    priority_queue<road> roads;

    for (int i = 0; i < roadNum; i++) {
        int city1; cin >> city1;
        int city2; cin >> city2;
        int repairCost; cin >> repairCost;

        road currRoad;
        currRoad.city1 = city1;
        currRoad.city2 = city2;
        currRoad.repairCost = repairCost;

        roads.push(currRoad);

        roadsV[city1].push_back(city2);
        roadsV[city2].push_back(city1);
    }

    // check for impossible
    dfs(1);

    for (int i = 1; i <= cityNum; i++) {
        if (!visited[i]) {
            cout << "IMPOSSIBLE" << endl;
            return 0;
        }
    }
    

    ll minCost = 0;

    // ds
    while (!roads.empty()) {
        road currRoad = roads.top(); roads.pop();

        if (same(currRoad.city1, currRoad.city2)) {
            // already joined, so no need to join them again
            continue;
        }

        minCost += currRoad.repairCost;

        cityUnion(currRoad.city1, currRoad.city2);
    }

    cout << minCost << endl;

    return 0;
}