#include <iostream>
#include <unordered_map>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int sensors;
    scanf("%d", &sensors);
    int maxFreq, secondMaxFreq, maxFreqInt, secondMaxFreqInt, secondMaxFreqMin;
    maxFreq = secondMaxFreq = 0;
    secondMaxFreqInt = secondMaxFreqMin = 1001;
    unordered_map<int, int> freqMap;
    int uniques = 0;
    for (int i = 0; i < sensors; i++) {
        int n;
        scanf("%d", &n);
        if (freqMap[n] == 0) {
            uniques++;
        }
        freqMap[n]++;
    }

    //move freqMap to vector
    vector<pair<int, int>> freqVec;
    for (auto it = freqMap.begin(); it != freqMap.end(); it++) {
        freqVec.push_back(*it);
    }

    //sort freqVec by freq
    /*sort(freqVec.begin(), freqVec.end(), [](pair<int, int> a, pair<int, int> b) {
        return a.second > b.second;
    });*/

    //sort by freq, then by value
    sort(freqVec.begin(), freqVec.end(), [](pair<int, int> a, pair<int, int> b) {
        if (a.second == b.second) {
            return a.first > b.first;
        }
        return a.second > b.second;
    });
    int first = freqVec[0].first;
    int secondFreq = freqVec[1].second;
    int maxDiff = 0;
    for (int i = 1; i < freqVec.size(); i++) {
        if (freqVec[i].second == secondFreq) {
            maxDiff = max(maxDiff, abs(freqVec[i].first - first));
        }
        else {
            break;
        }
    }
    printf("%d\n", maxDiff);
    return 0;
}