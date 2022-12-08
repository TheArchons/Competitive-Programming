#include <stdio.h>
#include <stack>

using namespace std;

/*
If the new number = the number of cars in the lake + 1, push it to the lake.
Else if the number on the branch = the number of cars in the lake + 1, push it to the lake.
Else if the the number on the mountain is greater than the current number (or the branch is empty), push it to the branch.
Else, print ("N") and return.
*/

void test() {
    int n;
    scanf("%d", &n);

    stack<int> branch;
    stack<int> mountain;
    for (int i = 0; i < n; i++) {
        int num;
        scanf("%d", &num);

        mountain.push(num);
    }

    for (int lakeNum = 0; lakeNum < n;) {
        int mountainTop = mountain.empty() ? 0 : mountain.top();
        int branchTop = branch.empty() ? 0 : branch.top();

        if (mountainTop == (lakeNum + 1)) {
            mountain.pop();
            lakeNum++;
        } else if (branchTop == (lakeNum + 1)) {
            branch.pop();
            lakeNum++;
        } else if (!branchTop || mountainTop < branchTop) {
            branch.push(mountainTop);
            mountain.pop();
        } else {
            printf("N\n");
            return;
        }
    }

    printf("Y\n");
    return;
}

int main() {
    int testCases;
    scanf("%d", &testCases);
    
    for (int i = 0; i < testCases; i++) {
        test();
    }

    return 0;
}