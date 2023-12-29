#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
ll ll_MAX = LONG_LONG_MAX;

ll maxVal = 2 * pow(10, 5) + 1;
ll valueNum;

vector<ll> values(maxVal);
vector<ll> valBIT(maxVal, 0);

ll lsb(ll n) {
    return n & (-n);
}

void add(ll index, ll addVal) {
    if (index > valueNum) return;   

    valBIT[index] += addVal;
    add(index + lsb(index), addVal);
}

ll sum(ll index) {
    if (index < 1) return 0;

    return valBIT[index] + sum(index - lsb(index));
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    // freopen("dynamicRangeSumQueries_BIT.input", "r", stdin); // For testing. Comment out for submissions

    // binary indexed tree version
    
    cin >> valueNum;
    ll queryNum; cin >> queryNum;

    for (ll i = 1; i <= valueNum; i++) {
        ll value; cin >> value;

        values[i] = value;
        
        add(i, value);
    }

    for (ll i = 0; i < queryNum; i++) {
        ll type; cin >> type; type--;
        ll a; cin >> a;
        ll b; cin >> b;

        if (type) {
            cout << sum(b) - sum(a-1) << endl;
        } else {
            add(a, b - values[a]);
            values[a] = b;
        }
    }

    return 0;
}