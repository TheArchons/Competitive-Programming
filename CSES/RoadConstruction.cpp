#include <bits/stdc++.h>

using namespace std;

const int maxCity = pow(10, 5) + 5;

vector<int> ds(maxCity);
vector<int> dss(maxCity, 1);

int maxSize = 0;
int setNum;

int findRep(int city) {
    while (ds[city] != city) {
        city = ds[city];
    }

    return city;
}

void repUnion(int city1, int city2) {
    // union by sizes because we need to output that anyways
    int city1Rep = findRep(city1);
    int city2Rep = findRep(city2);

    if (city1Rep == city2Rep) return;

    if (dss[city1Rep] < dss[city2Rep]) {
        swap(city1Rep, city2Rep);
    }

    ds[city2Rep] = city1Rep;
    dss[city1Rep] += dss[city2Rep];

    maxSize = max(dss[city1Rep], maxSize);
    setNum--;

    return;
}

void initDs() {
    for (int i = 0; i < maxCity; i++) {
        ds[i] = i;
    }
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    // freopen("RoadConstruction.input", "r", stdin); // For testing. Comment out for submissions

    int cityNum; cin >> cityNum;
    int roadNum; cin >> roadNum;

    initDs();

    setNum = cityNum;

    for (int i = 0; i < roadNum; i++) {
        int city1; cin >> city1; int city2; cin >> city2;

        repUnion(city1, city2);

        cout << setNum << " " << maxSize << endl;
    }

    return 0;
}