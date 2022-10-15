#include<stdio.h>
#include<set>

using namespace std;

int main() {
    int x, n;
    scanf("%d %d", &x, &n);
    set<int> s;

    for (int i = 0; i < n; i++) {
        int a;
        scanf("%d", &a);
        s.insert(a);

        int max = 0;
        max = *s.lower_bound(0);
        for (set<int>::iterator it = s.begin(); it != s.end(); it++) {
            if (s.upper_bound(*it) != s.end()) {
                int temp = *s.upper_bound(*it) - *it;
                if (temp > max) {
                    max = temp;
                }
            }
            else {
                int temp = x - *it;
                if (temp > max) {
                    max = temp;
                }
            }
        }

        printf("%d ", max);
    }
}