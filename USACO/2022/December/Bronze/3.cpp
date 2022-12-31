#include <bits/stdc++.h>

using namespace std;

void lie(bool isLie) {
    if (isLie) {
        cout << "LIE" << endl;
    } else {
        cout << "OK" << endl;
    }
    return;
}

void solve() {
    int arrLen, arrs;
    cin >> arrLen >> arrs;

    map<vector<bool>, bool> arrsMap;
    for (int i = 0; i < arrs; i++) {
        vector<bool> arr;
        string s;
        cin >> s;

        for (char c : s) {
            arr.push_back(c == '1');
        }

        bool res;
        cin >> res;

        if (arrsMap.find(arr) != arrsMap.end() && arrsMap[arr] != res) {
            lie(true);
            // take in the rest of the input
            for (int j = i + 1; j < arrs; j++) {
                string s;
                cin >> s;
                bool res;
                cin >> res;
            }
            return;
        } else {
            arrsMap[arr] = res;
        }
    }

    while (true) {
        bool split = false;

        for (int i = 0; i < arrLen; i++) {
            // check if all 1s correspond to the same result for the current bit
            bool canSplit = true;
            bool found = false;
            bool res;
            for (auto it : arrsMap) {
                if (it.first[i]) {
                    res = it.second;
                    found = true;
                    break;
                }
            }

            if (found) {
                for (auto it : arrsMap) {
                    if (it.first[i] && it.second != res) {
                        canSplit = false;
                        break;
                    }
                }

                if (canSplit) {
                    split = true;
                    // remove all lines with arr[i] == 1
                    for (auto it = arrsMap.begin(); it != arrsMap.end(); ) {
                        if (it->first[i]) {
                            it = arrsMap.erase(it);
                        } else {
                            it++;
                        }
                    }
                }
            }
            
            // check if all 0s correspond to the same result for the current bit
            canSplit = true;
            found = false;

            for (auto it : arrsMap) {
                if (!it.first[i]) {
                    res = it.second;
                    found = true;
                    break;
                }
            }

            if (found) {
                for (auto it : arrsMap) {
                    if (!it.first[i] && it.second != res) {
                        canSplit = false;
                        break;
                    }
                }

                if (canSplit) {
                    split = true;
                    // remove all lines with arr[i] == 0
                    for (auto it = arrsMap.begin(); it != arrsMap.end(); ) {
                        if (!it->first[i]) {
                            it = arrsMap.erase(it);
                        } else {
                            it++;
                        }
                    }
                }
            }
        }

        if (!split || arrsMap.size() <= 1) {
            break;
        }
    }

    // if not all lines with different results were removed, then its a lie

    bool res = arrsMap.begin()->second;
    for (auto it : arrsMap) {
        if (it.second != res) {
            lie(true);
            return;
        }
    }

    lie(false);
    return;
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    freopen("3.input", "r", stdin); // for testing
    
    int testCases;
    cin >> testCases;

    while (testCases--) {
        solve();
    }
}
