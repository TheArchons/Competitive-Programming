#include <iostream>
#include <string>
using namespace std;

int main() {
    string pos1, pos2, distanceStr;
    int energy, distance, pos1X, pos1Y, pos2X, pos2Y;
    getline(cin, pos1);
    getline(cin, pos2);
    getline(cin, distanceStr);
    energy = stoi(distanceStr);
    for (int i = 0; i < pos1.length(); i++) {
        if (pos1[i] == ' ') {
            pos1X = stoi(pos1.substr(0, i));
            pos1Y = stoi(pos1.substr(i + 1));
        }
    }
    for (int i = 0; i < pos2.length(); i++) {
        if (pos2[i] == ' ') {
            pos2X = stoi(pos2.substr(0, i));
            pos2Y = stoi(pos2.substr(i + 1));
        }
    }
    distance = abs(pos1X - pos2X) + abs(pos1Y - pos2Y);
    if (distance > energy) {
        cout << "N";
        return 0;
    }
    if (distance == energy) {
        cout << "Y";
        return 0;
    }
    if ((distance % 2 == 0) ^ (energy % 2 == 0)) {
        cout << "N";
    } else {
        cout << "Y";
    }
    return 0;
}