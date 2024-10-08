#include <bits/stdc++.h>

using namespace std;


bool solve() {
    int numCities; cin >> numCities;
    int numRoads; cin >> numRoads;
    int numSoldiers; cin >> numSoldiers;

    vector<vector<int>> graph(numCities);

    for (int i = 0; i < numRoads; i++) {
        int city1; cin >> city1;
        int city2; cin >> city2;

        city1--;
        city2--;

        graph[city1].push_back(city2);
        graph[city2].push_back(city1);
    }

    vector<bool> cityHasSoldier(numCities);

    for (int i = 0; i < numSoldiers; i++) {
        int city; cin >> city;
        int strength; cin >> strength;

        city--;

        if (cityHasSoldier[city]) { // already covered by another soldier
            return false;
        }

        queue<int> cityQ;
        cityQ.push(city);
        
        unordered_map<int, int> distanceToBase;
        unordered_set<int> currentSoliderHasCovered;
        currentSoliderHasCovered.insert(city);

        cityHasSoldier[city] = true;

        while (!cityQ.empty()) {
            int currCity = cityQ.front(); cityQ.pop();

            for (int nextCity : graph[currCity]) {
                if (currentSoliderHasCovered.find(nextCity) != currentSoliderHasCovered.end() || distanceToBase[currCity] + 1 > strength) { // already covered by current soldier or out of the current soldier's area
                    continue;
                }

                if (cityHasSoldier[nextCity]) { // already covered by another soldier
                    return false;
                }

                cityQ.push(nextCity);
                cityHasSoldier[nextCity] = true;
                distanceToBase[nextCity] = distanceToBase[currCity] + 1;
                currentSoliderHasCovered.insert(nextCity);
            }
        }
    }

    // ensure each city has been covered
    for (int i = 0; i < numCities; i++) {
        if (!cityHasSoldier[i]) {
            return false;
        }
    }

    return true;
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    // freopen("akbar.input", "r", stdin); // For testing. Comment out for submissions

    int testCases; cin >> testCases;

    for (int i = 0; i < testCases; i++) {
        if (solve()) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }

    return 0;
}