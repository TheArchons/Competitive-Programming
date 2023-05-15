#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<ll> cows;

ll findInsPos(ll val) {
    ll l = 0; ll r = cows.size() - 1;

    while (l <= r) {
        ll mid = (l + r) / 2;

        if (cows[mid] == val) {
            return mid;
        } else if (cows[mid] < val) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }

    return l;
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    // freopen("1.input", "r", stdin); // For testing. Comment out for submissions

    ll cowNum; cin >> cowNum;
    cows.resize(cowNum);
    
    for (ll i = 0; i < cowNum; i++) {
        cin >> cows[i];
    }

    vector<ll> unsortedCows = cows;

    sort(cows.begin(), cows.end());

    vector<ll> cowPrefixSum(cowNum + 1);
    
    cowPrefixSum[0] = 0;
    ll total = 0;
    unordered_map<ll, ll> cowPos;

    for (ll i = 1; i <= cowNum; i++) {
        cowPrefixSum[i] = cowPrefixSum[i - 1] + cows[i - 1];
        total += cows[i - 1] * (i);
        cowPos[cows[i - 1]] = i - 1;
    }

    ll queries; cin >> queries;

    while (queries--) {
        ll unsortedPos; cin >> unsortedPos; ll newValue; cin >> newValue;

        ll curr = total;
        
        ll oldVal = unsortedCows[unsortedPos - 1];
        ll newPos = findInsPos(newValue);
        ll pos = cowPos[oldVal];

        // in between pos and newPos
        if (newPos > pos) {
            curr -= cowPrefixSum[newPos] - cowPrefixSum[pos + 1];
            curr += newPos * newValue;
        } else if (newPos < pos) {
            curr += cowPrefixSum[pos] - cowPrefixSum[newPos];
            curr += (newPos + 1) * newValue;
        } else {
            curr += (newPos + 1) * newValue;
        }

        curr -= (pos + 1) * oldVal;

        cout << curr << endl;
    }

    return 0;
}