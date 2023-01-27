#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    freopen("2.input", "r", stdin); // for testing

    int cowNum, orderedCowNum, mandatoryCowLocationNum;
    cin >> cowNum >> orderedCowNum >> mandatoryCowLocationNum;

    vector<int> order(orderedCowNum);
    queue<int> cowQueue;
    bool found = false;
    for (int i = 0; i < orderedCowNum; i++) {
        cin >> order[i];
        if (!found) cowQueue.push(order[i]);
        if (order[i] == 1) {
            found = true;
        }
    }

    if (!found) {
        cowQueue = queue<int>();

        cowQueue.push(1);
    }

    map<int, int> mandatoryCowLocations;
    for (int i = 0; i < mandatoryCowLocationNum; i++) {
        int cow, location;
        cin >> cow >> location;
        if (cow == 1) {
            cout << location << endl;
            return 0;
        }
        mandatoryCowLocations[location] = cow;
    }

    return 0;
}