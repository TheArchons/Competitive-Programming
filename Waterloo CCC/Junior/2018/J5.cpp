#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

int shortestPath(vector<int> (&ins)[]) {
    queue<int> toVisit;
    int depth = 1;
    int loopCount = 0;
    int valsInLayer = 0;
    bool newDepth = true;
    toVisit.push(1);
    while(true) {
        vector<int> currIn = ins[toVisit.front()-1];
        if(newDepth) {
            valsInLayer = toVisit.size();
            newDepth = false;
        }
        toVisit.pop();
        if(empty(currIn)) {
            return depth;
        }
        while(!empty(currIn)) {
            toVisit.push(currIn.back());
            currIn.pop_back();
        }
        loopCount++;
        if(loopCount == valsInLayer) {
            depth++;
            newDepth = true;
            loopCount = 0;
        }
    }
}

int main() {
    string tempStr;
    int length, count = 0;
    getline(cin, tempStr);
    length = stoi(tempStr);
    vector<int> pages[length];
    bool notVisitable[length] = {true}, cantVisitAll = false; notVisitable[0] = true;
    for(int i = 0; i < length; i++) {
        getline(cin, tempStr);
        int prevPos = 0;
        for(int j = 0; j < tempStr.length(); j++) {
            if(tempStr[j] == ' ') {
                prevPos = j + 1;
                int tempInt = stoi(tempStr.substr(prevPos, j - prevPos));
                pages[i].push_back(tempInt);
                if(i != tempInt-1) {
                    notVisitable[tempInt-1] = true;
                }
            }
        }
    }
    for(int i = 0; i < length; i++) {
        if(!notVisitable[i]) {
            cout << "N" << endl;
            cantVisitAll = true;
            break;
        }
    }
    if(!cantVisitAll) {
        cout << "Y" << endl;
    }
    cout << shortestPath(pages) << endl;
    return 0;
}