#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    //freopen("1.input", "r", stdin); // for testing
    freopen("sleepy.in", "r", stdin); freopen("sleepy.out", "w", stdout); // for submission
    
    int n;
    cin >> n;

    vector<int> cows(n + 1);
    cows[n] = 101;

    for (int i = 0; i < n; i++) {
        cin >> cows[i];
    }

    int out = n;
    for (int i = n - 1; cows[i] < cows[i+1]; i--) {
        out--;
    }

    cout << out << endl;

    return 0;
}