//https://cses.fi/problemset/task/1641

#include <map>
#include <stdio.h>

using namespace std;

int main() {
    int n, x;
    scanf("%d %d", &n, &x);

    map<int, int> map;
    int values[n] = {0};
    for (int i = 0; i < n; i++) {
        int a;
        scanf("%d", &a);
        map[x-a] = i;
        values[i] = a;
    }

    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            int sum = values[i] + values[j];
            if (map.find(sum) != map.end()) {
                int k = map[sum];
                if (k != i && k != j) {
                    printf("%d %d %d", i+1, j+1, k+1);
                    return 0;
                }
            }
        }
    }

    printf("IMPOSSIBLE");
}