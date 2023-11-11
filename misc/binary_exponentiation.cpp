#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll power(ll x, ll y) {
    if (y == 0) return 1;

    ll halfPow = power(x, y / 2);
    if (y % 2) { // odd
        return halfPow * halfPow * x;
    } else{
        return halfPow * halfPow;
    }
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);

    ll x; cin >> x;
    ll y; cin >> y;

    cout << power(x, y) << endl;

    return 0;
}