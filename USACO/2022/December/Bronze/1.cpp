#include <bits/stdc++.h>

using namespace std;

int main() {
    int cows;
    scanf("%d", &cows);

    vector<int> cowTuitions;
    for (int i = 0; i < cows; i++) {
        int temp;
        scanf("%d", &temp);
        cowTuitions.push_back(temp);
    }

    sort(cowTuitions.begin(), cowTuitions.end());

    long long int cowNum, tuition, maxCowNum = 0, maxTuition = 0;
    cowNum = tuition = 0;

    for (int i = cows-1; i >= 0; i--) {
        cowNum++;
        tuition = cowTuitions[i];
        if (tuition * cowNum >= maxTuition * maxCowNum) {
            maxTuition = tuition;
            maxCowNum = cowNum;
        }
    }
    
    printf("%lld %lld", maxCowNum*maxTuition, maxTuition);
}

