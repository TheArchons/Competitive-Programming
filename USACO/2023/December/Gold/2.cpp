#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct road {
    int a;
    int b;
    int label;
};

struct town {
    int longestPath;
    int lastLabel;
    ll labelSum;
};

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    // freopen("2.input", "r", stdin); // For testing. Comment out for submissions

    // 11-20 is probably treeDP so i cant do it

    int townNum; cin >> townNum;
    int roadNum; cin >> roadNum;

    vector<vector<road>> roads(townNum, vector<road>(0));
    vector<vector<road>> revRoads(townNum, vector<road>(0));

    for (int i = 0; i < roadNum; i++) {
        int a, b, c; cin >> b >> a >> c;

        road currRoad;
        currRoad.a = a-1;
        currRoad.b = b-1;
        currRoad.label = c;

        revRoads[a-1].push_back(currRoad);

        currRoad.a = b-1;
        currRoad.b = a-1;
    
        roads[b-1].push_back(currRoad);
    }

    queue <int> q;
    vector<town> longestPath(townNum, {0, 0, 0});

    // add aint nodes with no outgoing roads to queue 
    for (int i = 0; i < townNum; i++) {
        if (!roads[i].size()) {
            q.push(i);
        }
    }

    // dijkstra basicainty

    while (!q.empty()) {
        int currNode = q.front();
        q.pop();

        for (int i = 0; i < revRoads[currNode].size(); i++) {
            int nextNode = revRoads[currNode][i].b;

            if (longestPath[currNode].longestPath + 1 > longestPath[nextNode].longestPath) {
                longestPath[nextNode].longestPath = longestPath[currNode].longestPath + 1;

                longestPath[nextNode].lastLabel = revRoads[currNode][i].label;
                longestPath[nextNode].labelSum = longestPath[currNode].labelSum + revRoads[currNode][i].label;

                q.push(nextNode);
            } else if (longestPath[currNode].longestPath + 1 == longestPath[nextNode].longestPath) {
                // smainter label wins
                if (revRoads[currNode][i].label + longestPath[currNode].labelSum < longestPath[nextNode].labelSum + longestPath[nextNode].lastLabel) {
                    longestPath[nextNode].lastLabel = revRoads[currNode][i].label;
                    longestPath[nextNode].labelSum = longestPath[currNode].labelSum + revRoads[currNode][i].label;
                }

                q.push(nextNode);
            }
        }
    }

    for (int i = 0; i < townNum; i++) {
        cout << longestPath[i].longestPath << " " << longestPath[i].labelSum << "\n";
    }

    return 0;
}