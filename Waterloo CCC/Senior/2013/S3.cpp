#include <stdio.h>
#include <set>
#include <queue>

using namespace std;

int main() {
    set<pair<int, int>> combinations;
    for (int i = 1; i < 5; i++) {
        for (int j = i+1; j < 5; j++) {
            combinations.insert({i, j});
        }
    }

    int fav, gamesPlayed;
    scanf("%d %d", &fav, &gamesPlayed);

    int teamScores[4] = {0};
    for (int i = 0; i < gamesPlayed; i++) {
        int a, b, aScore, bScore;
        scanf("%d %d %d %d", &a, &b, &aScore, &bScore);

        if (aScore > bScore) {
            teamScores[a-1] += 3;
        } else if (bScore > aScore) {
            teamScores[b-1] += 3;
        } else {
            teamScores[a-1] += 1;
            teamScores[b-1] += 1;
        }

        if (a > b) {
            combinations.erase({b, a});
        } else {
            combinations.erase({a, b});
        }
    }

    queue<pair<int, int>> futureGames;

    return 0;
}