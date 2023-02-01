#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    //freopen("1.input", "r", stdin); // for testing

    int cowNum;
    cin >> cowNum;

    vector<bool> cows(cowNum); // true = G, false = H
    int gCount = 0;

    for (int i = 0; i < cowNum; i++) {
        char c;
        cin >> c;

        cows[i] = c == 'G';
        if (c == 'G')
            gCount++;
    }

    int hCount = cowNum - gCount;

    vector<int> cowLists(cowNum);
    for (int i = 0; i < cowNum; i++) {
        int num;
        cin >> num;

        cowLists[i] = num;
    }

    bool hasHLeader, hasGLeader;
    int hLeaderPos, gLeaderPos;
    hasHLeader = hasGLeader = false;
    // find gLeader
    for (int i = 0; i < cowNum; i++) {
        if (cows[i]) {
            gLeaderPos = i;
            int tempCount = gCount;
            for (int j = i; j < cowLists[i]; j++) {
                if (cows[j])
                    tempCount--;
            }

            if (!tempCount) {
                hasGLeader = true;
                
            }
            break;
        }
    }

    // find hLeader
    for (int i = 0; i < cowNum; i++) {
        if (!cows[i]) {
            hLeaderPos = i;
            int tempCount = hCount;
            for (int j = i; j < cowLists[i]; j++) {
                if (!cows[j])
                    tempCount--;
            }

            if (!tempCount) {
                hasHLeader = true;
            }
            break;
        }
    }

    int ans = 0;

    int hLeaderCount = 0, gLeaderCount = 0;
    if (hasHLeader) {
        for (int i = 0; i < hLeaderPos; i++) {
            if (cows[i] && (!hasGLeader || i != gLeaderPos)) {
                if (cowLists[i] > hLeaderPos)
                    gLeaderCount++;
            }
        }
        ans += gLeaderCount;
    }

    if (hasGLeader) {
        for (int i = 0; i < gLeaderPos; i++) {
            if (!cows[i] && (!hasHLeader || i != hLeaderPos)) {
                if (cowLists[i] > gLeaderPos)
                    hLeaderCount++;
            }
        }

        ans += hLeaderCount;
    }

    if (hasHLeader && hasGLeader) {
        ans++;
    }

    cout << ans << endl;

    return 0;
}