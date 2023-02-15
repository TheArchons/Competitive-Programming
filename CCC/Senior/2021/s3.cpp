#include <bits/stdc++.h>

using namespace std;

#define ll long long

struct Friend {
    ll position; // Pi
    ll secondsPerMeter; // Wi
    ll hearingRange; // Di
};

int friendNum;
vector<Friend> friends;

ll calcWalkTime(int mid) {
    ll walkTime = 0;

    for (auto currFriend : friends) {
        int dist = abs(mid - currFriend.position) - currFriend.hearingRange;

        if (dist > 0) {
            walkTime += dist * currFriend.secondsPerMeter;
        }
    }

    return walkTime;
}


int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    //freopen("3.input", "r", stdin); // For testing. Comment out for submissions

    cin >> friendNum;

    friends.resize(friendNum);

    for (int i = 0; i < friendNum; i++) {
        cin >> friends[i].position >> friends[i].secondsPerMeter >> friends[i].hearingRange;
    }

    int left = 0, right = pow(10, 9);

    ll midTime; ll midTime2;

    while (left < right) {
        int mid = (left + right) / 2;
        midTime = calcWalkTime(mid);
        midTime2 = calcWalkTime(mid + 1);

        if (midTime < midTime2) { // going up
            right = mid;
        } else { // going down
            left = mid + 1;
        }
    }

    cout << min(midTime, midTime2) << endl;

    return 0;
}