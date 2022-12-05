https://cses.fi/problemset/task/1068

#include <stdio.h>
#include <stdint.h>
using namespace std;

int main() {
    long long n;
    scanf("%lld", &n);
    while (n != 1) {
        printf("%lld ", n);
        if (n%2 == 0) {
            n /= 2;
        }
        else {
            n = n*3 + 1;
        }
    }
    printf("1");
}