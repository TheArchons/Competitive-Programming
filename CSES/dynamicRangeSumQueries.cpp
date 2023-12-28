#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
ll ll_MAX = LONG_LONG_MAX;

vector<ll> valueSegTree(8*pow(10, 5) + 5, -1);
vector<ll> values(2*pow(10, 5) + 5);

void buildSeg(ll vertex, ll left, ll right) {
    if (left == right) {
        valueSegTree[vertex] = values[left];
        return;
    }

    ll mid = (right + left) / 2;
    buildSeg(2*vertex, left, mid);
    buildSeg(2*vertex+1, mid + 1, right);
    valueSegTree[vertex] = valueSegTree[2*vertex] + valueSegTree[2*vertex+1];
}

void update(ll vertex, ll left, ll right, ll find, ll newVal) {
    if (left == right) {
        valueSegTree[vertex] = newVal;
        return;
    }

    ll mid = (left + right)/2;
    if (find > mid) {
        update(2*vertex + 1, mid + 1, right, find, newVal);
    } else {
        update(2*vertex, left, mid, find, newVal);
    }

    valueSegTree[vertex] = valueSegTree[2*vertex] + valueSegTree[2*vertex + 1];
}

ll sum(ll vertex, ll left, ll right, ll find_left, ll find_right) {
    if (find_left > find_right) {
        return 0;
    }

    if (find_left == left && find_right == right) {
        return valueSegTree[vertex];
    }

    ll mid = (left + right)/2;
    return sum(vertex*2, left, mid, find_left, min(find_right, mid)) + sum(vertex*2+1, mid + 1, right, max(find_left, mid + 1), find_right);
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    // freopen("dynamicRangeSumQueries.input", "r", stdin); // For testing. Comment out for submissions

    ll valueNum; cin >> valueNum;
    ll queryNum; cin >> queryNum;

    

    for (ll i = 1; i <= valueNum; i++) {
        ll value; cin >> value;
        
        values[i] = value;
    }

    buildSeg(1, 1, valueNum);

    for (ll i = 0; i < queryNum; i++) {
        ll type; cin >> type;
        ll a; cin >> a;
        ll b; cin >> b;

        if (type == 2) {
            // find sum
            cout << sum(1, 1, valueNum, a, b) << endl;
        } else {
            update(1, 1, valueNum, a, b);
        }
    }

    return 0;
}
