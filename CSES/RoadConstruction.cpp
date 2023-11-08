#include <bits/stdc++.h>

using namespace std;

const int maxCity = pow(10, 5) + 5;

vector<int> ds(maxCity);
vector<int> dsh(maxCity, 1);

int findRep(int city) {
    while (ds[city] != city) {
        city = ds[city];
    }

    return city;
}

int repUnion(int)

void initDs() {
    for (int i = 0; i < maxCity; i++) {
        ds[i] = i;
    }
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    freopen("RoadConstruction.input", "r", stdin); // For testing. Comment out for submissions

    int cityNum; cin >> cityNum;
    int roadNum; cin >> roadNum;

    initDs();

    for (int i = 0; i < roadNum; i++) {
        int city1; cin >> city1; int city2; cin >> city2;

        
    }

    return 0;
}