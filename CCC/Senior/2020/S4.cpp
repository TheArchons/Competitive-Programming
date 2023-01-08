#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    //freopen("4.input", "r", stdin); // for testing
    
    string s;
    cin >> s;

    int stringLen = s.length();
    int minSwaps = INT_MAX;
    int As;
    As = 0;

    vector<int> prefix(stringLen + 1);
    prefix[0] = 0;
    int currA = 0;

    for (int i = 0; i < stringLen; i++) {
        if (s[i] == 'A') {
            As++; currA++;
        }

        prefix[i + 1] = currA;
    }

    for (int i = 0; i < stringLen; i++) {
        int a, b;
        if (i + As > stringLen) {
            a = (prefix[i] - prefix[(As + i) - stringLen]);
            b = As - ((prefix[stringLen] - prefix[i]) + (prefix[(i + As) - stringLen]));
        } else {
            a = (prefix[stringLen] - prefix[i + As]) + prefix[i];
            b = As - ((prefix[i + As] - prefix[i]));
        }

        minSwaps = min(minSwaps, abs(a - b) + min(a, b));
    }

    cout << minSwaps << endl;
}