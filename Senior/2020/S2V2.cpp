#include <stdio.h>
#include <map>
#include <vector>
#include <tuple>
#include <set>
#include <stack>

using namespace std;

int main() {
    int rows, cols;
    scanf("%d\n%d", &rows, &cols);

    map<int, vector<tuple<int, int>>> poses;

    int room[rows][cols] = {0};

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            int val;
            scanf("%d", &val);
            room[i][j] = val;
            poses[val].push_back(make_tuple(i, j));
        }
    }

    tuple<int, int> curr = make_tuple(rows-1, cols-1);

    set<tuple<int, int>> visited;

    stack<tuple<int, int>> path;

    while (curr != make_tuple(0, 0)) {
        int val = room[get<0>(curr)][get<1>(curr)];
        int find = (get<0>(curr) + 1) * (get<1>(curr) + 1);
        visited.insert(curr);
        path.push(curr);

        bool found = false;
        for (int i = 0; i < poses[find].size(); i++) {
            // if not visited
            if (visited.find(poses[find][i]) == visited.end()) {
                curr = poses[find][i];
                found = true;
                break;
            }
        }

        if (found) {
            poses[val].pop_back();
        } else {
            path.pop();
            if (path.empty()) {
                printf("no");
                return 0;
            }
            curr = path.top();
        }
    }

    printf("yes");

    return 0;
}