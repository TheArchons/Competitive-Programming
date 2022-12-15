
#include <bits/stdc++.h>

using namespace std;

// takes a vector<int> and target, and returns the number of combinations of the vector that add up to the target
int twoSum(vector<int> nums, int target) {
    int count = 0;

    multiset<int> numDiffs;

    for (int i = 0; i < nums.size(); i++) {
        if (numDiffs.find(nums[i]) != numDiffs.end()) {
            count++;
            numDiffs.erase(numDiffs.find(nums[i]));
        } else {
            numDiffs.insert(target - nums[i]);
        }
    }

    return count;
}

int main() {
    //freopen("3.input", "r", stdin); // for testing
    
    int n;
    scanf("%d", &n);

    vector<int> boards(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &boards[i]);
    }

    int maxLen, maxLenCount;
    maxLen = maxLenCount = 0;

    for (int i = 0; i < 4001; i++) {
        int count = twoSum(boards, i);
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