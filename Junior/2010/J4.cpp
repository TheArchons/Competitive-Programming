#include <iostream>
#include <stack>
#include <queue>
#include <unordered_set>

using namespace std;

int minCycle(int nums[], int len) {
    unordered_set<int> visited;
    int currPos = 0;
    queue<int> cycle;
    int minCycle = 0, lastCycle = 0;
    bool inCycle = true;
    //find the minimum cycle that repeats itself
    while(true) {
        int currChange = nums[currPos] - nums[currPos + 1];
        //if the first element in cycle is the same as currChange, then we might have a cycle
        if (!cycle.empty() && currChange == cycle.front()) {
            //keep searching until the cycle doesn't match up
            inCycle = true;
        }
        //else if (cycle.empty() && )
        else {
            if (inCycle) {
                //backtrack to before the cycle and mark the position as visited

            }
            //if the cycle doesn't start with the same number, add it to the cycle
            cycle.push(currChange);
        }
    }

    return nums[0];
}

int main() {
    int len = -1;
    while (len != 0) {
        scanf("%d", &len);
        if (len == 0) {
            break;
        }
        int nums[len];
        for (int i = 0; i < len; i++) {
            scanf("%d", &nums[i]);
        }
        printf("%d\n", minCycle(nums, len));
    }
}