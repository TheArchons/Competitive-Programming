#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    //freopen("1.input", "r", stdin); // for testing

    int cases;
    cin >> cases;
    nextCase:while (cases--) {
        string start, end;
        cin >> start >> end;

        int sLen, eLen;
        sLen = start.length();
        eLen = end.length();
        int extra = 0;
        if (sLen != eLen) {
            cout << -1 << endl;
            goto nextCase;
        }

        if (start == end) {
            cout << 0 << endl;
            goto nextCase;
        }

        map<char, char> sToE;
        map<char, char> seenExtras;
        for (int i = 0; i < sLen; i++) {
            if (start[i] != end[i]) {
                if (sToE.find(start[i]) == sToE.end() || sToE[start[i]] == end[i]) {
                    sToE[start[i]] = end[i];
                } else {
                    cout << -1 << endl;
                    goto nextCase;
                }

                if (sToE.find(end[i]) != sToE.end() && sToE[end[i]] == start[i] && seenExtras.find(start[i]) == seenExtras.end()) {
                    extra++;
                    seenExtras[start[i]] = end[i];
                    seenExtras[end[i]] = start[i];
                }
            } else if (sToE.find(start[i]) != sToE.end()) {
                cout << -1 << endl;
                goto nextCase;
            }
        }

        cout << sToE.size() + extra << endl;
    }

    return 0;
}