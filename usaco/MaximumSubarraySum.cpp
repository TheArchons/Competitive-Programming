#include <stdio.h>
#include <algorithm>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);

    int a[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    long long sum = 0;
    long long max = a[0];
    for (int i = 0; i < n; i++) {
        if (sum + a[i] > a[i]) {
            sum += a[i];
        } else {
            sum = a[i];
        }
        if (sum > max) {
            max = sum;
        }
    }

    printf("%lld", max);
}