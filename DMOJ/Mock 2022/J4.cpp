#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int students, rounds;
    scanf("%d %d", &students, &rounds);
    vector<queue<int>> targets;
    vector<int> prev;
    for (int i = 0; i < students; i++) {
        int target;
        scanf("%d", &target);
        targets.push_back(queue<int>());
        targets[i].push(target);
        prev.push_back(target);
    }
    
    for (int i = 0; i < rounds-1; i++) {
        vector<queue<int>> newTargets = targets;
        for (int j = 0; j < students-1; j++) {
            //ignore empty queue
            if (targets[j].empty()) {
                continue;
            }
            int target = targets[j].front();
            newTargets[j].pop();
            newTargets[target-1].push(j+1);
        }
        targets = newTargets;
        //set prev to first element of each queue
        for (int j = 0; j < students-1; j++) {
            if (!targets[j].empty()) {
                prev[j] = targets[j].front();
            } 
        }
    }
    for (int i = 0; i < students-1; i++) {
        printf("%d ", prev[i]);
    }
    printf("%d\n", prev[students-1]);
    return 0;
}