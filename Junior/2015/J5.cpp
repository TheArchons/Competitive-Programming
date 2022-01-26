#include <iostream>

using namespace std;

int main() {
    int pieCount, peopleCount;
    scanf("%d\n%d", &pieCount, &peopleCount);
    //array of pie distribution, the last one receiving all pies
    int pies[peopleCount] = {0};
    //set all people's pies to 1
    for (int i = 0; i < peopleCount; i++) {
        pies[i] = 1;
    }
    pies[peopleCount-1] += pieCount-peopleCount;
    //distribute the pies
    int distCount = 1;
    bool changed = true;
    while (changed) { //figure out loop stopping
        next:
        changed = false;
        for (int i = peopleCount-1; i > 0; i--) {
            for (int j = 0; j < peopleCount && pies[i-1] < pies[i]; j++) {
                if (i <= j) { //skip if we try to distribute up or to ourselves
                    continue;
                }
                //check for sharing validity
                bool invalid = false;
                 for (int z = j; z <= i; z++) {
                    if (z+1 >= sizeof(pies)/sizeof(pies[0])) continue;
                    if (pies[z] + 1 > pies[z+1]-1) {
                        //cout << "invalid" << endl;
                        invalid = true;
                        break;
                    }
                }
                if (invalid) {
                    continue;
                } 
                pies[j]++;
                pies[i]--;
                distCount++;
                changed = true;
                goto next;
            }
        }
    }
    printf("%d\n", distCount);
}