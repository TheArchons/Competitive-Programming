#include <iostream>
#include <stack>
#include <tuple>

using namespace std;

int main() {
    int contestCount, rank, maxRank;
    maxRank = 0;
    scanf("%d %d", &contestCount, &rank);
    tuple<int, int, int> contests[contestCount]; //skipPos, nextPos, score
    for (int i = 0; i < contestCount; i++) {
        int skipPos, nextPos, score, pos;
        scanf("%d %d %d %d", &pos, &skipPos, &nextPos, &score);
        contests[i] = make_tuple(skipPos-1, nextPos-1, score);
    }

    stack<tuple<int, int, bool>> path; //pos, score, isSkip
    path.push(make_tuple(1, get<2>(contests[0]), false));
    while(!path.empty()) {
        if (get<0>(path.top()) > contestCount-1) { //unsure if this is correct
            //out of bounds
            bool isSkip = get<2>(path.top());
            rank += get<1>(path.top());
            if (rank > maxRank) {
                maxRank = rank;
            }
            rank -= get<1>(path.top());
            path.pop();
            if (path.empty()) {
                break;
            }
            if (isSkip) {
                get<1>(contests[get<0>(path.top())]) = -1;
            }
            else {
                get<0>(contests[get<0>(path.top())]) = -1;
            }
        }
        else if (get<0>(contests[get<0>(path.top())]) == -1) {
            if (get<1>(contests[get<0> (path.top())]) == -1) {
                //skip because we've visited both
                bool isSkip = get<2>(path.top());
                rank -= get<1>(path.top());
                path.pop();\
                if (path.empty()) {
                    break;
                }
                if (isSkip) {
                    get<1>(contests[get<0>(path.top())]) = -1;
                }
                else {
                    get<0>(contests[get<0>(path.top())]) = -1;
                }
            }
            else if (get<1>(contests[get<0>(path.top())]) > contestCount-1) {
                //out of bounds
                /*bool isSkip = get<2>(path.top());
                rank += get<1>(path.top());
                if (rank > maxRank) {
                    maxRank = rank;
                }
                //backtrack
                rank -= get<1>(path.top());
                //path.pop();
                if (isSkip) {
                    get<1>(contests[get<0>(path.top())]) = -1;
                }
                else {
                    get<0>(contests[get<0>(path.top())]) = -1;
                }*/
                get<1>(contests[get<0>(path.top())]) = -1;
            }
            else {
                path.push(make_tuple(get<1>(contests[get<0>(path.top())]), 0, true));
            }
        }
        else {
            rank += get<1>(path.top());
            path.push(make_tuple(get<0>(contests[get<0>(path.top())]), get<2>(contests[get<0>(path.top())]), false));
        }
    }
    printf("%d\n", maxRank);
    return 0;
}