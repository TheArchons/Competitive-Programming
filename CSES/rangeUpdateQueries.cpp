#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
ll ll_MAX = LONG_LONG_MAX;

ll maxValues = pow(10, 5) * 2 + 5;

vector<ll> valSeg(4 * maxValues, 0);

void update(ll vertex, ll l, ll r, ll findl, ll findr, ll newVal) {
    if (findl > findr) return;

    if (l == findl && r == findr) {
        valSeg[vertex] += newVal;
        return;
    }

    ll mid = (l + r)/2;
    update(vertex*2, l, mid, findl, min(findr, mid), newVal);
    update(vertex*2+1, mid + 1, r, max(findl, mid + 1), findr, newVal);
}

ll findIncrease(ll vertex, ll l, ll r, ll find) {
    // dfs basically
    if (l == r) {
        return valSeg[vertex];
    }

    ll mid = (l + r)/2;
    ll sum = valSeg[vertex];
    
    if (find > mid) {
        // right
        sum += findIncrease(vertex*2 + 1, mid + 1, r, find);
    } else {
        // left
        sum += findIncrease(vertex*2, l, mid, find);
    }

    return sum;
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    // freopen("rangeUpdateQueries.input", "r", stdin); // For testing. Comment out for submissions

    ll valNum; cin >> valNum;
    ll queryNum; cin >> queryNum;

    vector<ll> values(valNum);

    for (ll i = 1; i <= valNum; i++) {
        ll val; cin >> val;

        values[i] = val;
    }

    for (ll i = 0; i < queryNum; i++) {
        ll type; cin >> type; type--;

        if (type) {
            ll position; cin >> position;

            cout << values[position] + findIncrease(1, 1, valNum, position) << endl;
        } else {
            ll left; cin >> left;
            ll right; cin >> right;
            ll newVal; cin >> newVal;

            update(1, 1, valNum, left, right, newVal);
        }
    }

    return 0;
}