#include <stdio.h>

using namespace std;

int main() {
    int seqLen; int numQueries;
    scanf("%d %d", &seqLen, &numQueries);

    unsigned long long psum[seqLen];
    unsigned long long sum = 0;
    for (int i = 0; i < seqLen; i++) {
        int n;
        scanf("%d", &n);
        sum += n;
        psum[i] = sum;
    }

    for (int i = 0; i < numQueries; i++) {
        int start, end;
        scanf("%d %d", &start, &end);
        if (start == 0) {
            printf("%llu\n", psum[end-1]);
        }
        else {
            printf("%llu\n", psum[end-1] - psum[start-1]);
        }
    }
}
