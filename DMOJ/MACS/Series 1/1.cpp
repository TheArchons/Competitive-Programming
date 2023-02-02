#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    //freopen("1.input", "r", stdin); // for testing. Comment out for submissions

    int maxHunger; cin >> maxHunger;
    int appleNum; cin >> appleNum;
    int waitSeconds; cin >> waitSeconds;

    cout << max(min(maxHunger, appleNum) - waitSeconds, 0) << endl;

    return 0;
}