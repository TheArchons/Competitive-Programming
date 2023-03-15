#include <bits/stdc++.h>

using namespace std;

struct CowLocation {
    int x;
    int y;
    int time;
};

struct CowLocationCompare {
    bool operator() (const CowLocation& lhs, const CowLocation& rhs) const {
        return lhs.time < rhs.time;
    }
};

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    freopen("2.input", "r", stdin); // For testing. Comment out for submissions

    int grazeNum; cin >> grazeNum;
    int cowNum; cin >> cowNum;

    set<CowLocation, CowLocationCompare> grazeTimes;

    for (int i = 0; i < grazeNum; i++) {
        int x; cin >> x;
        int y; cin >> y;
        int time; cin >> time;

        grazeTimes.insert({x, y, time});
    }

    int innoCount = 0;

    for (int i = 0; i < cowNum; i++) {
        int x; cin >> x;
        int y; cin >> y;
        int time; cin >> time;

        CowLocation cow = {x, y, time};

        auto it = grazeTimes.lower_bound(cow);

        if (it != grazeTimes.end()) {
            CowLocation graze = *it;

            if (graze.time == cow.time) {
                if (graze.x != cow.x || graze.y != cow.y) {
                    innoCount++;
                }

                continue;
            }

            int dist = abs(graze.x - cow.x) + abs(graze.y - cow.y);


            // TODO check for diagonal dist
            // int dist = sqrt(pow(graze.x - cow.x, 2) + pow(graze.y - cow.y, 2));

            if (dist > graze.time - cow.time) {
                innoCount++;

                continue;
            }
        }

        if (it != grazeTimes.begin()) {
            it--;
            CowLocation graze = *it;

            int dist = abs(graze.x - cow.x) + abs(graze.y - cow.y);

            // TODO check for diagonal dist
            // int dist = sqrt(pow(graze.x - cow.x, 2) + pow(graze.y - cow.y, 2));

            if (dist > cow.time - graze.time) {
                innoCount++;

                continue;
            }
        }
    }

    cout << innoCount << endl;

    return 0;
}