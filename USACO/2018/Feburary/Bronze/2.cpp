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

    int left, right;
    left = 1;
    right = cowNum - 1;

    int ans = 1;
    // go from front to back
    while (left < right && cows[left + 1] - cows[left] <= cows[left] - cows[left - 1]) {
        left++;
    }

    if (left >= right) {
        cout << ans << endl;
        return 0;
    }

    // if the only way to reach the end is to start from there, start from there
    if (cows[cowNum - 2] - cows[cowNum - 3] <= cows[right] - cows[cowNum - 2]) {
        ans = 2;
        right--;
        while (left < right && cows[right] - cows[right - 1] < cows[right + 1] - cows[right]) {
            right--;
        }

        if (left >= right) {
            cout << ans << endl;
            return 0;
        }
    }

    // travel front to back until left >= right
    while (left < right) {
        ans++;
        left++;
        while (left < right && cows[left + 1] - cows[left] <= cows[left] - cows[left - 1]) {
            left++;
        }
    }

    cout << ans << endl;
    return 0;
}