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

    for (int max = n-1; max > 0; max--) {
        if (!(prefix[max] % 7)) {
            printf("%d", max+1);
            return 0;
        }

        for (int end = n-1; end > max; end--) {
            unsigned long long diff;
            diff = prefix[end] - prefix[end - max - 1];

            if (!(diff % 7)) {
                printf("%d", max+1);
                return 0;
            }
        }
    }
    
    printf("0");
}