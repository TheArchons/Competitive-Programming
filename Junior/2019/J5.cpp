#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <bits/stdc++.h>
#include <utility>
#include <tuple>
#include <stack>
using namespace std;

pair<unordered_map<string, pair<string, int>>, unordered_set<int>> takeIns() { //takes inputs for substitutions
    string temp;
    unordered_map<string, pair<string, int>> replaceable;
    unordered_set<int> lengths;
    for (int i = 0; i < 3; i++) {
        getline(cin, temp);
        for (int j = 0; j < temp.length(); j++) {
            if (temp[j] == ' ') {
                replaceable[temp.substr(0, j)] = make_pair(temp.substr(j+1, temp.length()), i + 1);
                lengths.insert(j + 1);
            }
        }
    }
    return make_pair(replaceable, lengths);
}

tuple<int, string, string> takeIn2() { // takes inputs for steps, start, and end
    string temp;
    getline(cin, temp);
    int x;
    string y, z;
    bool didntFindSpace = true;
    for (int i = 0; i < temp.length(); i++) {
        int j;
        if (didntFindSpace) {
            if (temp[i] == ' ') {
                didntFindSpace = false;
                x = stoi(temp.substr(0, i));
                j = i + 1;
            }
        } else {
            if (temp[i] == ' ') {
                y = temp.substr(j, i - j);
                z = temp.substr(i + 1, temp.length() - i - 1);
                break;
            }
        }
    }
    return (make_tuple(x, y, z));
}

tuple<int, int, string> findReplaceable(string currString, unordered_map<string, pair<string, int>> replaceable, unordered_set<int> lengths, vector<pair<string, int>> cantReplace) { //Possibility of this not functioning
    //Somehow doesn't check all the possibilities
    while(!empty(lengths)) {
        int length = *lengths.begin() - 1;
        lengths.erase(lengths.begin());
        for (int i = 0; i < currString.length() - length + 1; i++) {
            bool breakOut = false;
            if (replaceable.count(currString.substr(i, length)) != 0) {
                vector<pair<string, int>> cantReplaceCopy = cantReplace;
                while (!empty(cantReplaceCopy)) {
                    if ((cantReplaceCopy.back().first == replaceable.at(currString.substr(i, length)).first) && (cantReplaceCopy.back().second == i)) {
                        breakOut = true;
                        break;
                    }
                    cantReplaceCopy.pop_back();
                }
                if (!breakOut) {
                    return(make_tuple(replaceable.at(currString.substr(i, length)).second, i, currString.substr(i, length)));
                }
            }
        }
    }
    return make_tuple(0, 0, "");
}

vector<string> DFSSubstitutions(unordered_map<string, pair<string, int>> replaceable, unordered_set<int>, int steps, string startStr, string endStr, unordered_set<int> lengths) { //performs DFS
    vector<string> visited;
    vector<pair<string, int>> cannotReplace[50];
    stack<string> prevStrings;
    string current = startStr;
    int stepCount = 0;
    prevStrings.push(startStr);
    tuple<int, int, string, string> tempTuple;
    while((current != endStr) || (stepCount != steps)) {
        tuple<int, int, string> tempTuple = findReplaceable(current, replaceable, lengths, cannotReplace[stepCount + 1]);
        if (get<0>(tempTuple) != 0 && stepCount != steps) {
            stepCount++;
            current.erase(get<1>(tempTuple), get<2>(tempTuple).length());
            current.insert(get<1>(tempTuple), replaceable.at(get<2>(tempTuple)).first);
            cannotReplace[stepCount].push_back(make_pair(replaceable.at(get<2>(tempTuple)).first, get<1>(tempTuple)));
            prevStrings.push(current);
            visited.push_back(to_string(get<0>(tempTuple)) + " " + to_string(get<1>(tempTuple) + 1) + " " + current);
            continue;
        }
        //Reverses back by one
        stepCount--;
        prevStrings.pop();
        cout << prevStrings.top() << endl;
        current = prevStrings.top();
        visited.pop_back();
    }
    return visited;
}

void printVisited(vector<string> visited) {
    for (int i = 0; i < visited.size(); i++) {
        cout << visited.at(i) << endl;
    }
}

int main() {
    string temp, startStr, endStr;
    int steps;
    pair<unordered_map<string, pair<string, int>>, unordered_set<int>> ins = takeIns(); //take inputs
    unordered_map<string, pair<string, int>> replaceable = ins.first; unordered_set<int> lengths = ins.second; //allocates pair into respective variables
    tuple<int, string, string> ins2 = takeIn2(); //take inputs
    steps = get<0>(ins2); startStr = get<1>(ins2); endStr = get<2>(ins2); //allocates tuple into respective variables
    vector<string> DFSSubs = DFSSubstitutions(replaceable, lengths, steps, startStr, endStr, lengths); //performs DFS
    printVisited(DFSSubs); //print DFS
    return 0;
}