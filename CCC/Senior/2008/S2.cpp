#include <bits/stdc++.h>

using namespace std;

int calcPoses(int radius, int i) {
    return 2*floor(sqrt(pow(radius, 2) - pow(i, 2))) + 1;
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    //freopen("2.input", "r", stdin); // for testing. Comment out for submissions    

    while (true) {
        int radius; cin >> radius;

        if (!radius) return 0;

        int total = 0;

        for (int i = 1; i <= radius; i++) {
            total += 2*calcPoses(radius, i);
        }

        total += calcPoses(radius, 0);

        cout << total << endl;
    }

    return 0;
}