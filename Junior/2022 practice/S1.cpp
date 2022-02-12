#include <iostream>
#include <queue>

using namespace std;

int main() {
    int games;
    scanf("%d", &games);
    queue<int> swifts;
    for (int i = 0; i < games; i++) {
        int n;
        scanf("%d", &n);
        swifts.push(n);
    }
    int k, swiftScore, semaScore;
    k = swiftScore = semaScore = 0;
    for (int i = 0; i < games; i++) {
        int n;
        scanf("%d", &n);
        swiftScore += swifts.front();
        swifts.pop();
        semaScore += n;
        if (swiftScore == semaScore) {
            k = i+1;
        }
    }
    printf("%d", k);
}