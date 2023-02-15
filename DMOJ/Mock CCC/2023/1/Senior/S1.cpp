#include <bits/stdc++.h>

using namespace std;

int fibNum = 21;

vector<int> fibonaccis(fibNum);
set<int> compFibs;

void initFibs() {
    fibonaccis[0] = 0;
    fibonaccis[1] = 1;

    for (int i = 2; i < fibNum; i++) {
        fibonaccis[i] = fibonaccis[i - 1] + fibonaccis[i - 2];
    }
}

int maxCompFib = pow(10, 6);

void concatFibs(string first, string second) {
    if (first == "0" || first.length() + second.length() > 6) {
        return;
    }

    int curr = stoi(first + second);

    if (curr > maxCompFib || compFibs.find(curr) != compFibs.end()) {
        return;
    }

    compFibs.insert(curr);

    for (int i = 0; i < fibNum; i++) {
        concatFibs(to_string(curr), to_string(fibonaccis[i]));
        concatFibs(to_string(fibonaccis[i]), to_string(curr));
    }

    return;
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    //freopen("1.input", "r", stdin); // for testing. Comment out for submissions

    initFibs();

    for (int i = 0; i < fibNum; i++) {
        for (int j = 0; j < fibNum; j++) {
            concatFibs(to_string(fibonaccis[i]), to_string(fibonaccis[j]));
            concatFibs(to_string(fibonaccis[j]), to_string(fibonaccis[i]));
        }
    }

    int testCases; cin >> testCases;

    while (testCases--) {
        int curr; cin >> curr;

        if (compFibs.find(curr) != compFibs.end()) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}