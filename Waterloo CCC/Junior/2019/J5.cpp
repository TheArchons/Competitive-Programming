#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <unordered_set>

using namespace std;

bool isVisited(vector<pair<int, string>> visited, pair<int, string> v) {\
    for (auto i : visited) {
        if (i.first == v.first && i.second == v.second) {
            return true;
        }
    }
    return false;
}

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

    stack<pair<pair<int, int>, string>> s; //for printing
    stack<string> s2; //to remember past strings
    vector<pair<int, string>> visited;
    string curr = start;
    bool found = false;
    next: //position uncertain
    while(curr != end) {
        if (steps != 0 || !found) {
            found = false;
            //if we haven't reached the stepcount yet, attempt to replace as long as it hasn't been visited
            for (int i : subLens) {
                //sliding window
                for (int j = 0; j <= curr.length()-i; j++) {
                    string tempStr = curr.substr(j, i);
                    //check if it's a sub
                    for (int k = 0; k < 3; k++) {
                        string find = subs[k].first;
                        string replace = subs[k].second;
                        if (tempStr == find) { //if the substr is a valid sub
                            if (!isVisited(visited, make_pair(steps, curr))) { //if it hasn't been visited
                                curr.replace(j, i, replace);
                                s.push({{k+1, j}, curr});
                                s2.push(curr);
                                steps--;
                                found = true;
                                
                                goto next;
                            }
                        }
                    }

                }
            }
        }
        else { //if we have reached the stepcount, backtrack
            
            s2.pop();
            if (s2.empty()) {
                curr = start;
            }
            else {
                curr = s2.top();
            }
            s.pop();
            steps++;
            found = true;
            visited.push_back(make_pair(steps, curr));
        }
    }
    //reverse stack
    stack<pair<pair<int, int>, string>> s3;
    while (!s.empty()) {
        s3.push(s.top());
        s.pop();
    }
    //print the stack
    while(!s3.empty()) {
        cout << s3.top().first.first << " " << s3.top().first.second+1 << " " << s3.top().second << endl;
        s3.pop();
    }

    return 0;
}