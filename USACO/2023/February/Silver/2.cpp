#include <bits/stdc++.h>

using namespace std;

typedef long double ll;

struct CowLocation {
    ll x;
    ll y;
    ll time;
};

struct CowLocationCompare {
    bool operator() (const CowLocation& lhs, const CowLocation& rhs) const {
        return lhs.time < rhs.time;
    }
};

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    // freopen("2.input", "r", stdin); // For testing. Comment out for submissions

    ll grazeNum; cin >> grazeNum;
    ll cowNum; cin >> cowNum;

    multiset<CowLocation, CowLocationCompare> grazeTimes;

    for (ll i = 0; i < grazeNum; i++) {
        ll x; cin >> x;
        ll y; cin >> y;
        ll time; cin >> time;

        grazeTimes.insert({x, y, time});
    }

    ll innoCount = 0;

    for (ll i = 0; i < cowNum; i++) {
        ll x; cin >> x;
        ll y; cin >> y;
        ll time; cin >> time;

        CowLocation cow = {x, y, time};

        auto it = grazeTimes.lower_bound(cow);

        if (it != grazeTimes.end()) {
            CowLocation graze = *it;

            if (graze.time == cow.time) {
                if (graze.x != cow.x || graze.y != cow.y) {
                    innoCount++;
                }

                continue;
            }

            // ll dist = abs(graze.x - cow.x) + abs(graze.y - cow.y);


            // TODO check for diagonal dist
            ll dist = ceil((long double)sqrt(pow(graze.x - cow.x, 2) + pow(graze.y - cow.y, 2)));

            if (dist > graze.time - cow.time) {
                innoCount++;

                continue;
            }
        }

        if (it != grazeTimes.begin()) {
            it--;
            CowLocation graze = *it;

            // ll dist = abs(graze.x - cow.x) + abs(graze.y - cow.y);

            // TODO check for diagonal dist
            ll dist = ceil((long double)sqrt(pow(graze.x - cow.x, 2) + pow(graze.y - cow.y, 2)));

            if (dist > cow.time - graze.time) {
                innoCount++;

                continue;
            }
        }
    }

    cout << innoCount << endl;

    return 0;
}