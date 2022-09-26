#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main() {
    string books;
    int LCount = 0, MCount = 0, SCount = 0, MInL = 0, MInS = 0, LInM = 0, LInS = 0, OOP = 0, addOOP = 0;
    cin >> books;
    for (int i = 0; i < books.length(); i++) {
        if (books[i] == 'L') {
            LCount++;
        } else if (books[i] == 'M') {
            MCount++;
        } else {
            SCount++;
        }
    }
    for (int i = 0; i < books.length(); i++) {
        if (i < LCount) {
            if (books[i] == 'M') {
                MInL++;
            }
        }
        else if (i < LCount + MCount) {
            if (books[i] == 'L') {
                LInM++;
            }
        }
        else {
            if (books[i] == 'L') {
                LInS++;
            }
            else if (books[i] == 'M') {
                MInS++;
            }
        }
    }
    OOP = MInL+LInM+MInS+LInS - min(MInL, LInM);
    cout << OOP << endl;
    return 0;
}