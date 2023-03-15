#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct delivery {
    ll day;
    ll amount;
};

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    // freopen("1.input", "r", stdin); // For testing. Comment out for submissions

    ll deliveryNum; cin >> deliveryNum;
    ll dayNum; cin >> dayNum;

    vector<delivery> deliveries(deliveryNum + 1);

    for (ll i = 0; i < deliveryNum; i++) {
        cin >> deliveries[i].day >> deliveries[i].amount;
    }

    deliveries[deliveryNum].day = dayNum;
    deliveries[deliveryNum].amount = 0;

    ll total = 0; ll baleNum = 0; ll prevDay = 0;

    for (ll i = 0; i < deliveryNum + 1; i++) {
        delivery d = deliveries[i];
        ll eatNum = min(baleNum, d.day - prevDay);

        baleNum -= eatNum;
        total += eatNum;

        baleNum += d.amount;
        prevDay = d.day;
    }

    if (deliveries[deliveryNum].day == dayNum) {
        total += min(baleNum, (ll) 1);
    }

    cout << total << endl;

    return 0;
}