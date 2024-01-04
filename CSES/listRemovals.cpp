#include <bits/stdc++.h>

using namespace std;

int maxIntNum = 2 * pow(10, 5) + 5;

vector<int> intList(maxIntNum);
vector<int> segList(4 * maxIntNum, 0);

void findUpdate(int vertex, int l, int r, int realL, int realR, int findVal) {
    // reals account for the removed values

    if (l == r) {
        cout << intList[l] << " ";
    } else {
        int next1 = 2*vertex;
        int next2 = 2*vertex + 1;
        int mid = (l + r)/2;
        int size = mid - l - segList[next1];
        int realMid = realL + size;

        if (findVal <= realMid) {
            // left
            findUpdate(next1, l, mid, realL, realMid, findVal);
        } else {
            // right
            findUpdate(next2, mid + 1, r, realMid + 1, realR, findVal);
        }
    }

    segList[vertex]++;
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    // freopen("listRemovals.input", "r", stdin); // For testing. Comment out for submissions

    int intNum; cin >> intNum;

    vector<int> removalList(intNum + 1);

    for (int i = 1; i <= intNum; i++) {
        int val; cin >> val;

        intList[i] = val;
    }

    for (int i = 1; i <= intNum; i++) {
        int remPos; cin >> remPos;

        findUpdate(1, 1, intNum, 1, intNum - segList[1], remPos);
    }

    return 0;
}