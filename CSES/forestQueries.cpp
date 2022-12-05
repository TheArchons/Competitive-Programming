//https://cses.fi/problemset/task/1652

#include <stdio.h>

using namespace std;

int main() {
    int n, q;
    scanf("%d %d", &n, &q);

    int a[n][n];
    for (int i = 0; i < n; i++) {
        getchar();
        for (int j = 0; j < n; j++) {
            int d = getchar();
            a[i][j] = (d == '*' ? 1 : 0) + (j == 0 ? 0 : a[i][j-1]);
        }
    }

    // prefix top down
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            a[i][j] += (i == 0 ? 0 : a[i-1][j]);
        }
    }

    for (int i = 0; i < q; i++) {
        int y1, x1, y2, x2;
        scanf("%d %d %d %d", &y1, &x1, &y2, &x2);

        int sum = a[y2-1][x2-1];
        if (y1 > 1) {
            sum -= a[y1-2][x2-1];
        }
        if (x1 > 1) {
            sum -= a[y2-1][x1-2];
        }
        if (y1 > 1 && x1 > 1) {
            sum += a[y1-2][x1-2];
        }

        printf("%d\n", sum);

    }

    return 0;
}
