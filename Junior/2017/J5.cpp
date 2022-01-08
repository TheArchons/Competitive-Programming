#include <cstring>
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
    bool usedNums[20000][4000];
    for (int i = 0; i < length; i++) {
        unordered_set<int> numsUsed; // set of numbers used
        int currI = nums.at(i);
        for(int j = 0; j < length; j++) {
            int currVal = nums.at(j);
            if (j <= i) {
                continue;
            }
            int comboVal = currVal + currI;
            if (usedNums[i][comboVal] || usedNums[j][comboVal]) {
                continue;
            }
            usedNums[i][comboVal] = usedNums[j][comboVal] = true;
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
    int index = 0;
    char c, cs[7];
    int length;
    do {
        c = getchar();
        cs[index] = c;
        index++;
    } while (c != '\n');
    //charString to int
    length = atoi(cs);
    vector<int> nums;
    nums.reserve(length);
    bool moreThan1Uniques = false;
    //split input by spaces into nums with getchar
    index = 0;
    char input[10];
    c = getchar();
    if(c == '\n') {
        putchar('a');
    }
    while (c != '\n') {
        if (c == ' ') {
            nums.push_back(atoi(input));
            memset(input, 0, sizeof input);
            index = 0;
            if (nums.back() != nums.front()) {
                moreThan1Uniques = true;
            }   
        }
        input[index] = c;
        index++;
        c = getchar();

    }
    nums.push_back(atoi(input));
    if (nums.back() != nums.front()) {
        moreThan1Uniques = true;
    }
    if (!moreThan1Uniques) {
        printf("%d %d\n", length/2, 1);
        return 0;
    }
    pair<int, int> max = findMax(nums, length);
    printf("%d %d", max.first, max.second);
    return 0;
}