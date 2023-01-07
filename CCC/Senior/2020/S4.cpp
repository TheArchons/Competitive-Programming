#include <bits/stdc++.h>

using namespace std;

/*
    Shift the start of the array through the array.
    For each start, find the minimum number of swaps to get the array in order.
    First save the number of out of place As, and Bs.
    The minimum number of swaps is abs(A - B).
    return the minimum number of swaps.
*/

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    //freopen("4.input", "r", stdin); // for testing
    
    string s;
    cin >> s;

    int stringLen = s.length();
    int minSwaps = INT_MAX;
    int As, Bs;
    As = 0;

    for (auto c : s) {
        if (c == 'A') As++;
    }

    for (int i = 0; i < stringLen; i++) {
        int a, b;
        a = b = 0;
        for (int j = 0; j < stringLen; j++) {\
            int currPos = (i + j) % stringLen;
            char curr = s[currPos];

            // if out of place
            if (curr == 'A' && j > As) a++;
            else if (curr == 'B' && j < As) b++;
        }

        minSwaps = min(minSwaps, abs(a - b) + min(a, b));
    }

    cout << minSwaps << endl;
}