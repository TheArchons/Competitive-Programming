#include <bits/stdc++.h>

using namespace std;

vector<int> mountains;
vector<int> mins;
int mountainNum;


void calcValue(int l, int r) {
    int val = 0;

    while (l >= 0 && r < mountainNum) {
        val += abs(mountains[l] - mountains[r]);
        mins[r - l] = min(mins[r - l], val);

        l--; r++;
    }

    return;
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    // freopen("2.input", "r", stdin); // For testing. Comment out for submissions

    cin >> mountainNum;

    mountains.resize(mountainNum);

    for (int i = 0; i < mountainNum; i++) {
        cin >> mountains[i];
    }

    mins.resize(mountainNum, INT_MAX);

    for (int i = 0; i < mountainNum; i++) {
        calcValue(i, i);
        if (i < mountainNum - 1) {
            calcValue(i, i + 1);
        }
    }

    for (int i = 0; i < mountainNum; i++) {
        cout << mins[i] << " ";
    }

    return 0;
}