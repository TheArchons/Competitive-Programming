#include <iostream>
#include <string>
using namespace std;

int main() {
    int paints, highestX, highestY, lowestX, lowestY;
    highestX = highestY = 0;
    lowestX = lowestY = 2147483647;
    string temp;
    getline(cin, temp);
    paints = stoi(temp);
    for (int i = 0; i < paints; i++) {
        string in;
        getline(cin, in);
        int x, y;
        x = y = 0;
        for (int i = 0; i < in.length(); i++) {
            if (in[i] == ',') {
                x = stoi(in.substr(0, i));
                y = stoi(in.substr(i+1, in.length()));
            }
        }
        if (x > highestX) {
            highestX = x + 1;
        }
        if (x < lowestX) {
            lowestX = x - 1;
        }
        if (y > highestY) {
            highestY = y + 1;
        }
        if (y < lowestY) {
            lowestY = y - 1;
        }
    }
    cout << lowestX << "," << lowestY << endl << highestX << "," << highestY << endl;
    return 0;
}