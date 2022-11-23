#include <stdio.h>
#include <vector>
#include <unordered_set>
#include <queue>
#include <map>
#include <stack>
#include <set>

using namespace std;

int main() {
    int restaurants, phoNum;
    scanf("%d %d", &restaurants, &phoNum);

    map<int, bool> phoRestaurants; // first = restaurant, second = visited
    for (int i = 0; i < phoNum; i++) {
        int pho;
        scanf("%d", &pho);
        phoRestaurants[pho] = false;
    }

    vector<int> connections[restaurants];

    for (int i = 0; i < restaurants - 1; i++) {
        int a, b;
        scanf("%d %d", &a, &b);

        connections[a].push_back(b);
        connections[b].push_back(a);
    }

    if (phoNum == 1) {
        printf("0");
        return 0;
    }

    
    int head = phoRestaurants.begin()->first;

    phoRestaurants[head] = true;

    // remove all nodes that do not lead to a pho restaurant
    set<int> dontVisit;
    set<int> visited;
    int curr = head;
    stack<int> path;
    path.push(curr);
    while (!path.empty()) {
        bool found = false;
        int connectionNum = 0;
        for (int i = 0; i < connections[curr].size(); i++) {
            int connection = connections[curr][i];
            if (dontVisit.find(connection) == dontVisit.end()) {
                connectionNum++;
            }

        }
        if (connectionNum == 1 && phoRestaurants.find(curr) == phoRestaurants.end()) {
            dontVisit.insert(curr);
        }

        for (int i = 0; i < connections[curr].size(); i++) {
            if (visited.find(connections[curr][i]) == visited.end()) {
                visited.insert(connections[curr][i]);
                path.push(connections[curr][i]);
                curr = connections[curr][i];
                found = true;
                break;
            }
        }
        if (found) {
            continue;
        }

        path.pop();
        if (!path.empty()) {
            curr = path.top();
        }
    }
    
    // find a pho restaurant that only has one connection
    for (int i = 0; i < phoRestaurants.size(); i++) {
        for (int j = 0; j < connections[i].size(); j++) {
            if (dontVisit.find(connections[i][j]) == dontVisit.end()) {
                head = i;
                break;
            }
        }
    }

    // find the depth of each subtree
    map<int, int> depths;
    

    // dfs until all pho restaurants are visited
    int dist = 0;
    visited.clear();
    curr = head;
    path.push(curr);
    int foundNum = 1;

    return 0;
}
