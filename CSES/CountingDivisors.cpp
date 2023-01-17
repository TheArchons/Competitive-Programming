// https://cses.fi/problemset/task/1713

#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    //freopen("CountingDivisors.input", "r", stdin); // for testing
    
    int queries;
    cin >> queries;

    while (queries--) {
        int divNum, num;
        cin >> num;

        divNum = 0;

        for (int i = 1; i <= sqrt(num); i++) {
            if (!(num % i)) {
                if (num / i == i) {
                    divNum++;
                } else {
                    divNum += 2;
                }
            }
        }

        cout << divNum << "\n";
    }
}