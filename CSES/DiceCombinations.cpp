// https://cses.fi/problemset/task/1633

#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    //freopen("DiceCombinations.input", "r", stdin); // for testing
    
    int n;
    cin >> n;

    vector<long long int> dp(n+1);
    dp[0] = 1;

    for (int i = 0; i <= n; i++) {
        for (int j = 1; j <= 6; j++) {
            dp[i] += i-j >= 0 ? dp[i-j] : 0;
        }

        dp[i] %= 1000000007;
    }

    cout << dp[n];
}