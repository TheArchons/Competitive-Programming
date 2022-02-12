#include <iostream>
#include <unordered_map>
#include <unordered_set>

using namespace std;

int main() {
    //take input
    int fenceLen;
    scanf("%d ", &fenceLen);
    int fence[fenceLen];
    for (int i = 0; i < fenceLen; i++) {
        if (i+1 == fenceLen) {
            scanf("%d", &fence[i]);
        } else {
            scanf("%d ", &fence[i]);
        }
    }

    //iterate through every pair
    unordered_map<int, int> sumCounts;
    unordered_set<int> heights;
    int max = 0;
    for (int i = 0; i < fenceLen; i++) {
        for (int j = i+1; j < fenceLen; j++) {
            sumCounts[fence[i]+fence[j]]++;
            if (sumCounts[fence[i]+fence[j]] > max) {
                max = sumCounts[fence[i]+fence[j]];
                heights = unordered_set<int>();
            }
            if (sumCounts[fence[i]+fence[j]] == max) {
                heights.insert(fence[i]+fence[j]);
            }
        }
    }
    printf("%d %d\n", max, heights.size());
    return 0;
}