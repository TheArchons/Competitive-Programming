#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int main() {
    string tempStr, names1, names2;
    int friendCount, prevName, count;
    getline(cin, tempStr);
    friendCount = stoi(tempStr);
    getline(cin, names1);
    getline(cin, names2);
    unordered_map<string, string> friends;
    //split names1 and names 2 into arrays
    string names1Arr[friendCount], namesArr2[friendCount];
    count = prevName = 0;
    for (int i = 0; i < names1.length(); i++) {
        if (names1[i] == ' ') {
            names1Arr[count] = names1.substr(prevName, i-prevName);
            prevName = i + 1;
            count++;
        }
    }
    names1Arr[count] = names1.substr(prevName, names1.length() - prevName);
    prevName = count = 0;
    for (int i = 0; i < names2.length(); i++) {
        if (names2[i] == ' ') {
            namesArr2[count] = names2.substr(prevName, i-prevName);
            prevName = i + 1;
            count++;
        }
    }
    namesArr2[count] = names2.substr(prevName, names2.length() - prevName);

    for (int i = 0; i < friendCount; i++) {
        if (names1Arr[i] == namesArr2[i]) {
            cout << "bad";
            return 0;
        }
        if(!friends.count(names1Arr[i])) {
            friends[names1Arr[i]] = namesArr2[i];
            friends[namesArr2[i]] = names1Arr[i];
        }
        else {
            if(friends[names1Arr[i]] != namesArr2[i] || friends[namesArr2[i]] != names1Arr[i]) {
                cout << "bad";
                return 0;
            }
        }
    }
    cout << "good";
    return 0;
}