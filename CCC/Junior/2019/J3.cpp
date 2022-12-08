#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    int loops;
    string currLine;
    char lastChar;
    vector<string> chars;
    vector<vector<string>> splitChars;
    vector<vector<vector<string>>> lines;
    cin >> loops;
    lines.reserve(loops);
    for (int i = 0; i < loops; i++) {
        cin >> currLine;
        chars.clear();
        lastChar = currLine[0];
        for (int j = 0; j < currLine.length(); j++) {
            if (currLine[j] != lastChar) {
                lastChar = currLine[j];
                splitChars.push_back(chars);
                chars.clear();
                chars.push_back(string(1, currLine[j]));
            }
            else {
                chars.push_back(string(1, lastChar));
            }
        }
        splitChars.push_back(chars);
        lines.push_back(splitChars);
        splitChars.clear();
    }
    // finished splitting
    for (int i = 0; i < lines.size(); i++) {
        for (int j = 0; j < lines[i].size(); j++) {
            cout << lines[i][j].size() << " " << lines[i][j][0] << " ";
        }
        cout << "\n";
    }
    return 0;
}