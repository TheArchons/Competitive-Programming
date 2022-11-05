#include <stdio.h>
#include <queue>

using namespace std;

int main() {
    int totalMins, numAlgorithms;
    scanf("%d %d", &numAlgorithms, &totalMins);

    priority_queue<int, vector<int>, greater<int> > algorithms;
    for (int i = 0; i < numAlgorithms; i++) {
        int algorithm;
        scanf("%d", &algorithm);
        algorithms.push(algorithm);
    }

    int total; int count;
    total = count = 0;
    while (total <= totalMins && !algorithms.empty()) {
        int algorithm = algorithms.top();
        algorithms.pop();
        total += algorithm;
        count++;
    }

    if (total > totalMins) {
        count--;
    }

    printf("%d", count);
}