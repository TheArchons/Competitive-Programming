#include <stdio.h>
using namespace std;

int main() {
    freopen("div7.in", "r", stdin); freopen("div7.out", "w", stdout);

    int n;
    scanf("%d", &n);
    unsigned long long prefix[n];
    unsigned long long sum = 0;
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        sum += x;
        prefix[i] = sum;
    }

    int max = 0;
    for (int i = n-1; i >= 0; i--) {
        for (int j = 0; j <= i; j++) {
            if (i-j < max) {
                break;
            }

            unsigned long long diff;
            if (j > 0) {
                diff = prefix[i] - prefix[j-1];
            }
            else {
                diff = prefix[i];
            }
            if (diff % 7 == 0) {
                max = i - j + 1;
            }
        }
    }

    printf("%d", max);
}