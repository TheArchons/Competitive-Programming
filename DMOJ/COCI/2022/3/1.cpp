#include <bits/stdc++.h>

using namespace std;

void output(bool isPossible) {
    if (isPossible) {
        cout << "DA" << endl;
    } else {
        cout << "NE" << endl;
    }
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    //freopen("1.input", "r", stdin); // for testing. Comment out for submissions

    int tableNum; cin >> tableNum; int chairColorNum; cin >> chairColorNum;

    if (tableNum < chairColorNum) {
        output(false);
        return 0;
    }

    int total = 0;

    for (int i = 0; i < chairColorNum; i++) {
        int currColor; cin >> currColor;
        if (currColor < 4) {
            output(false);
            return 0;
        }

        total += currColor/4;
    }

    output(total >= tableNum);

    return 0;
}