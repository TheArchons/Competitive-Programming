#include <stdio.h>
#include <vector>

using namespace std;

int main() {
    freopen("paintbarn.in", "r", stdin); freopen("paintbarn.out", "w", stdout);

    int n, k;
    scanf("%d %d", &n, &k);

    vector<vector<int>> side;
    side.resize(1000);
    for (int i = 0; i < 1000; i++) {
        side[i].resize(1000);
    }

    // set all to 0
    for (int i = 0; i < 1000; i++) {
        for (int j = 0; j < 1000; j++) {
            side[i][j] = 0;
        }
    }


    for (int i = 0; i < n; i++) {
        int x1, y1, x2, y2;
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

        // add markers
        for (int j = y1; j < y2; j++) {
            side[x1][j]++;
            side[x2][j]--;
        }
    }

    // read over array and count
    int count = 0;
    for (int i = 0; i < 1000; i++) {
        int sum = 0;
        for (int j = 0; j < 1000; j++) {
            sum += side[j][i];
            if (sum == k) {
                count++;
            }
        }
    }

    printf("%d", count);

    return 0;
}