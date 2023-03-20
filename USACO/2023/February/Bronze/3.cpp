#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    // freopen("3.input", "r", stdin); // For testing. Comment out for submissions

    int dayNum; cin >> dayNum; ll startPrice; cin >> startPrice;

    ll totalPrice = startPrice + 1;
    ll day; cin >> day;
    ll prevDay = day;

    for (int i = 1; i < dayNum; i++) {
        cin >> day;

        totalPrice += min(startPrice + 1, day - prevDay);

        prevDay = day;
    }

    cout << totalPrice << endl;

    return 0;
}