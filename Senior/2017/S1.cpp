#include <iostream>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    int swifts[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &swifts[i]);
    }
    int swiftCount, semaCount, maxpos;
    swiftCount = semaCount = maxpos = 0;
    for (int i = 0; i < n; i++) {
        int curr;
        scanf("%d", &curr);
        swiftCount += swifts[i];
        semaCount += curr;
        if (swiftCount == semaCount) {
            maxpos = i+1;
        }
    }
    printf("%d\n", maxpos);
    return 0;
}