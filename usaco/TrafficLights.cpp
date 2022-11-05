#include<stdio.h>
#include<set>
#include<map>

using namespace std;

int main() {
    int x, n;
    scanf("%d %d", &x, &n);
    set<int> lights;
    lights.insert(0); lights.insert(x);

    map<int, int> gaps; // gap -> count

    for (int i = 0; i < n; i++) {
        int light;
        scanf("%d", &light);

        set<int>::iterator it = lights.lower_bound(light);
        int right = *it;
        it--;
        int left = *it;

        int gap = right - left;
        if (gaps.find(gap) != gaps.end()) {
            gaps[gap]--;
            if (gaps[gap] == 0) {
                gaps.erase(gap);
            }
        }

        lights.insert(light);
        gap = light - left;
        if (gaps.find(gap) != gaps.end()) {
            gaps[gap]++;
        } else {
            gaps[gap] = 1;
        }

        gap = right - light;
        if (gaps.find(gap) != gaps.end()) {
            gaps[gap]++;
        } else {
            gaps[gap] = 1;
        }

        printf("%d ", gaps.rbegin()->first);
    }
}