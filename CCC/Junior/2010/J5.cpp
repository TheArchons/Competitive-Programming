#include <iostream>
#include <queue>

using namespace std;

int main() {
    int startX, startY, endX, endY;
    cin >> startX >> startY >> endX >> endY;
    
    //bfs to find the shortest path
    vector<queue<pair<int, int>>> q; //queue of pairs of (x, y)
    q.push_back(queue<pair<int, int>>());
    q.back().push(make_pair(startX, startY));
    while (q.back().back().first != endX || q.back().back().second != endY) {
        //check all jumps within and 8x8 chessboard
        
    }
}