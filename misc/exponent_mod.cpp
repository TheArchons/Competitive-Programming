#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll powerRemainder(ll base, ll exp, ll modVal) {
    if (!exp) {
        return 1;
    }

    ll halfExp = powerRemainder(base, exp / 2, modVal) % modVal;
    if (exp % 2) { // odd
        return halfExp * halfExp * base % modVal;
    } else {
        return halfExp * halfExp % modVal;
    }
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);

    ll base; cin >> base;
    ll exp; cin >> exp;
    ll modVal; cin >> modVal;
    
    cout << powerRemainder(base, exp, modVal) << endl;

    return 0;
}