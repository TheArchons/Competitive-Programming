#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main() {
    string books;
    int LCount = 0, MCount = 0, SCount = 0, MInL = 0, MInS = 0, LInM = 0, LInS = 0, SInM = 0, SInL = 0, OOP = 0, addOOP = 0;
    float OOPF = 0;
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
                OOP++;
            } else if (books[i] == 'S') {
                SInL++;
                OOP++;
            }
        }
        else if (i < LCount + MCount) {
            if (books[i] == 'L') {
                LInM++;
                OOP++;
            }
            else if (books[i] == 'S') {
                SInM++;
                OOP++;
            }
        }
        else {
            if (books[i] == 'L') {
                LInS++;
                OOP++;
            }
            else if (books[i] == 'M') {
                MInS++;
                OOP++;
            }
        }
    }
    OOPF = OOP/2.0;
    OOP = ceil(OOPF);
    cout << OOP << endl;
    return 0;
}