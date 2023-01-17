#include <bits/stdc++.h>

using namespace std;

int costMultiplier;

struct city {
    int days = 0;
    int cost = 0;
};

int calculateCosts(city currCity) {
    return currCity.cost - (costMultiplier*pow(currCity.days, 2));
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    freopen("1.input", "r", stdin); // for testing
    // for USACO grader
    //freopen("time.in", "r", stdin);
    //freopen("time.out", "w", stdout);
    
    int cityNum, roadNum;
    cin >> cityNum >> roadNum >> costMultiplier;

    vector<int> cityCosts(cityNum+1);
    for (int i = 1; i <= cityNum; i++) {
        cin >> cityCosts[i];
    }

    vector<vector<int>> connections(cityNum+1);
    for (int i = 0; i < roadNum; i++) {
        int city1, city2;
        cin >> city1 >> city2;

        connections[city1].push_back(city2);
    }

    vector<city> maxCityMoney(cityNum+1);

    queue<int> toVisit;
    toVisit.push(1);

    while (!toVisit.empty()) {
        int curr = toVisit.front();
        city currCity = maxCityMoney[curr];
        toVisit.pop();

        for (int i = 0; i < connections[curr].size(); i++) {
            int next = connections[curr][i];
            city nextCity = currCity;
            nextCity.days++;
            nextCity.cost += cityCosts[next];

            int currNextCost = calculateCosts(nextCity);
            if (currNextCost <= calculateCosts(maxCityMoney[next])) {
                continue;
            }

            toVisit.push(next);
            maxCityMoney[next] = nextCity;
        }
    }

    cout << calculateCosts(maxCityMoney[1]) << endl;
    return 0;
}