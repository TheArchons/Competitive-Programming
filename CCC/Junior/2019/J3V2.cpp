#include <iostream>
#include <vector>
using namespace std;

void countSymbols() {
    string str;
    getline(cin, str);
    int charCount = -1;
    char currChar = str[0];
    for (int i = 0; i < str.length(); i++) {
        charCount++;
        if (str[i] != currChar) {
            cout << charCount << " " << currChar << " ";
            charCount = 0;
            currChar = str[i];
            continue;
        }
    }
    cout << charCount + 1 << " " << currChar << endl;
}

int main() {
    int lines;
    vector<pair<char, int>> chars[4];
    string temp;
    getline(cin, temp); lines = stoi(temp);
    for (int i = 0; i < lines; i++) {
        countSymbols();
    }
    return 0;
}