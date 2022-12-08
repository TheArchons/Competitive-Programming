#include <iostream>
#include <vector>
#include <stack>
#include <unordered_set>

using namespace std;

bool vectorPairSearch(vector<pair<int, int>>& v, int x, int y) {
    for (int i = 0; i < v.size(); i++) {
        if (v[i].first == x && v[i].second == y) {
            return true;
        }
    }
    return false;
}

pair<int, int> matrixSearch(vector<vector<int>> &matrix, int find, vector<pair<int, int>> &visited) {
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[0].size(); j++) {
            if (matrix[i][j] == find && !vectorPairSearch(visited, i, j)) {
                return make_pair(i, j);
            }
        }
    }
    return make_pair(-1, -1);
}

int main() {
    int xLen, yLen;
    scanf("%d %d", &yLen, &xLen);
    vector<vector<int>> matrix(yLen, vector<int>(xLen));
    for (int i = 0; i < yLen; i++) {
        for (int j = 0; j < xLen; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    stack<pair<int, int>> path;
    vector<pair<int, int>> visited;
    path.push(make_pair(xLen-1, yLen-1));
    pair<int, int> curr;
    visited.push_back(make_pair(xLen, yLen));
    while (!path.empty() && (path.top().first != 0 || path.top().second != 0)) {
        curr = path.top();
        //printf("%d\n", matrix[curr.first-1][curr.second-1]);
        pair<int, int> next = matrixSearch(matrix, (curr.first+1)*(curr.second+1), visited);
        if (next.first == -1) {
            path.pop();
        } else {
            path.push(next);
            visited.push_back(next);
        }
    }
    if (path.empty()) {
        printf("no");
    } else {
        printf("yes");
    }
    return 0;
}