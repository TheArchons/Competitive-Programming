#include <iostream>

using namespace std;

int main() {
    int area, treeCount, maxLen;
    scanf("%d %d", &area, &treeCount);
    pair<int, int> trees[treeCount];
    for (int i = 0; i < treeCount; i++) {
        scanf("%d %d", &trees[i].first, &trees[i].second);
    }
    maxLen = 0;
    int currX, currY;
    //calculate the closest tree from the current square
    
}