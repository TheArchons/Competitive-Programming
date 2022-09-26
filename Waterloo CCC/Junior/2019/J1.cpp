#include <iostream>
#include <stdio.h>
using namespace std;

int main() {
    int apples = 0, temp = 0, bananas = 0;
    for (int i = 3; i > 0; i--) {
        cin >> temp;
        apples += temp*i;
    }
    for (int i = 3; i > 0; i--) {
        cin >> temp;
        bananas += temp*i;
    }
    if (apples > bananas) {
        cout << "A";
    }
    else if (apples < bananas) {
        cout << "B";
    }
    else {
        cout << "T";
    }
    return 0;
}