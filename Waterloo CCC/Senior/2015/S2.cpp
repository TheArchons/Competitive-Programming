#include <bits/stdc++.h>

using namespace std;

const map<char, int> jerseySize = {
    {'S', 0},
    {'M', 1},
    {'L', 2},
};

int main() {
    //freopen("2.input", "r", stdin); // for testing
    int jerseyNum, numPlayers;
    scanf("%d\n%d\n", &jerseyNum, &numPlayers);

    map<int, int> jerseyMap;
    for (int i = 1; i < jerseyNum + 1; i++) {
        char size;
        scanf("%c\n", &size);
        jerseyMap[i] = jerseySize.at(size);
    }

    int total = 0;
    for (int i = 0; i < numPlayers; i++) {
        char size;
        int number;
        scanf("%c\n%d\n", &size, &number);
        
        if (jerseyMap[number] >= jerseySize.at(size)) {
            total++;
            jerseyMap[number] = -1;
        }
    }

    printf("%d", total);
}