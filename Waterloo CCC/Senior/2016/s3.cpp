#include <bits/stdc++.h>

using namespace std;

/*
1. Remove all useless nodes (restaurants that do not lead to a pho restaurant) by doing a DFS from the pho restaurants
2. Pick one pho restaurant that only has one connection as the root (because all useless nodes are removed, it is guaranteed that there is at least one such node)
3. Calculate the depth of each node from the root
    1. Do a DFS from the root
    2. For each node in path, set the depth of the node for max(current depth of node, number of edges between the node and the first node of the path)
4. DFS but choose the node with the lowest depth first.
5. When all restaurants are visited, return the number of edges traveled
*/

int main() {
    //freopen("3.input", "r", stdin); // for testing
    
    int nodes, phoNum;
    scanf("%d %d\n", &nodes, &phoNum);

    set<int> phos;
    for (int i = 0; i < phoNum; i++) {
        int temp;
        scanf("%d", &temp);
        phos.insert(temp);
    }

    map<int, vector<int>> connections;
    for (int i = 0; i < nodes-1; i++) {
        int a, b;
        scanf("%d %d", &a, &b);

        connections[a].push_back(b);
        connections[b].push_back(a);
    }

    // Remove all useless nodes
    set<int> visited, tempVisited;
    vector<int> path;
    path.push_back(*phos.begin());
    
    while (!path.empty()) {
        int current = path.back();
        path.pop_back();
        tempVisited.insert(current);

        if (phos.find(current) == phos.end() && connections[current].size() == 1) {
            visited.insert(current);
        }

        for (int i = 0; i < connections[current].size(); i++) {
            if (tempVisited.find(connections[current][i]) == tempVisited.end()) {
                path.push_back(connections[current][i]);
            }
        }
    }

    // Find the root
    int root;
    for (auto it = phos.begin(); it != phos.end(); it++) {
        if (connections[*it].size() == 1) {
            root = *it;
            break;
        }
    }

    // Calculate the depth of each node
    int depths[nodes] = {0};

    path.push_back(root);
    tempVisited.clear();

    int curr = root;
    int visitedPhoNum = 1;

    while (visitedPhoNum < phos.size()) {
        bool found = false;
        tempVisited.insert(curr);

        // calculate the depth of all nodes in the path
        for (int i = path.size() - 2; i >= 0; i--) {
            depths[path[i]] = max(depths[path[i]], (int)path.size() - i - 1);
        }

        for (int i = 0; i < connections[curr].size(); i++) {
            if (tempVisited.find(connections[curr][i]) == tempVisited.end() && visited.find(connections[curr][i]) == visited.end()) {
                curr = connections[curr][i];
                path.push_back(curr);
                found = true;
                break;
            }
        }

        if (!found) {
            path.pop_back();
            curr = path.back();
        }

        if (phos.find(curr) != phos.end()) {
            visitedPhoNum++;
        }
    }

    // DFS but choose the node with the lowest depth first
    path.clear();
    path.push_back(root);
    curr = root;
    visitedPhoNum = 1;
    int dist = 0;

    while (visitedPhoNum < phos.size()) {
        visited.insert(curr);

        int minDepth = INT_MAX;
        int minDepthNode = -1;

        for (int i = 0; i < connections[curr].size(); i++) {
            if (visited.find(connections[curr][i]) == visited.end()) {
                if (depths[connections[curr][i]] < minDepth) {
                    minDepth = depths[connections[curr][i]];
                    minDepthNode = connections[curr][i];
                }
            }
        }

        if (minDepthNode != -1) {
            curr = minDepthNode;
            path.push_back(curr);
            if (phos.find(curr) != phos.end()) visitedPhoNum++;
        } else {
            path.pop_back();
            curr = path.back();
        }

        dist++;
    }

    printf("%d", dist);

    return 0;
}