#include <stdio.h>
#include <stack>
#include <vector>
#include <set>
#include <queue>

using namespace std;

int calculate_moves(int n) {
    vector<stack<int>> start = vector<stack<int>>(n);
    for (int i = 0; i < n; i++) {
        int num;
        scanf("%d", &num);
        start[i].push(num);
    }

    if (n == 1) {
        printf("0\n");
        return 0;
    }

    // queue of boards + depth of board
    queue<pair<vector<stack<int>>, int>> moves;
    moves.push(make_pair(start, 0));

    set<vector<stack<int>>> visited;
    visited.insert(start);

    while (!moves.empty()) {
        vector<stack<int>> current = moves.front().first;
        int depth = moves.front().second;
        moves.pop();

        // if in order, print depth and return
        bool inOrder = true;
        for (int i = 0; i < n; i++) {
            if (current[i].empty() || current[i].size() != 1 || current[i].top() != i + 1) {
                inOrder = false;
                break;
            }
        }
        if (inOrder) {
            printf("%d\n", depth);
            return 0;
        }

        // add all possible moves to stack
        for (int i = 0; i < n; i++) {
            if (!current[i].empty()) {
                if (i != n-1 && (current[i+1].empty() || current[i].top() < current[i+1].top())) {
                    vector<stack<int>> newBoard = current;
                    newBoard[i+1].push(newBoard[i].top());
                    newBoard[i].pop();
                    if (visited.find(newBoard) == visited.end()) {
                        moves.push(make_pair(newBoard, depth + 1));
                        visited.insert(newBoard);
                    }
                }
                if (i != 0 && (current[i-1].empty() || current[i].top() < current[i-1].top())) {
                    vector<stack<int>> newBoard = current;
                    newBoard[i-1].push(newBoard[i].top());
                    newBoard[i].pop();
                    if (visited.find(newBoard) == visited.end()) {
                        moves.push(make_pair(newBoard, depth + 1));
                        visited.insert(newBoard);
                    }
                }
            }
        }
    }

    printf("IMPOSSIBLE\n");
}

int main() {
    while (true) {
        int n;
        scanf("%d", &n);
        if (n == 0) {
            break;
        }
        calculate_moves(n);
    }

    return 0;
}