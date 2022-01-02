#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <bits/stdc++.h>
using namespace std;

pair<int, int> maxCombos(int ins[], int length) {
    int max, maxes; //max number of combos, combos that are max length
    max = maxes = 0;
    unordered_map<int, int> combos; //maps number of combos to the number of times it appears
    char prevChar;
    for(int i = 0; i < length; i++) {
        if (ins[i] == prevChar) { //if the current character is the same as the previous one
            continue; //skip it
        }
        prevChar = ins[i];
        for(int j = i+1; j < length; j++) {
            int sum = ins[i] + ins[j];
            if(!combos.count(sum)) { //creates a new entry if it doesn't exist
                combos[sum] = 1;
            }
            else { //if it does exist, increment it
                combos[sum]++;
            }
            if(combos[sum] > max) { //if the current number of combos is greater than the max, update max
                max = combos[sum];
                maxes = 1;
            }
            else if(combos[sum] == max) { //if the current number of combos is equal to the max, update maxes
                maxes++;
            }
        }
    }
    return make_pair(max, maxes);
}

int main() {
    string temp;
    int length;
    getline(cin, temp);
    length = stoi(temp);
    int ins[length];
    getline(cin, temp);
    //split temp into ins
    for (int i = 0; i < length; i++) {
        ins[i] = stoi(temp.substr(0, temp.find(' ')));
        temp = temp.substr(temp.find(' ') + 1);
    }
    sort(ins, ins+length);
    if(ins[0] == ins[length-1]) { //if all the numbers are the same
        cout << length << " " << 1;
        return 0;
    }
    pair<int, int> combos = maxCombos(ins, length);
    cout << combos.first << " " << combos.second;
    return 0;
}