#include <iostream>
#include <vector>

using namespace std;

bool YTreeSearch(pair<int, int> trees[], int y, int treeLen) {
    for (int i = 0; i < treeLen; i++) {
        if (trees[i].first == y) {
            return true;
        }
    }
    return false;
}

bool XTreeSearch(pair<int, int> trees[], int x, int treeLen) {
    for (int i = 0; i < treeLen; i++) {
        if (trees[i].first == x) {
            return true;
        }
    }
    return false;
}

int areaSearch(pair<int, int> trees[], int x, int y, int treeCount, int area) {
    //find the closest tree to the bottom left
    int max = 0;
    int currX = x;
    while (currX > 0 && !XTreeSearch(trees, currX, treeCount)) {
        currX--;
    }
    if (x-currX > max) {
        max = x-currX;
    }

    //find the closest tree to the right
    currX = x;
    while (currX < treeCount && !XTreeSearch(trees, currX, treeCount)) {
        currX++;
    }
    if (currX-x > max) {
        max = currX-x;
    }

    //find the closest tree to the top
    int currY = y;
    while (currY > 0 && !YTreeSearch(trees, currY, treeCount)) {
        currY--;
    }
    if (y-currY > max) {
        max = y-currY;
    }

    //find the closest tree to the bottom
    currY = y;
    while (currY < treeCount && !YTreeSearch(trees, currY, treeCount)) {
        currY++;
    }
    if (currY-y > max) {
        max = currY-y;
    }

    return max;
}

int main() {
    int area, trees, maxLen = 0;
    scanf("%d %d", &area, &trees);
    pair<int, int> treePos[trees]; //check if ccc allows this
    for (int i = 0; i < trees; i++) {
        scanf("%d %d", &treePos[i].second, &treePos[i].first);
    }

    //search for the largest area in the adjacent squares to the tree
    for (int i = 0; i < trees; i++) {
        //search all 8 directions
        int x = treePos[i].first;
        int y = treePos[i].second;
        x--; //left
        int currArea = areaSearch(treePos, x, y, trees, area);
        if (currArea > maxLen) {
            maxLen = currArea;
        }
        x++; x++; //right
        currArea = areaSearch(treePos, x, y, trees, area);
        if (currArea > maxLen) {
            maxLen = currArea;
        }
        y--; x--; //up
        currArea = areaSearch(treePos, x, y, trees, area);
        if (currArea > maxLen) {
            maxLen = currArea;
        }
        y++; y++; //down
        currArea = areaSearch(treePos, x, y, trees, area);
        if (currArea > maxLen) {
            maxLen = currArea;
        }
    }

    printf("%d\n", maxLen);
}