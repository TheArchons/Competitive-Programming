#include <stdio.h>
#include <algorithm>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);

    tuple<int, int> movies[n];
    for (int i = 0; i < n; i++) {
        int start; int end;
        scanf("%d %d", &start, &end);

        movies[i] = make_tuple(start, end);
    }

    sort(movies, movies + n, [](tuple<int, int> a, tuple<int, int> b) {
        return get<1>(a) < get<1>(b);
    });

    int minStart = 0;
    int count = 0;
    for (int i = 0; i < n; i++) {
        int start = get<0>(movies[i]);
        int end = get<1>(movies[i]);

        if (start >= minStart) {
            minStart = end;
            count++;
        }
    }

    printf("%d", count);
}