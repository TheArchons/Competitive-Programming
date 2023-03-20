#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct Friend {
    ll muffinNum;
    ll cookieNum;
    ll maxTime;
};

vector<Friend> friends;
ll friendNum;
ll cookieTime;
ll muffinTime;

bool check(ll money) {
    ll greater = max(0LL, money - muffinTime + 1); ll less = min(money, cookieTime - 1);

    for (ll i = 0; i < friendNum; i++) {
        Friend cf = friends[i];
        ll currCookieTime, currMuffinTime;

        if (cf.cookieNum == cf.muffinNum) {
            if (cookieTime <= money) {
                currCookieTime = 1;
                currMuffinTime = muffinTime - (money - (cookieTime - 1));
            } else {
                currCookieTime = cookieTime - money;
                currMuffinTime = muffinTime;
            }

            // if possible
            if (cf.cookieNum*currCookieTime + cf.muffinNum*currMuffinTime <= cf.maxTime) {
                continue;
            } else {
                return false;
            }
        } else if (cf.cookieNum > cf.muffinNum) {
            ll currGreater = ceil(((double)((cookieTime * cf.cookieNum + muffinTime * cf.muffinNum - cf.maxTime) - money*cf.muffinNum ))/(cf.cookieNum - cf.muffinNum));
            greater = max(greater, currGreater);
        } else {
            ll currLess = floor(((double)((cookieTime * cf.cookieNum + muffinTime * cf.muffinNum - cf.maxTime) - money*cf.muffinNum ))/(cf.cookieNum - cf.muffinNum));
            less = min(less, currLess);
        }
    }

    return greater <= less;
}

void solve() {
    cin >> friendNum;
    cin >> cookieTime;
    cin >> muffinTime;

    friends.resize(friendNum);

    for (ll i = 0; i < friendNum; i++) {
        cin >> friends[i].cookieNum >> friends[i].muffinNum >> friends[i].maxTime;
    }

    // binsearch for optimal money spending

    ll left = 0;
    ll right = cookieTime + muffinTime - 2;
    while (left < right) {
        ll mid = (left + right) / 2;
        
        if (check(mid)) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }

    cout << left << endl;
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    // freopen("1.input", "r", stdin); // For testing. Comment out for submissions

    ll testCases; cin >> testCases;

    while (testCases--) {
        solve();
    }

    return 0;
}