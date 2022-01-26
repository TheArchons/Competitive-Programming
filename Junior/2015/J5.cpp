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
    next:
    for (int i = peopleCount-1; i > 0; i--) {
        for (int j = i-1; j >= 0; j--) {
            pies[i]--;
            pies[j]++;
            if (pies[i] >= pies[i-1] && pies[j] <= pies[j+1]) {
                distCount++;
                goto next;
            }
            else{
                pies[i]++;
                pies[j]--;
            }
        }
    }
    printf("%d\n", distCount);
}