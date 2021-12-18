#include <iostream>
using namespace std;

void printChars(char str, int n) {
    for (int i = 0; i < n; i++) {
        cout << str;
    }
    cout << endl;
}

int main() {
    int lines;
    string temp;
    char c;
    getline(cin, temp); lines = stoi(temp);
    for (int i = 0; i < lines; i++) {
        getline(cin, temp);
        int pos = temp.find(" ");
        int charCount = stoi(temp.substr(0, pos));
        c = temp.back();
        printChars(c, charCount);
    }
}