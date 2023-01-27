#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    // freopen("2.input", "r", stdin); // for testing
    freopen("hoofball.in", "r", stdin); freopen("hoofball.out", "w", stdout); // for submission

    int cowNum;
    cin >> cowNum;

    vector<int> cows(cowNum);

    for (int i = 0; i < cowNum; i++) {
        cin >> cows[i];
    }
    
    if (cowNum == 1) {
        cout << 1 << endl;
        return 0;
    }

    sort(cows.begin(), cows.end());

    int ans = 0;
    bool wentLeft = false;

    for (int i = 1; i < cowNum; i++) {
        // if going left is more preferred, skip
        if (cows[i] - cows[i - 1] <= cows[i + 1] - cows[i]) {
            wentLeft = true;
            if (i == cowNum - 2)
                ans++;
                break;
            continue;
        } else {
            ans++;
            int pos = i;

            if (wentLeft) {
                // account for going left
                ans++;
                wentLeft = false;
            }

            while (cows[pos + 1] - cows[pos] <= cows[pos + 2] - cows[pos + 1]) {
                pos++;
                if (pos == cowNum - 1)
                    break;
            }

            i = pos - 1;
        }
    }

    cout << ans << endl;
    return 0;
}