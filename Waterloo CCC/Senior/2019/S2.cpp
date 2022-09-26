#include <iostream>
#include <unordered_set>
using namespace std;

unordered_set<int> notPrime;

bool isPrime(int n) {
    if (n == 1) {
        return false;
    }
    if (n == 2) {
        return true;
    }
    for (int i = 2; i*i <= n; i++) {
        if (n%i == 0) {
            return false;
        }
    }
    return true;
}

pair<int, int> pettyAveragePrimes(int target) {
    target *= 2;
    int num1, num2;
    num1 = 0;
    num2 = target;
    while (num1 < num2) {
        if (isPrime(num1) && isPrime(num2)) {
            return make_pair(num1, num2);
        }
        num1++;
        num2--;
    }
    return make_pair(target, target+1);
}

int main() {
    int len;
    scanf("%d", &len);
    for (int i = 0; i < len; i++) {
        int target;
        scanf("%d", &target);
        pair<int, int> result = pettyAveragePrimes(target);
        printf("%d %d\n", result.first, result.second);
    }
}