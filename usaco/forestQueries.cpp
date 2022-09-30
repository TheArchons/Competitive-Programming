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

    for (int i = 0; i < q; i++) {
        int y1, x1, y2, x2;
        scanf("%d %d %d %d", &y1, &x1, &y2, &x2);

        int sum = 0;
        for (int j = y1-1; j < y2; j++) {
            if (x1 == 1) {
                sum += a[j][x2-1];
            }
            else {
                sum += a[j][x2-1] - a[j][x1-2];
            }
        }
        printf("%d\n", sum);
    }

    return 0;
}
