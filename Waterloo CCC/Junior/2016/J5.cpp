#include <iostream>
#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int main() {
    string input;
    bool Q2;
    int racers;
    getline(cin, input);
    Q2 = stoi(input) - 1;
    getline(cin, input);
    racers = stoi(input);
    vector<int> dmoj, peg;
    dmoj.reserve(racers);
    peg.reserve(racers);
    getline(cin, input);
    //split input into a vector by spaces
    int prevLoc = 0;
    for (int i = 0; i < input.length(); i++) {
        if (input[i] == ' ') {
            dmoj.push_back(stoi(input.substr(prevLoc, i - prevLoc)));
            prevLoc = i + 1;
        }
    }
    //get last int
    dmoj.push_back(stoi(input.substr(prevLoc, input.length() - prevLoc)));
    //do the same for peg
    getline(cin, input);
    prevLoc = 0;
    for (int i = 0; i < input.length(); i++) {
        if (input[i] == ' ') {
            peg.push_back(stoi(input.substr(prevLoc, i - prevLoc)));
            prevLoc = i + 1;
        }
    }
    peg.push_back(stoi(input.substr(prevLoc, input.length() - prevLoc)));
    //sort dmoj and peg
    sort(dmoj.begin(), dmoj.end()); sort(peg.begin(), peg.end());
    int total = 0;
    if (!Q2) {
        for (int i = 0; i < racers; i++) {
            total += max(dmoj.back(), peg.back());
            dmoj.pop_back(); peg.pop_back();
        }
    }
    else {
        for (int i = 0; i < racers; i++) {
            total += max(dmoj.back(), peg.front());
            dmoj.pop_back(); peg.erase(peg.begin());
        }
    }
    cout << total;
    return 0;
}