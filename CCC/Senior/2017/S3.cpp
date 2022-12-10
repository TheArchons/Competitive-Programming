
#include <bits/stdc++.h>

using namespace std;

/*
Try every combination of boards and increment the value in a hashmap of the corresponding sum.
Then, iterate through the hashmap and find the maximum value and number of values with the maximum value.
*/

int main() {
    freopen("3.input", "r", stdin); // for testing
    
    int n;
    scanf("%d", &n);

    int boards[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &boards[i]);
    }

    unordered_map<int, int> sums;
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            sums[boards[i] + boards[j]]++;
        }
    }

    int max = 0;
    int maxCount = 0;

    for (auto it = sums.begin(); it != sums.end(); it++) {
        if (it->second > max) {
            max = it->second;
            maxCount = 1;
        } else if (it->second == max) {
            maxCount++;
        }
    }

    printf("%d %d", max, maxCount);

    return 0;
}