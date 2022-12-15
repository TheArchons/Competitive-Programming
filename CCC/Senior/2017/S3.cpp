#include <bits/stdc++.h>

using namespace std;

int boards[4001];

// takes a target, and returns the number of combinations of the map that add up to the target
int twoSum(int target) {
    int count = 0;

    for (int i = 1; i <= target/2; i++) {
        if (boards[i] > 0 && boards[target - i] > 0) {
            if (i == target - i) {
                count += boards[i] / 2;
            } else {
                count += min(boards[i], boards[target - i]);
            }
        }
    }

    return count;
}

int main() {
    //freopen("3.input", "r", stdin); // for testing

    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int temp;
        scanf("%d", &temp);

        boards[temp]++;
    }

    int maxLen, maxLenCount;
    maxLen = maxLenCount = 0;

    for (int i = 0; i < 4001; i++) {
        int count = twoSum(i);
        if (count > maxLen) {
            maxLen = count;
            maxLenCount = 1;
        } else if (count == maxLen) {
            maxLenCount++;
        }
    }

    printf("%d %d", maxLen, maxLenCount);
    return 0;
}