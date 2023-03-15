#include <bits/stdc++.h>

using namespace std;

typedef long double ll;

struct Friend {
    ll cookieNum;
    ll muffinNum;
    ll maxWait;
};

ll muffinTime;
ll cookieTime;
ll friendNum;
vector<Friend> friends;

void solve() {
    cin >> friendNum;
    cin >> cookieTime;
    cin >> muffinTime;

    friends.resize(friendNum);

    for (ll i = 0; i < friendNum; i++) {
        cin >> friends[i].cookieNum >> friends[i].muffinNum >> friends[i].maxWait;
    }

    ll start = 0; // TODO check if start = 1 or 0
    ll end = cookieTime;

    ll y, y1, y2;
    y = y1 = y2 = 0;

    while (true) {
        ll minZ = pow(10, 19);
        ll m = floor((start+end)/2);

        ll k;

        bool cont = false;

        for (ll i = 0; i < friendNum; i++) {
            Friend currFriend = friends[i];

            ll z = (double)(currFriend.maxWait - (currFriend.cookieNum * m))/currFriend.muffinNum;

            if (z < 0) { // TODO if start = 0 z < 0
                end = m - 1;
                y2 = 0;

                cont = true;
                break;
            }

            if (z < minZ) {
                minZ = min(z, muffinTime);

                k = currFriend.muffinNum - currFriend.cookieNum;
            }
        }

        if (cont) {
            continue;
        }

        minZ = floor(minZ);

        y = m + minZ;

        if (!k || start == m || end == m) {
            cout << fixed << setprecision(0) << floor(cookieTime + muffinTime - y) << "\n";

            return;
        }

        if (k < 0) {
            end = m;

            y2 = y;

            continue;
        }

        start = m;
        y1 = y;
    }

    return;
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    // freopen("1.input", "r", stdin); // For testing. Comment out for submissions

    ll caseNum; cin >> caseNum;

    while (caseNum--) {
        solve();
    }

    return 0;
}
