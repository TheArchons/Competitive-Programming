#include <bits/stdc++.h>

using namespace std;

int circumference = pow(10, 6);

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    //freopen("3.input", "r", stdin); // For testing. Comment out for submissions

    int houseNum; cin >> houseNum;

    vector<int> houses(houseNum);

    for (int i = 0; i < houseNum; i++) {
        cin >> houses[i];
    }

    sort(houses.begin(), houses.end());

    int maxDist = (houses[0] + circumference) - houses[houseNum - 1];
    int maxDistPos = 0;

    for (int i = 1; i < houseNum; i++) {
        if (maxDist < houses[i] - houses[i - 1]) {
            maxDist = houses[i] - houses[i - 1];
            maxDistPos = i;
        }
    }

    vector<int> shiftedHouses(houseNum);

    if (maxDistPos != 0) {
        for (int i = 0; i < maxDistPos; i++) {
            shiftedHouses[i] = houses[i + maxDistPos];
        }

        for (int i = maxDistPos; i < houseNum; i++) {
            shiftedHouses[i] = houses[i - maxDistPos] + circumference;
        }
    } else {
        shiftedHouses = houses;
    }


    int left = 0;
    int right = circumference;

    int hoseNum; cin >> hoseNum;

    while (left <= right) {
        int mid = (left + right) / 2;

        bool works = true;
        int usedHoses = 1;

        int maxPos = shiftedHouses[0] + mid*2;

        for (int i = 1; i < houseNum; i++) {
            if (shiftedHouses[i] > maxPos) {
                usedHoses++;
                maxPos = shiftedHouses[i] + mid*2;
            }
        }

        if (usedHoses > hoseNum) {
            works = false;
        }

        if (works) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    cout << left << endl;

    return 0;
}