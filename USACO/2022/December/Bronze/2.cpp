#include <bits/stdc++.h>

using namespace std;

unordered_map<char, int> cowTypeMap = {
    {'H', 0},
    {'G', 1}
};

void testCase() {
    int cows, cowDist;
    scanf("%d %d\n", &cows, &cowDist);

    vector<int> cowPos;
    for (int i = 0; i < cows; i++) {
        char temp;
        scanf("%c", &temp);
        cowPos.push_back(cowTypeMap[temp]);
    }

    set<int> gGrassPos, hGrassPos;

    for (int i = 0; i < cows; i++) {
        int curr = cowPos[i];
        if (!curr) {
            auto it = hGrassPos.lower_bound(i);
            if (it != hGrassPos.end() && *it - i <= cowDist) {
                continue;
            }

            if (it != hGrassPos.begin()) {
                it--;
                if (i - *it <= cowDist) {
                    continue;
                }
            }

            // if cowDist + i > cows, then set it to the furthest empty position
            if (i + cowDist >= cows) {
                for (int j = cows - 1; j >= 0; j--) {
                    if (hGrassPos.find(j) == hGrassPos.end() && gGrassPos.find(j) == gGrassPos.end()) {
                        hGrassPos.insert(j);
                        break;
                    }
                }
            } else {
                hGrassPos.insert(i + cowDist);
            }
        } else {
            auto it = gGrassPos.lower_bound(i);
            if (it != gGrassPos.end() && *it - i <= cowDist) {
                continue;
            }

            if (it != gGrassPos.begin()) {
                it--;
                if (i - *it <= cowDist) {
                    continue;
                }
            }

            // if cowDist + i > cows, then set it to the furthest empty position
            if (i + cowDist >= cows) {
                for (int j = cows - 1; j >= 0; j--) {
                    if (hGrassPos.find(j) == hGrassPos.end() && gGrassPos.find(j) == gGrassPos.end()) {
                        gGrassPos.insert(j);
                        break;
                    }
                }
            } else {
                gGrassPos.insert(i + cowDist);
            }
        }
    }

    printf("%d\n", gGrassPos.size() + hGrassPos.size());

    for (int i = 0; i < cows; i++) {
        if (gGrassPos.find(i) != gGrassPos.end()) {
            printf("G");
        } else if (hGrassPos.find(i) != hGrassPos.end()) {
            printf("H");
        } else {
            printf(".");
        }
    }

    printf("\n");

    return;
}

int main() {
    int t;
    scanf("%d", &t);

    for (int i = 0; i < t; i++) {
        scanf("\n");
        testCase();
    }

    return 0;
}
