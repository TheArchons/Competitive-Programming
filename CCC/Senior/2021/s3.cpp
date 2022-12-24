#include <bits/stdc++.h>

using namespace std;

struct Friend {
    int position;
    int walkSpeed;
    int hearingDistance;
};

bool operator<(const Friend& a, const Friend& b) {
    return a.position < b.position;
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    freopen("3.input", "r", stdin); // for testing
    
    int numFriends;
    cin >> numFriends;

    set<Friend> friends;
    for (int i = 0; i < numFriends; i++) {
        int position, walkSpeed, hearingDistance;
        cin >> position >> walkSpeed >> hearingDistance;
        friends.insert({position, walkSpeed, hearingDistance});
    }

    int minTime = INT_MAX;
    for (int i = friends.begin()->position; i <= friends.rbegin()->position; i++) {
        int currTime = 0;
        for (auto it : friends) {
            int dist = abs(it.position - i);
            if (dist > it.hearingDistance) {
                currTime += (dist - it.hearingDistance) * it.walkSpeed;
            }
        }

        minTime = min(minTime, currTime);
    }

    cout << minTime << endl;

    return 0;
}