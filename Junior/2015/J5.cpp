#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

bool isVisited(vector<vector<int>>& visited, vector<int>& curr) {
    //check if the current vector is visited with binary search
    int left = 0, right = visited.size()-1;
    while (left <= right) {
        int mid = (left+right)/2;
        if (visited[mid] == curr) {
            return true;
        } else if (visited[mid] < curr) {
            left = mid+1;
        } else {
            right = mid-1;
        }
    }
    return false;
}

int main() {
    int pieCount, peopleCount;
    scanf("%d\n%d", &pieCount, &peopleCount);
    //array of pie distribution, the last one receiving all pies
    vector<int> pies(peopleCount);
    //set all people's pies to 1
    for (int i = 0; i < peopleCount; i++) {
        pies[i] = 1;
    }
    pies[peopleCount-1] += pieCount-peopleCount;
    queue<vector<int>> toVisit; toVisit.push(pies);
    vector<vector<int>> visited; visited.push_back(pies);
    //distribute the pies
    int distCount = 1;
    while (!toVisit.empty()) {
        pies = toVisit.front(); toVisit.pop();
        for (int i = peopleCount-1; i > 0; i--) {
            for (int j = i-1; j >= 0; j--) {
                pies[i]--;
                pies[j]++;
                if (pies[i] >= pies[i-1] && pies[j] <= pies[j+1] && !isVisited(visited, pies)) {
                    distCount++;
                    toVisit.push(pies); visited.push_back(pies);
                    //goto next;
                }
                else{
                    pies[i]++;
                    pies[j]--;
                }
            }
        }
    }
    printf("%d\n", distCount);
}