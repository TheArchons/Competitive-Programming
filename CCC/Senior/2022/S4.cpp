#include <bits/stdc++.h>

using namespace std;

// subtask 1, brute force

int halfCircumference, circumference;

bool checkValid(multiset<int> points) {
    auto it = points.begin();
    int first, second, third;
    first = *it;
    it++;
    second = *it;
    it++;
    third = *it;

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

    multiset<int> points;
    for (int i = 0; i < pointNum; i++) {
        int point;
        cin >> point;
        points.insert(point);
    }

    int pointCount = 0;

    for (auto it = points.begin(); it != points.end(); it++) {
        for (auto it2 = it; it2 != points.end(); it2++) {
            for (auto it3 = it2; it3 != points.end(); it3++) {
                if (checkValid({*it, *it2, *it3})) {
                    pointCount++;
                }
            }
        }
    }

    cout << pointCount << endl;

    return 0;
}