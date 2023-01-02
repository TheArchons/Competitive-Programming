#include <bits/stdc++.h>

using namespace std;

struct Friend {
    int position, walkSpeed, hearDist;
}p;

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    //freopen("3.input", "r", stdin); // for testing
    
    int friendNum;
    cin >> friendNum;

    vector<int> diffs(1000000);
    int minFriend, maxFriend;
    minFriend = INT_MAX;
    maxFriend = 0;
    vector<Friend> friends(friendNum);

    for (int i = 0; i < friendNum; i++) {
        int p, w, d;
        cin >> p >> w >> d;

        friends[i] = {p, w, d};
    }

    for (auto [p, w, d] : friends) {
        diffs[max(p-d, 0)] += w;
        diffs[p+d] += w;

        minFriend = min(minFriend, max(p-d, 0));
        maxFriend = max(maxFriend, p);
    }

    int walkDist = 0;
    int currDiff = 0;

    for (auto [p, w, d] : friends) {
        currDiff -= w;
        if (p - d > minFriend) {
            walkDist += (p - d - minFriend) * w;
        }
    }

    currDiff += diffs[minFriend];

    int minWalkDist = walkDist;

    for (int i = minFriend+1; i <= maxFriend; i++) {
        walkDist += currDiff;
        minWalkDist = min(minWalkDist, walkDist);
        currDiff += diffs[i];
    }

    cout << minWalkDist << endl;

    return 0;
}