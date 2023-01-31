#include <bits/stdc++.h>

using namespace std;

int maxValue = 0;
int maxWeight;
set<vector<pair<int, int>>> seen;

void recurse(vector<pair<int, int>> items, int currWeight, int currValue) {
    if (currWeight > maxWeight || seen.find(items) != seen.end()) {
        return;
    }

    seen.insert(items);

    maxValue = max(maxValue, currValue);

    for (int i = 0; i < items.size(); i++) {
        pair<int, int> item = items[i];
        items.erase(items.begin() + i);
        recurse(items, currWeight + item.first, currValue + item.second);
        items.insert(items.begin() + i, item);
    }
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    //freopen("e.input", "r", stdin); // for testing

    int itemNum;
    cin >> itemNum >> maxWeight;

    vector<pair<int, int>> items(itemNum);

    for (int i = 0; i < itemNum; i++) {
        cin >> items[i].first >> items[i].second;
    }

    recurse(items, 0, 0);

    cout << maxValue << endl;

    return 0;
}