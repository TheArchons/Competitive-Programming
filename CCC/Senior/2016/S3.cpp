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

    set<int> phoRestaurants;
    
    for (int i = 0; i < phoNum; i++) {
        int phoRestaurant;
        scanf("%d", &phoRestaurant);
        phoRestaurants.insert(phoRestaurant);
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
    path.push(*phoRestaurants.begin());

    int currDist, maxDist, maxDistNode;
    currDist = maxDist = maxDistNode = 0;

    while (!path.empty()) {
        int currNode = path.top();
        tempVisited[currNode] = true;

        if (phoRestaurants.find(currNode) == phoRestaurants.end()) {
            int connections = 0;
            for (int i = 0; i < graph[currNode].size(); i++) {
                int nextNode = graph[currNode][i];
                if (!visited[nextNode]) {
                    connections++;
                }
            }

            if (connections <= 1) {
                visited[currNode] = true;
            }
        }

        bool found = false;

        for (int i = 0; i < graph[currNode].size(); i++) {
            int nextNode = graph[currNode][i];
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
            if (currDist > maxDist && phoRestaurants.find(currNode) != phoRestaurants.end()) {
                maxDist = currDist;
                maxDistNode = path.top();
            }
        }
    }

    // Find the longest path from the longest path and set to root
    tempVisited = visited;
    path.push(maxDistNode);
    currDist = maxDistNode = maxDist = 0;

    while (!path.empty()) {
        int currNode = path.top();
        tempVisited[currNode] = true;

        bool found = false;

        for (int i = 0; i < graph[currNode].size(); i++) {
            int nextNode = graph[currNode][i];
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
            if (currDist > maxDist && phoRestaurants.find(path.top()) != phoRestaurants.end()) {
                maxDist = currDist;
                maxDistNode = path.top();
            }
        }
    }

    // Find the distance to visit all pho restaurants from the root and calculate the longest path from the root
    int totalDist;
    totalDist = currDist = maxDist = 0;

    path.push(maxDistNode);

    while (!path.empty()) {
        int currNode = path.top();
        visited[currNode] = true;

        bool found = false;
        
        for (int i = 0; i < graph[currNode].size(); i++) {
            int nextNode = graph[currNode][i];
            if (!visited[nextNode]) {
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
            if (currDist > maxDist && phoRestaurants.find(path.top()) != phoRestaurants.end()) {
                maxDist = currDist;
            }
        }
    }

    printf("%d", 2 * totalDist - maxDist);

    return 0;
}