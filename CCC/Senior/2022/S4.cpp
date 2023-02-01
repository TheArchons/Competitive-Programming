#include <bits/stdc++.h>

using namespace std;

// subtask 1 + 2

int halfCircumference, circumference;

bool checkValid(int first, int second, int third) {
    if (second - first < halfCircumference && third - second < halfCircumference && (first + circumference) - third < halfCircumference) {
        return true;
    }

    return false;
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    //freopen("4.input", "r", stdin); // for testing

    int pointNum;
    cin >> pointNum >> circumference;

    halfCircumference = (circumference + 1) / 2;

    vector<int> pointCount(circumference, 0);
    for (int i = 0; i < pointNum; i++) {
        int point;
        cin >> point;
        pointCount[point]++;
    }

    vector<int> pointCountPrefix(circumference, 0);
    int prefixSum = 0;
    for (int i = 0; i < circumference; i++) {
        prefixSum += pointCount[i];
        pointCountPrefix[i] = prefixSum;
    }

    int totalPoints = 0;

    for (int i = 0; i < halfCircumference; i++) {
        if (!pointCount[i]) continue;
        for (int j = i + 1; j < i + halfCircumference; j++) {
            if (!pointCount[j]) continue;
            // int tail = pointCountPrefix[(i + halfCircumference) % circumference];
            // int head = pointCountPrefix[(j + halfCircumference - 1) % circumference];
            int head, tail;
            if (i + halfCircumference < circumference) {
                tail = pointCountPrefix[i + halfCircumference];
            } else {
                tail = pointCountPrefix[circumference - 1];
            }

            if (j + halfCircumference - 1 < circumference) {
                head = pointCountPrefix[j + halfCircumference - 1];
            } else {
                head = pointCountPrefix[circumference - 1];
            }

            totalPoints += abs(head - tail) * pointCount[i] * pointCount[j];
        }
    }

    cout << totalPoints << endl;

    return 0;
}