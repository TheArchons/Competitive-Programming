#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

string findS = "bessie";
ll findLen = findS.length();

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    // freopen("3.input", "r", stdin); // For testing. Comment out for submissions

    string s; getline(cin, s);

    ll sLen = s.length();

    map<char, set<ll>> charPos;

    for (ll i = 0; i < sLen; i++) {
        char curr = s[i];
        if (curr == 'b' || curr == 'e' || curr == 's' || curr == 'i') {
            charPos[curr].insert(i);
        }
    }

    ll l, r;
    l = r = -1;

    ll ans = 0;
    bool end = false;

    int prevR, prevL;
    prevR = prevL = -1;

    while (!end) {
        // travel right
        for (ll i = 0; i < findLen; i++) {
            char curr = findS[i];
            auto it = charPos[curr].upper_bound(r);
            if (it != charPos[curr].end()) {
                r = *it;
            } else {
                end = true;
                break;
            }
        }

        if (end) {
            break;
        }

        l = r + 1;

        // travel left
        for (ll i = findLen - 1; i >= 0; i--) {
            char curr = findS[i];
            auto it = charPos[curr].lower_bound(l);
            if (it != charPos[curr].begin()) {
                it--;
                l = *it;
            }
        }

        ans += (l + 1) * (sLen - r);

        if (l < prevR) {
            ans -= (l + 1) * ((sLen - prevR) + 1);
        }

        prevL = l;
        prevR = r;

        r = l + 1;
    }

    cout << fixed << ans << "\n";

    return 0;
}