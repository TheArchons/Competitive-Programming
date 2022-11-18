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
    
    int head = phoRestaurants.begin()->first;
    phoRestaurants[head] = true;
    

    // remove all nodes that do not lead to a pho restaurant
    set<int> dontVisit;
    set<int> visited;
    stack<int> path;
    int curr = head;
    path.push(curr);

    curr = head;

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

    // dfs for a pho restaurant, and add dist to the total and set the restaurant to tail
    // note how it is now guaranteed that the path will arrive at a pho restaurant as long as we dont visit a dontVisit node
    int tail = head;
    int dist = 0;
    do {
        for (int i = 0; i < connections[tail].size(); i++) {
            if (dontVisit.find(connections[tail][i]) == dontVisit.end()) {
                if (phoRestaurants.find(connections[tail][i]) != phoRestaurants.end()) {
                    if (phoRestaurants[connections[tail][i]]) {
                        continue;
                    }
                }
                tail = connections[tail][i];
                dist++;
                dontVisit.insert(tail);
                break;
            }
        }
    }
    while (phoRestaurants.find(tail) == phoRestaurants.end());

    phoRestaurants[tail] = true;

    curr = head;
    path = stack<int>();
    path.push(head);
    int tempDist = 0;
    while (!path.empty()) {
        bool continueNow = false;
        for (int i = 0; i < connections[curr].size(); i++) {
            if (!phoRestaurants[connections[curr][i]] && dontVisit.find(connections[curr][i]) == dontVisit.end()) {
                curr = connections[curr][i];
                tempDist++;
                if (phoRestaurants.find(curr) != phoRestaurants.end()) {
                    dist += tempDist;
                    tempDist = 0;
                }
                path.push(curr);
                phoRestaurants[curr] = true;
                continueNow = true;
                break;
            }
        }
        if (continueNow) {
            continue;
        }

        path.pop();
        tempDist++;
        if (!path.empty()) {
            curr = path.top();
        }
    }

    curr = tail;
    path = stack<int>();
    path.push(tail);
    tempDist = 0;
    while (!path.empty()) {
        bool continueNow = false;
        for (int i = 0; i < connections[curr].size(); i++) {
            if (!phoRestaurants[connections[curr][i]] && dontVisit.find(connections[curr][i]) == dontVisit.end()) {
                curr = connections[curr][i];
                tempDist++;
                if (phoRestaurants.find(curr) != phoRestaurants.end()) {
                    dist += tempDist;
                    tempDist = 0;
                }
                path.push(curr);
                phoRestaurants[curr] = true;
                continueNow = true;
                break;
            }
        }
        if (continueNow) {
            continue;
        }

        path.pop();
        tempDist++;
        if (!path.empty()) {
            curr = path.top();
        }
    }

    printf("%d", dist);
    return 0;
}