#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct Friend {
    ll muffinNum;
    ll cookieNum;
    ll maxTime;
};

void solve() {
    ll friendNum; cin >> friendNum;
    ll cookieTime; cin >> cookieTime;
    ll muffinTime; cin >> muffinTime;

    vector<Friend> friends(friendNum);

    for (ll i = 0; i < friendNum; i++) {
        cin >> friends[i].cookieNum >> friends[i].muffinNum >> friends[i].maxTime;
    }

    ll minSpending = INT_MAX;

    for (ll i = 0; i <= cookieTime; i++) {
        for (ll j = 0; j <= muffinTime; j++) {
            // check if possible
            bool possible = true;
            for (ll k = 0; k < friendNum; k++) {
                if (cookieTime - i <= 0 || muffinTime - j <= 0 || (friends[k].cookieNum * (cookieTime - i)) + (friends[k].muffinNum * (muffinTime - j)) > friends[k].maxTime) {
                    possible = false;
                    break;
                }
            }

            if (possible) {
                minSpending = min(minSpending, i + j);
            }
        }
    }

    cout << minSpending << endl;
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    //freopen("1.input", "r", stdin); // For testing. Comment out for submissions

    ll testCases; cin >> testCases;

    while (testCases--) {
        solve();
    }

    return 0;
}