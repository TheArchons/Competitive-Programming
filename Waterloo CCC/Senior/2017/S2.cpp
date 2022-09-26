#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int half(int num) {
    if (num % 2 == 0) {
        return (num / 2)-1;
    } else {
        return (num) / 2;
    }
}

int main() {
    int n;
    scanf("%d", &n);
    if (n == 1) {
        scanf("%d", &n);
        printf("%d\n", n);
        return 0;
    }
    int tides[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &tides[i]);
    }
    sort(tides, tides+n);
    bool flip = false;
    for (int i = half(n); i >= 0; i--) {
        if (tides[i] == tides[n-1-i]) {
            printf("%d ", tides[i]);
            flip = !flip;
            continue;
        }
        if (flip) {
            printf("%d %d ", tides[n-1-i], tides[i]);
        }
        else {
            printf("%d %d ", tides[i], tides[n-1-i]);
        }
    }
}