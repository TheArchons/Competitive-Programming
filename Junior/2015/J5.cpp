#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

void printVec(vector<int> vec){
    for(int i:vec){
        cout << i << " ";
    }
    cout << endl;
}

int main() {
    int pieCount, peopleCount;
    scanf("%d\n%d", &pieCount, &peopleCount);
    int base = pieCount - peopleCount + 1;
    int total = 0;
    for (int ending = base; ending > 0; ending--) {
        //skip if base is too big
        if (ending == base) {
            total++;
            continue;
        }
        //create a vector ending with the current ending
        vector<int> distVec;
        for (int i = 0; i < peopleCount-1; i++) {
            distVec.push_back(1);
        }
        distVec.push_back(ending);
        //distribute extras
        int pos = peopleCount-2;
        for (int extras = base-ending; extras > 0; extras--) {
            if (pos < 0) {
                pos = peopleCount-2;
            }
            distVec[pos]++; pos--;
        }
        //check if valid
        if (distVec[peopleCount-1] < distVec[peopleCount-2]) {
            break;
        }
        total++;
        //atempt to distribute up
        for (int i = 0; i < peopleCount-2; i++) {
            if (distVec[i-1] < distVec[i] && distVec[i+1] < distVec[i+2] && distVec[i] > 1) {
                printVec(distVec);
                distVec[i]--;
                distVec[i+1]++;
                total++;
            }
        }
        printVec(distVec);
    }
    printf("%d\n", total);
    return 0;
}