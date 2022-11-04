#include <stdio.h>
#include <set>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int cities[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &cities[i]);
    }

    multiset<int> towers;
    for (int i = 0; i < m; i++) {
        int a;
        scanf("%d", &a);
        towers.insert(a);
    }

    int maxRange = 0;
    for (int i = 0; i < n; i++) {
        multiset<int>::iterator towerIt = towers.lower_bound(cities[i]);
        if (towerIt == towers.end()) {
            towerIt--;
            int diff = abs(cities[i] - *towerIt);
            if (diff > maxRange) {
                maxRange = diff;
            }
            continue;
        }

        int diff1 = abs(cities[i] - *towerIt);
        towerIt--;
        int diff2 = abs(cities[i] - *towerIt);
        diff1 = max(diff1, diff2);
        
        if (diff1 > maxRange) {
            maxRange = diff1;
        }
    }

    printf("%d", maxRange);
}