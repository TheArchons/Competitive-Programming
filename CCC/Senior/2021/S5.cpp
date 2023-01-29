#include <bits/stdc++.h>

using namespace std;

struct req {
    int start, end, gcd;
};

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    //freopen("5.input", "r", stdin); // for testing

    int arrayLen, reqNum;
    cin >> arrayLen >> reqNum;

    vector<int> array(arrayLen, 1);
    vector<req> reqs(reqNum);

    for (int i = 0; i < reqNum; i++) {
        cin >> reqs[i].start >> reqs[i].end >> reqs[i].gcd;

        // add if gcd == 2
        if (reqs[i].gcd == 2) {
            for (int j = reqs[i].start; j <= reqs[i].end; j++) {
                array[j - 1] = 2;
            }
        }

        
    }

    // check if valid
    for (int i = 0; i < reqNum; i++) {
        int currGcd = 0;
        for (int j = reqs[i].start; j <= reqs[i].end; j++) {
            currGcd = gcd(currGcd, array[j - 1]);
        }

        if (currGcd != reqs[i].gcd) {
            cout << "Impossible" << endl;
            return 0;
        }
    }

    for (int i = 0; i < arrayLen; i++) {
        cout << array[i] << " ";
    }

    return 0;
}