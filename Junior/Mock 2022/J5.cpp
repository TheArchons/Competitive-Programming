#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

int main() {
    int restrictions, resolutions;
    scanf("%d %d", &resolutions, &restrictions);
    unordered_map<int, int> appears;
    unordered_set<int> ignore;
    vector<pair<int, int>> res;
    //take in restrictions
    for (int i = 0; i < restrictions; i++) {
        int r1, r2;
        scanf("%d %d", &r1, &r2);
        res.push_back(make_pair(r1, r2));
    }
    int max;
    while (max != -1) {
        vector<int> addedAppears;
        //add restrictions to appears
        for (pair<int, int> i : res) {
            if (ignore.find(i.first) == ignore.end() && ignore.find(i.second) == ignore.end()) {
                appears[i.first]++;
                appears[i.second]++;
                addedAppears.push_back(i.first);
                addedAppears.push_back(i.second);
            }
        }
        //add max appears to ignore
        max = -1;
        for (int i : addedAppears) {
            if (appears[i] > max) {
                max = i;
            }
        }
        if (max == -1) {
            break;
        }
        ignore.insert(max);
        resolutions--;
    }
    printf("%d\n", resolutions);
}