#include <bits/stdc++.h>

using namespace std;

int maxValueNum = 2 * pow(10, 5) + 5;

vector<int> values(maxValueNum);
vector<int> seg(maxValueNum * 4);

void buildSeg(int segPos, int l, int r) {
    if (l == r) {
        seg[segPos] = values[l];
        return;
    }

    int mid = (l + r)/2;

    buildSeg(2*segPos, l, mid);
    buildSeg(2*segPos + 1, mid + 1, r);

    seg[segPos] = min(seg[2*segPos], seg[2*segPos + 1]);

    return;
}

int findMin(int segPos, int l, int r, int findL, int findR) {
    if (findL > findR) return INT_MAX;
    if (l == findL && r == findR) {
        return seg[segPos];
    }

    int mid = (l + r)/2;

    return min(findMin(segPos*2, l, mid, findL, min(findR, mid)), findMin(segPos*2 + 1, mid + 1, r, max(findL, mid + 1), findR));
}

void update(int segPos, int l, int r, int find, int newVal) {
    if (l == r) {
        seg[segPos] = newVal;
        return;
    }

    int mid = (l + r)/2;
    
    if (find > mid) {
        // right child
        update(2*segPos + 1, mid + 1, r, find, newVal);
    } else {
        // left child
        update(2*segPos, l, mid, find, newVal);
    }

    seg[segPos] = min(seg[2*segPos], seg[2*segPos + 1]);
    return;
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    // freopen("dynamicRangeMinimumQueries.input", "r", stdin); // For testing. Comment out for submissions

    int valueNum; cin >> valueNum;
    int queryNum; cin >> queryNum;
    
    for (int i = 1; i <= valueNum; i++) {
        int value; cin >> value;

        values[i] = value;
    }

    buildSeg(1, 1, valueNum);

    for (int i = 0; i < queryNum; i++) {
        int type; cin >> type;
        int a; cin >> a;
        int b; cin >> b;

        if (type == 1) {
            update(1, 1, valueNum, a, b);
        } else {
            cout << findMin(1, 1, valueNum, a, b) << endl;
        }
    }
    return 0;
}