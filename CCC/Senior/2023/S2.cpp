#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    //freopen("2.input", "r", stdin); // For testing. Comment out for submissions

    int mountainNum; cin >> mountainNum;

    vector<int> mountains(mountainNum);
    vector<int> prefixSum(mountainNum + 1);

    int total = 0;

    for (int i = 0; i < mountainNum; i++) {
        cin >> mountains[i];
        total += mountains[i];
        prefixSum[i + 1] = total;
    }

    for (int i = 0; i < mountainNum; i++) { // lengths
        int minVal = pow(10, 9);
        for (int left = 0; left < mountainNum - i; left++) {
            int right = left + i;
            if (mountainNum <= 300) {
                int tempL, tempR;
                tempL = left;
                tempR = right;
                int total = 0;

                while (tempL < tempR) {
                    total += abs(mountains[tempR] - mountains[tempL]);
                    tempL++;
                    tempR--;
                }

                minVal = min(minVal, total);
            } else {
                if (i == 0) {
                    minVal = 0;
                    continue;
                }
                int midPref = prefixSum[left + (i + 1) / 2];
                // sum of the left side before the middle
                int leftSum = midPref - prefixSum[left];
                // sum of the right side after the middle
                int a = left + (i + 1) / 2;
                if ((left - right) % 2 == 0) {
                    a++;
                }
                int rightSum = prefixSum[right + 1] - prefixSum[a];

                minVal = min(minVal, abs(leftSum - rightSum));
            }

        }
        cout << minVal << " ";
    }

    return 0;
}