#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    pair<string, string> subs[3];
    vector<int> subLens;
    for (int i = 0; i < 3; i++) {
        cin >> subs[i].first >> subs[i].second;
        for (int j : subLens) {
            if (subs[i].first.length() == j) {
                goto dontPush;
            }
        }
        subLens.push_back(subs[i].first.length());
        dontPush:;
    }
    int steps;
    string start, end;
    cin >> steps >> start >> end;



    return 0;
}