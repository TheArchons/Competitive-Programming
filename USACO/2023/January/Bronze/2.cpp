#include <bits/stdc++.h>

using namespace std;

struct AC {
    int start, end, cooling, price;
};

int minPrice = 0;

set<set<AC>> visited;

bool operator<(const AC& a, const AC& b) {
    return a.price < b.price;
}

void recurse(set<AC> ACs, vector<int> reqCooling, int currPrice) {
    // check if all cows are cooled
    bool allCooled = true;
    for (int i = 0; i < reqCooling.size(); i++) {
        if (reqCooling[i] > 0) {
            allCooled = false;
            break;
        }
    }

    if (allCooled) {
        minPrice = min(minPrice, currPrice);
        return;
    }

    // try all ACs
    for (auto i = ACs.begin(); i != ACs.end(); i++) {
        AC currAC = *i;
        vector<int> newReqCooling = reqCooling;

        for (int j = currAC.start; j <= currAC.end; j++) {
            newReqCooling[j] = newReqCooling[j] - currAC.cooling;
        }

        set<AC> newACs;
        for (auto j = ACs.begin(); j != ACs.end(); j++) {
            if (j != i)
                newACs.insert(*j);
        }

        if (visited.find(newACs) != visited.end())
            continue;
        
        visited.insert(newACs);
        
        recurse(newACs, newReqCooling, currPrice + currAC.price);
    }

    return;
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    //freopen("2.input", "r", stdin); // for testing

    int cowNum, ACNum;
    cin >> cowNum >> ACNum;

    vector<int> reqCooling(101);

    for (int i = 0; i < cowNum; i++) {
        int start, end, cooling;
        cin >> start >> end >> cooling;

        // NOTE: TRY TO SEE IF END IS INCLUDED
        for (int j = start; j <= end; j++) {
            reqCooling[j] = max(reqCooling[j], cooling);
        }
    }

    set<AC> ACs;
    for (int i = 0; i < ACNum; i++) {
        int start, end, cooling, price;
        cin >> start >> end >> cooling >> price;

        ACs.insert({start, end, cooling, price});
        minPrice += price;
    }

    recurse(ACs, reqCooling, 0);

    cout << minPrice << endl;

    return 0;
}