#include <iostream>
#include <unordered_set>
#include <unordered_map>

using namespace std;

bool isVisited(unordered_map<int, unordered_set<int>> visited, pair<int, int> curr) {
    if (visited[curr.first].find(curr.second) != visited[curr.first].end()) {
        return true;
    }
    return false;
}

int main() {
    unordered_map<int, unordered_set<int>> visited;
    visited[-1].insert(-5); visited[-1].insert(-6); visited[-1].insert(-7);
    visited[0].insert(-1); visited[0].insert(-2); visited[0].insert(-3); visited[0].insert(-7);
    visited[1].insert(-3); visited[1].insert(-7);
    visited[2].insert(-7); visited[2].insert(-3);
    visited[3].insert(-3); visited[3].insert(-7); visited[3].insert(-4); visited[3].insert(-5);
    visited[4].insert(-5); visited[4].insert(-7);
    visited[5].insert(-3); visited[5].insert(-7); visited[5].insert(-4); visited[5].insert(-5);
    visited[6].insert(-7); visited[6].insert(-3);
    visited[7].insert(-3); visited[7].insert(-7); visited[7].insert(-4); visited[7].insert(-5); visited[7].insert(-6);
    pair<int, int> curr = {-1, -5};
    while(true) {
        char direction;
        int steps;
        scanf("\n%c %d", &direction, &steps);
        if (direction == 'q') {
            return 0;
        }
        for (int i = 0; i < steps; i++) {
            if (direction == 'd') {
                curr.second--;
                if (isVisited(visited, curr)) {
                    curr.second -= steps-i-1;
                    printf("%d %d DANGER\n", curr.first, curr.second);
                    
                    return 0;
                }
                visited[curr.first].insert(curr.second);
            }
            else if(direction == 'u') {
                curr.second++;
                if (isVisited(visited, curr)) {
                    curr.second += steps-i-1;
                    printf("%d %d DANGER\n", curr.first, curr.second);
                    
                    return 0;
                }
                visited[curr.first].insert(curr.second);
            }
            else if(direction == 'l') {
                curr.first--;
                if (isVisited(visited, curr)) {
                    curr.first -= steps-i-1;
                    printf("%d %d DANGER\n", curr.first, curr.second);
                    
                    return 0;
                }
                visited[curr.first].insert(curr.second);
            }
            else if(direction == 'r') {
                curr.first++;
                if (isVisited(visited, curr)) {
                    curr.first += steps-i-1;
                    printf("%d %d DANGER\n", curr.first, curr.second);
                    
                    return 0;
                }
                visited[curr.first].insert(curr.second);
            }
        }
        printf("%d %d safe\n", curr.first, curr.second);
    }
    return 0;
}