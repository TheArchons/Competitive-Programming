#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <unordered_map>

using namespace std;

bool findPair(vector<pair<int, string>> visited, pair<int, string> v) {
    for (auto i : visited) {
        if (i.first == v.first && i.second == v.second) {
            return true;
        }
    }
    return false;
}

bool findInt(vector<int> lens, int target) {
    for (int i : lens) {
        if (i == target) {
            return true;
        }
    }
    return false;
}

int main() {
    unordered_map<string, string> subs;
    vector<int> subLens;
    string temp;
    unordered_map<string, int> subCount;
    for (int i = 0; i < 3; i++) {
        cin >> temp >> subs[temp]; //fill the map
        //check if the sub is already in the vector
        if (!findInt(subLens, temp.length())) {
            subLens.push_back(temp.length());
        }
        subCount[subs[temp]] = i+1;
    }

    int findSteps; //number of steps to take
    string curr, end; //start and end strings
    cin >> findSteps >> curr >> end;

    stack<pair<pair<int, int>, string>> printPath; //for printing
    stack<string> pastStrings; //to remember past strings
    vector<pair<int, string>> visited;//visited (steps, string) pairs
    //visited.push_back({0, curr}); //add the curr string to the visited vector

    next:
    while(curr != end) { //DFS until we reach the end value
        if (findSteps != 0) { //try to replace if we haven't used all of our steps
            for (int subLen : subLens) {
                //sliding window
                for (int i = 0; i <= curr.length()-subLen; i++) {
                    string searchStr = curr.substr(i, subLen); //the substring to replace
                    //search the hashmap for searchStr
                    if (subs.find(searchStr) != subs.end()) { //if it's in the map
                        string replaceStr = subs[searchStr]; //get the replacement string
                        string newStr = curr.substr(0, i) + replaceStr + curr.substr(i+subLen); //create the new string
                        if (findPair(visited, make_pair(findSteps, newStr)) == false) { //if it's not in the visited vector
                            printPath.push({{subCount[replaceStr], i+1}, newStr}); //push the new string to the stack
                            pastStrings.push(newStr); //add the new string to the pastStrings stack
                            visited.push_back({findSteps, newStr}); //add the new string to the visited vector
                            curr = newStr; //set the current string to the new string
                            findSteps--; //decrement the steps
                            goto next; //go to the next iteration
                        }
                    }


                }
            }
        }
        //else { //backtrack
            pastStrings.pop(); //pop the top of the pastStrings stack
            curr = pastStrings.top(); //set the current string to the top of the pastStrings stack
            
            printPath.pop(); //pop the top of the printPath stack
            findSteps += 1; //increment the steps
            goto next; //go to the next iteration
        //}
    }

    //reverse the printPath stack
    stack<pair<pair<int, int>, string>> printPathRev;
    while (!printPath.empty()) {
        printPathRev.push(printPath.top());
        printPath.pop();
    }
    printPath = printPathRev;

    //print the path
    while (!printPath.empty()) {
        pair<pair<int, int>, string> p = printPath.top();
        cout << p.first.first << " " << p.first.second << " " << p.second << endl;
        printPath.pop();
    }
    return 0;
}