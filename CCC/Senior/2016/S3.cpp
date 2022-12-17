#include <bits/stdc++.h>

using namespace std;

/*
1. Remove all useless nodes
2. Find the longest path
3. Find the longest path from the longest path and set to root
4. Find the distance to visit all pho restaurants from the root
5. calculate the longest path from the root
6. print 2 * (total distance) - (longest path from root)
*/

int main() {
    //freopen("3.input", "r", stdin); // for testing
    
    int restaurantNum, phoNum;
    scanf("%d %d", &restaurantNum, &phoNum);

    vector<bool> phoRestaurants(restaurantNum, false);

    int phoBegin;
    
    for (int i = 0; i < phoNum; i++) {
        int phoRestaurant;
        scanf("%d", &phoRestaurant);
        if (i == 0) {
            phoBegin = phoRestaurant;
        }
        phoRestaurants[phoRestaurant] = true;
    }

    vector<vector<int>> graph(restaurantNum);
    
    for (int i = 0; i < restaurantNum - 1; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    // Remove all useless nodes and calculate the longest path
    vector<bool> visited(restaurantNum, false);
    vector<bool> tempVisited(restaurantNum, false);
    stack<int> path;
    path.push(phoBegin);

    int currDist, maxDist, maxDistNode;
    currDist = maxDist = maxDistNode = 0;

    // start clock
    auto start = chrono::high_resolution_clock::now();

    while (!path.empty()) {
        int currNode = path.top();
        tempVisited[currNode] = true;

        bool found = false;

        if (!phoRestaurants[currNode]) {
            int connections = 0;
            for (int i = 0; i < graph[currNode].size(); i++) {
                int nextNode = graph[currNode][i];
                if (!visited[nextNode]) {
                    connections++;
                    if (connections > 1) {
                        break;
                    }
                }
            }

            if (connections <= 1) {
                visited[currNode] = true;
            }
        }

        int nextNode;

        for (int i = 0; i < graph[currNode].size(); i++) {
            nextNode = graph[currNode][i];
            if (!tempVisited[nextNode]) {
                path.push(nextNode);
                found = true;
                break;
            }
        }

        if (!found) {
            path.pop();
            currDist--;
        } else {
            currDist++;
            if (currDist > maxDist && phoRestaurants[nextNode]) {
                maxDist = currDist;
                maxDistNode = nextNode;
            }
        }
    }

    // Find the longest path from the longest path and set to root
    tempVisited = visited;
    path.push(maxDistNode);
    currDist = maxDistNode = maxDist = 0;

    int totalDist = 0;

    while (!path.empty()) {
        int currNode = path.top();
        tempVisited[currNode] = true;

        bool found = false;
        int nextNode;

        for (int i = 0; i < graph[currNode].size(); i++) {
            nextNode = graph[currNode][i];
            if (!tempVisited[nextNode]) {
                path.push(nextNode);
                found = true;
                break;
            }
        }

        if (!found) {
            path.pop();
            currDist--;
        } else {
            currDist++;
            totalDist++;
            if (currDist > maxDist && phoRestaurants[nextNode]) {
                maxDist = currDist;
                maxDistNode = nextNode;
            }
        }
    }

    printf("%d", 2 * totalDist - maxDist);

    return 0;
}