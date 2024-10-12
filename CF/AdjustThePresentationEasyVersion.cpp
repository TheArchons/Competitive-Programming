// https://codeforces.com/problemset/problem/2021/C1
#include <bits/stdc++.h>

using namespace std;

void solve() {
    int numMembers; cin >> numMembers;
    int numSlides; cin >> numSlides;
    int numUpdates; cin >> numUpdates;

    vector<int> members(numMembers);

    for (int i = 0; i < numMembers; i++) {
        int member; cin >> member;

        members[i] = member;
    }

    vector<int> slides(numSlides);

    for (int i = 0; i < numSlides; i++) {
        int slide; cin >> slide;

        slides[i] = slide;
    }

    set<int> prevMembers;
    int currMemberNum = 0;

    for (int i = 0; i < numSlides; i++) {
        int currSlide = slides[i];

        if (prevMembers.find(currSlide) != prevMembers.end()) {
            continue;
        }

        int currMember = members[currMemberNum];

        if (currMember == currSlide) {
            prevMembers.insert(currMember);

            currMemberNum++;
        } else {
            cout << "TIDAK" << endl;

            return;
        }
    }

    cout << "YA" << endl;

    return;
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    // freopen("AdjustThePresentationEasyVersion.input", "r", stdin); // For testing. Comment out for submissions

    int testCases; cin >> testCases;

    while (testCases--) {
        solve();
    }

    return 0;
}