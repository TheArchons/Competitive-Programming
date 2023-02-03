#include <bits/stdc++.h>

using namespace std;

int arrayLen;

vector<int> divide(vector<int> baseArray) {
    // if each array is one element, return it
    if (baseArray.size() == 1) {
        return baseArray;
    }

    int third = baseArray.size()/3;

    // split into 3 subarrays
    vector<vector<int>> subArrays(3);
    for (int i = 0; i < third; i++) {
        subArrays[0].push_back(baseArray[i]);
    }

    for (int i = third; i < third*2; i++) {
        subArrays[1].push_back(baseArray[i]);
    }

    for (int i = third*2; i < third*3; i++) {
        subArrays[2].push_back(baseArray[i]);
    }

    // recurse on each subarray
    for (int i = 0; i < 3; i++) {
        subArrays[i] = divide(subArrays[i]);
    }

    // merge subarrays
    vector<int> mergedArray;
    mergedArray.insert(mergedArray.end(), subArrays[2].begin(), subArrays[2].end());
    mergedArray.insert(mergedArray.end(), subArrays[0].begin(), subArrays[0].end());
    mergedArray.insert(mergedArray.end(), subArrays[1].begin(), subArrays[1].end());

    return mergedArray;
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    //freopen("3.input", "r", stdin); // for testing. Comment out for submissions

    cin >> arrayLen;

    vector<int> baseArray(arrayLen);

    for (int i = 0; i < arrayLen; i++) {
        cin >> baseArray[i];
    }

    vector<int> finalArray = divide(baseArray);

    for (int i = 0; i < arrayLen; i++) {
        cout << finalArray[i] << " ";
    }

    return 0;
}