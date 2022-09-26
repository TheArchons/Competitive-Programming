#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;

int arrayPairSearch(pair<int, int> arr[], int target, int arrLen) {
    for (int i = 0; i < arrLen; i++) {
        if (arr[i].first == target) {
            return i;
        }
    }
    return -1;
}

int main() {
    int countries, groups, k;
    scanf("%d %d", &countries, &groups);
    int countryPerGroup = countries / groups;
    pair<int, int> countryGroups[countryPerGroup][groups];
    unordered_map<int, int> countryMap; //country, group
    for (int i = 0; i < countries/groups; i++) {
        for (int j = 0; j < groups; j++) {
            int country;
            scanf("%d", &country);
            countryGroups[i][j].first = country;
            countryMap[country] = i;
        }
    }
    for (int i = 0; i < ((groups-1)*countries)/2; i++) {
        int country1, country2;
        char result;
        scanf("%d %d %c", &country1, &country2, &result);
        if (result == 'W') {
            countryGroups[countryMap[country1]][arrayPairSearch(countryGroups[countryMap[country1]], country1, groups)].second += 3;
        }
        else if(result == 'L') {
            countryGroups[countryMap[country2]][arrayPairSearch(countryGroups[countryMap[country2]], country2, groups)].second += 3;
        }
        else {
            countryGroups[countryMap[country1]][arrayPairSearch(countryGroups[countryMap[country1]], country1, groups)].second += 1;
            countryGroups[countryMap[country2]][arrayPairSearch(countryGroups[countryMap[country2]], country2, groups)].second += 1;
        }

    }
    scanf("%d", &k);
    for (int i = 0; i < countryPerGroup; i++) {
        //find kth largest in each group
        sort(countryGroups[i], countryGroups[i] + groups, [](pair<int, int> a, pair<int, int> b) {
            return a.second > b.second;
        });
        int smallest = countryGroups[i][k-1].first;
        while(countryGroups[i][k-1].second == countryGroups[i][k].second) {
            if (countryGroups[i][k-1].first < smallest) {
                smallest = countryGroups[i][k-1].first;
            }
            if (countryGroups[i][k].first < smallest) {
                smallest = countryGroups[i][k].first;
            }
            k++;
        }
        if (countryPerGroup-1 == i) {
            printf("%d\n", smallest);
        }
        else {
            printf("%d ", smallest);
        }
    }
    return 0;
}