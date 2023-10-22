#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    // freopen("a_2.input", "r", stdin); // For testing. Comment out for submissions

    int n; cin >> n;

    vector<int> costs(n);

    for (int i = 0; i < n; i++) {
        int h; cin >> h;

        costs[i] = h;
    }

    int prev, second_prev;

    prev = abs(costs[1] - costs[0]);
    second_prev = 0;

    for (int i = 2; i < n; i++) {
        int temp = second_prev;

        second_prev = prev;

        int o1, o2;
        
        o1 = second_prev + abs(costs[i] - costs[i - 1]);
        o2 = temp + abs(costs[i] - costs[i - 2]);

        prev = min(o1, o2);
    }

    cout << prev << endl;

    return 0;
}