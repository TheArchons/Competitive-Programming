#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    bool found, used;
    found = used = false;
    int x, y, row, col, prevSpace, currX, currY, visitable;
    vector<pair<unsigned int, unsigned int>> prevPath;
    row = col = prevSpace = 0;
    string temp;
    getline(cin, temp);
    y = stoi(temp);
    getline(cin, temp);
    x = stoi(temp);
    int grids[y][x] = {0};
    currX = x - 1; currY = y - 1;
    for (int i = 0; i < y; i++) {
        getline(cin, temp);
        for (int j = 0; j < temp.length(); j++) {
            if (temp[j] == ' ') {
                grids[row][col] = stoi(temp.substr(prevSpace, j));
                prevSpace = j;
                col++;
            }
        }
        grids[row][x-1] = stoi(temp.substr(prevSpace, temp.length()));
        prevSpace = col = 0;
        row++;
    }
    if (x * y < grids[0][0]) {
        cout << "no" << endl;
        return 0;
    }
    else if (x * y == grids[0][0]) {
        cout << "yes" << endl;
        return 0;
    }
    while (currX != 0 || currY != 0) {
        found = used = false;
        visitable = (currX + 1) * (currY + 1);
        prevPath.push_back(make_pair(currX, currY));
        for (int i = 0; i < y; i++) {
            for (int j = 0; j < x; j++) {
                if (grids[i][j] == visitable && (i+1)*(j+1) != visitable) {
                    for (int z = 0; z < prevPath.size(); i++) {
                        if (prevPath[z].first == j && prevPath[z].second == z) {
                            break;
                        }
                    }
                    if (used) {
                        break;
                    } else {
                        currX = j; currY = i;
                        found = true;
                        break;
                    }                 
                }
            }
            if (found) {
                break;
            }
        }
        if (found) {
            continue;
        }
        prevPath.pop_back();
        grids[currY][currX] = 0;
        currX = prevPath.back().first; currY = prevPath.back().second;
        if (empty(prevPath)) {
            cout << "no" << endl;
            return 0;
        }
    }
    cout << "yes" << endl;
}