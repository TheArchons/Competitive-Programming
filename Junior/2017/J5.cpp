#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

//vectorSearch function
//returns true if the vector contains specified element
bool vectorSearch(vector<int> v, int element) {
    for (int i = 0; i < v.size(); i++) {
        if (v[i] == element) {
            return true;
        }
    }
    return false;
}

pair<int, int> findMax(vector<int> nums, int length) {
    int maxVal, maxesCount, currIndex;
    maxVal = maxesCount = currIndex = 0;
    unordered_map<int, int> maxes;
    unordered_map<int, vector<int>> numMap;
    for (int i = 0; i < length; i++) {
        vector<int> numClone = nums;
        unordered_set<int> numsUsed; // set of numbers used
        int currI = nums.at(i);
        for(int j = 0; !empty(numClone); j++) {
            int currVal = numClone.front();
            numClone.erase(numClone.begin());
            //if (j <= i || currI < currVal) {
            if (j <= i) {
                continue;
            }
            int comboVal = currVal + currI;
            if (vectorSearch(numMap[j], comboVal) || vectorSearch(numMap[i], comboVal)) {
                continue;
            }
            numMap[j].push_back(comboVal);
            numMap[i].push_back(comboVal);
            if (maxes.count(comboVal)) {
                maxes[comboVal]++;
            } else {
                maxes[comboVal] = 1;
            }
            if (maxes[comboVal] > maxVal) {
                maxVal = maxes[comboVal];
                maxesCount = 1;
            } else if (maxes[comboVal] == maxVal) {
                maxesCount++;
            }
        }
    }
    return make_pair(maxVal, maxesCount);
}

int main() {
    int length;
    string temp;
    getline(cin, temp);
    length = stoi(temp);
    vector<int> nums;
    getline(cin, temp);
    bool moreThan1Uniques = false;
    //split the string into a vector of ints by spaces
    for(int i = 0; i < temp.length(); i++) {
        if(temp[i] == ' ') {
            nums.push_back(stoi(temp.substr(0, i)));
            temp = temp.substr(i + 1);
            i = 0;
            if (nums.back() != nums.front()) {
                moreThan1Uniques = true;
            }
        }
    }
    //add the last number
    nums.push_back(stoi(temp));
    if (nums.back() != nums.front()) {
        moreThan1Uniques = true;
    }
    if (!moreThan1Uniques) {
        cout << length/2 << " " << 1;
        return 0;
    }
    pair<int, int> max = findMax(nums, length);
    cout << max.first << " " << max.second;
    return 0;
}