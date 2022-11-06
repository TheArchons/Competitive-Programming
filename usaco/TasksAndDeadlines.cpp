#include <algorithm>
#include <tuple>
#include <stdio.h>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);

    tuple<int, int> tasks[n];
    for (int i = 0; i < n; i++) {
        int duration, deadline;
        scanf("%d %d", &duration, &deadline);

        tasks[i] = make_tuple(duration, deadline);
    }

    sort(tasks, tasks + n);

    long long int reward; long long int time;
    reward = time = 0;
    for (int i = 0; i < n; i++) {
        int duration = get<0>(tasks[i]);
        int deadline = get<1>(tasks[i]);

        time += duration;

        reward += deadline - time;
    }

    printf("%lld", reward);
}