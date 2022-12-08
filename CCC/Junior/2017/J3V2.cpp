#include <iostream>
#include <string>
using namespace std;

int main() {
    string temp;
    pair<int, int> startPos, endPos;
    int energy, distance;
    getline(cin, temp);
    startPos.first = stoi(temp.substr(0, temp.find(' ')));
    startPos.second = stoi(temp.substr(temp.find(' ') + 1));
    getline(cin, temp);
    endPos.first = stoi(temp.substr(0, temp.find(' ')));
    endPos.second = stoi(temp.substr(temp.find(' ') + 1));
    getline(cin, temp);
    energy = stoi(temp);
    distance = abs(startPos.first - endPos.first) + abs(startPos.second - endPos.second);
    if (distance <= energy && ((energy-distance) % 2) == 0) {
        cout << "Y";
    } else {
        cout << "N";
    }
    return 0;
}