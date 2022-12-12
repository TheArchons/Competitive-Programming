#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("1.input", "r", stdin); // for testing
    
    int villageNum;
    scanf("%d", &villageNum);

    set<int> villages;
    for (int i = 0; i < villageNum; i++) {
        int village;
        scanf("%d", &village);
        villages.insert(village);
    }

    double minNeighbour = INT_MAX;
    for (auto it = villages.begin(); it != villages.end(); it++) {
        if (it == villages.begin() || it == --villages.end()) continue;
        auto left = it;
        auto right = it;
        left--; right++;
        double leftDist = abs(*it - *left) / 2.0;
        double rightDist = abs(*right - *it) / 2.0;
        minNeighbour = min(minNeighbour, (leftDist + rightDist));
    }

    printf("%.1f", minNeighbour);
}
