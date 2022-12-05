#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("3.input", "r", stdin); // for testing
    
    int gates, planes;
    scanf("%d\n%d", &gates, &planes);

    set<int> available;

    for (int i = 1; i <= gates; i++) {
        available.insert(i);
    }

    int count = 0;

    for (int i = 0; i < planes; i++) {
        int plane;
        scanf("%d", &plane);

        auto it = available.upper_bound(plane);
        if (it == available.begin()) {
            break;
        }
        it--;

        available.erase(it);
        count++;
    }

    printf("%d", count);
    return 0;
}