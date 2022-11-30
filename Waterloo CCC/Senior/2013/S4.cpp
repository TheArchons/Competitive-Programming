#include <bits/stdc++.h>

using namespace std;

int main() {
    int people, comparisons;
    scanf("%d %d", &people, &comparisons);

    map<int, vector<int>> comparisonGraph1, comparisonGraph2;

    for (int i = 0; i < comparisons; i++) {
        int person1, person2;
        scanf("%d %d", &person1, &person2);
        comparisonGraph1[person1].push_back(person2);
        comparisonGraph2[person2].push_back(person1);
    }

    int p, q;
    scanf("%d %d", &p, &q);

    queue<int> queue;
    queue.push(p);
    set<int> visited;

    while (!queue.empty()) {
        int current = queue.front();
        queue.pop();

        if (current == q) {
            printf("yes");
            return 0;
        }

        for (int i = 0; i < comparisonGraph1[current].size(); i++) {
            int next = comparisonGraph1[current][i];
            if (visited.find(next) == visited.end()) {
                visited.insert(next);
                queue.push(next);
            }
        }
    }

    queue.push(q);
    visited.clear();

    while (!queue.empty()) {
        int current = queue.front();
        queue.pop();

        if (current == p) {
            printf("no");
            return 0;
        }

        for (int i = 0; i < comparisonGraph2[current].size(); i++) {
            int next = comparisonGraph2[current][i];
            if (visited.find(next) == visited.end()) {
                visited.insert(next);
                queue.push(next);
            }
        }
    }

    printf("unknown");
}