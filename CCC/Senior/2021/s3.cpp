#include <bits/stdc++.h>

#define lld long long int

using namespace std;

struct Friend {
    int position, walkSpeed, hearDist;
};

bool operator<(const Friend& a, const Friend& b) {
    return a.position < b.position;
}

lld max(lld a, lld b) {
    return a > b ? a : b;
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    freopen("3.input", "r", stdin); // for testing
    
    int friendNum;
    cin >> friendNum;

    int minFriend, maxFriend;
    minFriend = INT_MAX;
    maxFriend = 0;
    set<Friend> friends;

    for (int i = 0; i < friendNum; i++) {
        Friend temp;
        cin >> temp.position >> temp.walkSpeed >> temp.hearDist;
        friends.insert(temp);

        minFriend = min(minFriend, temp.position);
        maxFriend = max(maxFriend, temp.position);
    }

    if (!friendNum) {
        cout << 0 << endl;
        return 0;
    }

    lld minTime = 0;
    // calculate minTime from the middle
    for (auto it = friends.begin(); it != friends.end(); it++) {
        minTime += max((abs(it->position - (minFriend + maxFriend)/2) - it->hearDist), 0) * it->walkSpeed;
    }

    int left, right;
    left = minFriend;
    right = maxFriend;
    while (left < right) {
        lld mid = left + ((right - left) / 2);
        lld leftTime, rightTime, leftNum;
        leftTime = rightTime = leftNum = 0;

        for (auto it = friends.begin(); it->position < mid; it++) {
            leftTime += max((mid - it->position - it->hearDist), 0) * it->walkSpeed;
            leftNum++;
        }

        for (auto it = next(friends.begin(), leftNum); it != friends.end(); it++) {
            rightTime += max((it->position - mid - it->hearDist), 0)* it->walkSpeed;
        }

        if (leftTime > rightTime) {
            right = mid;
        } else {
            left = mid + 1;
        }

        minTime = min(minTime, leftTime + rightTime);
    }

    cout << minTime << endl;

    return 0;
}