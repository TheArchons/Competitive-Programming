#include <iostream>
#include <stack>
#include <tuple>

using namespace std;

int main() {
    int contestCount, rank;
    scanf("%d %d", &contestCount, &rank);
    tuple<int, int, int> contests[contestCount]; //skipPos, nextPos, score
    for (int i = 0; i < contestCount; i++) {
        int skipPos, nextPos, score, pos;
        scanf("%d %d %d %d", &pos, &skipPos, &nextPos, &score);
        contests[i] = make_tuple(skipPos-1, nextPos-1, score);
    }


    stack<pair<int, int>> path;
    path.push(make_pair(1, get<2>(contests[0])));
    while(!path.empty()) {
        if (get<0>(contests[path.top().first]) == -1) {
            if (path.top().first == -1) {
                rank -= path.top().second;
                path.pop();
            }
            else if (get<1>(contests[path.top().first]) > contestCount-1) {
                //out of bounds
                rank += path.top().second;
                return -1;
            }
            else {
                path.push(make_pair(get<1>(contests[path.top().first]), get<2>(contests[path.top().first])));
            }
        }
        else if (path.top().first > contestCount-1) {
            //out of bounds
            rank += path.top().second;
            return -1;
        }
        else {
            rank += path.top().second;
            path.push(make_pair(get<0>(contests[path.top().first]), get<2>(contests[path.top().first])));
        }
    }
    return 0;
}