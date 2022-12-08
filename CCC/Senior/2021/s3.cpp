#include <stdio.h>
#include <climits>
#include <stdlib.h>
#include <algorithm>

using namespace std;

#define inf INT_MAX

bool compare(int a[], int b[]) {
    return a[0] < b[0];
}

// N - number of friends (0 for me)
// P - Position
// W - Walking speed (m/W)
// D - Hearing distance

int main() {
    unsigned int n;
    scanf("%d", &n);
    int arr[n][3] = {{0}};
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d", &arr[i][0], &arr[i][1], &arr[i][2]);
    }

    unsigned int min_dist = inf;

    // sort by arr[i][0]
    sort(arr, arr + n, compare);


    printf("%d\n", min_dist);
}