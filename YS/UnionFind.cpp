// https://judge.yosupo.jp/problem/unionfind

#include <bits/stdc++.h>

using namespace std;

vector<int> ds(200004);
vector<int> heights(200004, 1); //heights for ds

int find(int v) { // finds the representative
    while(ds[v] != v) {
        v = ds[v];
    }

    return v;
}

bool same(int v1, int v2) { // checks if two representatives are the same
    return find(v1) == find(v2);
}

void setunion(int v1, int v2) {
    int v1rep, v2rep;
    v1rep = find(v1);
    v2rep = find(v2);

    if (v1rep != v2rep) {
        // we want to skip this because this will add a height when joining itself
        if (v1rep < v2rep) {
            swap(v1rep, v2rep);
        }
        ds[v2rep] = v1rep;

        if (heights[v1rep] == heights[v2rep]) {
            heights[v1rep]++;
        }
    }
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    // freopen("UnionFind.input", "r", stdin); // For testing. Comment out for submissions

    int verticiesNum; cin >> verticiesNum;
    int queryNum; cin >> queryNum;

    // init ds
    for (int i = 0; i < 200004; i++) {
        ds[i] = i;
    }

    for (int i = 0; i < queryNum; i++) {
        int queryType; cin >> queryType; // 1 = union, 2 = same

        int v1; cin >> v1; int v2; cin >> v2;

        if (queryType) {
            if (same(v1, v2)) {
                cout << 1 << endl;
            } else {
                cout << 0 << endl;
            }
        } else{
            setunion(v1, v2);
        }
    }

    return 0;
}