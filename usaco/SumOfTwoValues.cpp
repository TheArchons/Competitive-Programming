#include <stdio.h>
#include <map>
#include <chrono>

using namespace std;

int main() {
    int arrLen, target;
    scanf("%d %d", &arrLen, &target);

    int arr[arrLen];
    map<int, int> map;
    
    for (int i = 0; i < arrLen; i++) {
        scanf("%d", &arr[i]);
        map[arr[i]] = i;
    }

    for (int i = 0; i < arrLen; i++) {
        int diff = target - arr[i];
        if (map.count(diff) && map[diff] != i) {
            printf("%d %d", i + 1, map[diff] + 1);
            return 0;
        }
    }

    printf("IMPOSSIBLE");
    return 0;
}