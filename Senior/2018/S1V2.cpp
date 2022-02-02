#include <iostream>
#include <algorithm>
using namespace std;



int main() {
    int len;
    float min, prev, curr;
    prev = min = -1;
    scanf("%d", &len);
    int villages[len];
    for (int i = 0; i < len; i++) {
        int temp;
        scanf("%d", &temp);
        villages[i] = temp;
    }
    sort(villages, villages+len);
    for (int i = 0; i < len; i++) {
        if (prev == -1) {
            prev = -2;
            continue;
        }
        if (prev == -2) {
            curr = double((villages[i] - villages[i-1]))/2;
            //printf("%.1f ", curr);
            prev = curr;
            continue;
        }
        curr = double((villages[i] - villages[i-1]))/2;
        //printf("%.1f ", curr);
        if ((curr + prev < min || min == -1)) {
            min = curr + prev;
        }
        prev = curr;
    }
    printf("%.1f\n", min);
    return 0;
}