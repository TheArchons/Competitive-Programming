#include <stdio.h>
#include <climits>
#include <stdlib.h>

using namespace std;

#define inf INT_MAX

// N - number of friends (0 for me)
// P - Position
// W - Walking speed (m/W)
// D - Hearing distance

int main() {
    unsigned int n;
    scanf("%d", &n);
    int arr[n][3];
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d", &arr[i][0], &arr[i][1], &arr[i][2]);
    }

    unsigned int min_dist = inf;
    for (int i = 0; i < n; i++) {
        int loc1 = arr[i][0]-arr[i][2];
        int loc2 = arr[i][0]+arr[i][2];
        int locations[2] = {loc1, loc2};
        for (int k = 0; k < 2; k++) {
            unsigned int dist = 0;
            for (int j = 0; j < n; j++) {
                int walkTime = (abs(locations[k] - arr[j][0])-arr[j][2])*arr[j][1];
                if (walkTime < 0) {
                    walkTime = 0;
                }
                dist += walkTime;
            }
            if (dist < min_dist) {
                min_dist = dist;
            }
        }
    }

    printf("%d\n", min_dist);
}