#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    // freopen("J3.input", "r", stdin); // For testing. Comment out for submissions

    int n; cin >> n;

    vector<int> days(5);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 5; j++) {
            char c; cin >> c;

            if (c == 'Y') {
                days[j]++;
            }
        }
    }

    int max = 0;
    vector<int> maxes;

    for (int i = 0; i < 5; i++) {
        if (days[i] > max) {
            max = days[i];
            maxes.clear();
            maxes.push_back(i + 1);
        } else if (days[i] == max) {
            maxes.push_back(i + 1);
        }
    }

    for (int i = 0; i < maxes.size(); i++) {
        if (!i) {
            cout << maxes[i];
        } else {
            cout << "," << maxes[i];
        }
    }

    cout << endl;

    return 0;
}