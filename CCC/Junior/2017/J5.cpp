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

pair<int, int> findMax(int nums[100000], int length, int repeatingNums[100000], int repeatingNumLen) {
    int maxVal, maxesCount, currIndex;
    maxVal = maxesCount = currIndex = 0;
    unordered_map<int, int> maxes;
    bool usedNums[20000][4000];
    for (int i = 0; i < length; i++) {
        unordered_set<int> numsUsed; // set of numbers used
        int currI = nums[i];
        for(int j = 0; j < length; j++) {
            int currVal = nums[j];
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
    for(int i = 0; i < repeatingNumLen; i++) {
        if (repeatingNums[i] > 1) {
            for (int j = 0; j < repeatingNumLen; j++) {
                if (i == j || repeatingNums[j] <= 1) {
                    continue;
                }
                int comboVal = i+j;
                int minVal = min(repeatingNums[i], repeatingNums[j]);
                maxes[comboVal] += minVal-1;
                if (maxes[comboVal] > maxVal) {
                    maxVal = maxes[comboVal];
                    maxesCount = 1;
                } else if (maxes[comboVal] == maxVal) {
                    maxesCount++;
                }
            }
        }
    }
    return make_pair(maxVal, maxesCount);
}

int main() {
    int index = 0;
    int numsIndex = 0;
    int repeatingNumLen = 0;
    char c, cs[7];
    int length;
    do {
        c = getchar();
        cs[index] = c;
        index++;
    } while (c != '\n');
    //charString to int
    length = atoi(cs);
    int nums[100000] = {0};
    bool moreThan1Uniques = false;
    //split input by spaces into nums with getchar
    index = 0;
    char input[10];
    c = getchar();
    if(c == '\n') {
        putchar('a');
    }
    int repeatingNums[100000] = {0};
    while (c != '\n') {
        if (c == ' ') {
            int intPut = atoi(input);
            if (repeatingNums[intPut] != 0) {
                repeatingNums[intPut]++;
                c = getchar();
                continue;
            }
            repeatingNums[intPut] = 1;
            repeatingNumLen++;
            nums[numsIndex] = intPut;
            memset(input, 0, sizeof input);
            index = 0;
            if (nums[numsIndex] != nums[0]) {
                moreThan1Uniques = true;
            }
            numsIndex++;
        }
        input[index] = c;
        index++;
        c = getchar();

    }
    nums[numsIndex] = atoi(input);
    if (nums[numsIndex] != nums[0]) {
        moreThan1Uniques = true;
    }
    if (!moreThan1Uniques) {
        printf("%d %d\n", length/2, 1);
        return 0;
    }
    pair<int, int> max = findMax(nums, length, repeatingNums, repeatingNumLen);
    printf("%d %d", max.first, max.second);
    return 0;
}