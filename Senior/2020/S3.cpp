#include <iostream>
#include <vector>

using namespace std;

int main() {
    string needle, haystack;
    int total;
    cin >> needle >> haystack;
    vector<string> needlePerms(needle.size());
    //permutations of needle
    for (int i = 0; i < needle.size(); i++) {
        for (int j = 0; j < needle.size(); j++) {
            //move by one
            needlePerms[i] += needle[(i+j)%needle.size()];
        }
    }
    //check if haystack contains any of the permutations of needle
    for (int i = 0; i < needlePerms.size(); i++) {
        if (haystack.find(needlePerms[i]) != string::npos) {
            total++;
        }
    }
    cout << total;
    return 0;
}