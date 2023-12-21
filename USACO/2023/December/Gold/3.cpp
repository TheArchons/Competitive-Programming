#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll maxNum = pow(10, 6)+5;

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    // freopen("3.input", "r", stdin); // For testing. Comment out for submissions

    // first compute l and r for each x
    // then parabola so binsearch
    vector<int> barns(maxNum, 0);
    
    ll barnNum; cin >> barnNum;
    
    for (ll i = 0; i < barnNum; i++) {
        ll currBarn; cin >> currBarn;

        barns[currBarn]++;
    }

    vector<pair<ll, ll>> lr(maxNum);

    ll lNum, rNum;
    lNum = 0; rNum = barnNum;
    ll l, r;
    l = r = 0;

    for (ll i = 0; i < maxNum; i++) {
        r += i * barns[i];
    }

    if (barns[0]) {
        rNum -= barns[0];
        lNum += barns[0];
    }

    lr[0] = make_pair(l, r);

    for (ll i = 1; i < maxNum; i++) {

        l += lNum;
        r -= rNum;

        lr[i] = make_pair(l, r);

        rNum -= barns[i];
        lNum += barns[i];
    }

    // for each query, binsearch

    ll queryNum; cin >> queryNum;

    for (ll i = 0; i < queryNum; i++) {
        ll lCost; cin >> lCost;
        ll rCost; cin >> rCost;

        l = 0; r = maxNum;

        // cost calculation, find and output minimum cost
        // l*lr[i] + r*lr[i]

        while (l < r) {
            ll mid = (l+r)/2;

            ll cost = lCost*lr[mid].first + rCost*lr[mid].second;

            ll cost2 = lCost*lr[mid+1].first + rCost*lr[mid+1].second;

            if (cost < cost2) {
                r = mid;
            } else {
                l = mid+1;
            }
        }

        ll cost = lCost*lr[l].first + rCost*lr[l].second;
        cout << cost << "\n";
    }

    return 0;
}