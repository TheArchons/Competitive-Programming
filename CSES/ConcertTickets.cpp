//https://cses.fi/problemset/task/1091

#include <stdio.h>
#include <set>

using namespace std;

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    multiset<int> tickets;

    for (int i = 0; i < n; i++) {
        int a;
        scanf("%d", &a);
        tickets.insert(a);
    }

    for (int i = 0; i < m; i++) {
        int maxPrice;
        scanf("%d", &maxPrice);

        multiset<int>::iterator it = tickets.upper_bound(maxPrice);
        if (it == tickets.begin()) {
            printf("-1\n");
        } else {
            it--;
            printf("%d\n", *it);
            tickets.erase(it);
        }
    }
}