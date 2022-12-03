#include <stdio.h>
#include <set>
#include <queue>

using namespace std;

int totalWins = 0;

void calculateCombination(int gamesPlayed, int favorite, set<pair<int, int>> combinations, vector<int> teamScores) {
    if (gamesPlayed == 6) { // all games have been played
        for (int i = 0; i < 4; i++) {
            if (i == favorite) continue;
            if (teamScores[i] > teamScores[favorite]) return;
        }
        totalWins++;
        return;
    }

    for (set<pair<int, int>>::iterator it = combinations.begin(); it != combinations.end(); it++) {
        pair<int, int> game = *it;

        combinations.erase(it);

        teamScores[game.first]++;
        teamScores[game.second]++;
        calculateCombination(gamesPlayed + 1, favorite, combinations, teamScores);

        teamScores[game.first] += 2;
        teamScores[game.second]--;
        calculateCombination(gamesPlayed + 1, favorite, combinations, teamScores);

        teamScores[game.first] -= 2;
        teamScores[game.second] += 3;
        calculateCombination(gamesPlayed + 1, favorite, combinations, teamScores);

        combinations.insert(game);
    }

    return;
}

int main() {
    set<pair<int, int>> combinations;
    for (int i = 0; i < 4; i++) {
        for (int j = i+1; j < 4; j++) {
            combinations.insert({i, j});
        }
    }

    int favorite, gamesPlayed;
    scanf("%d %d", &favorite, &gamesPlayed);
    favorite--;

    vector<int> teamScores;
    for (int i = 0; i < 4; i++) {
        teamScores.push_back(0);
    }

    for (int i = 0; i < gamesPlayed; i++) {
        int a, b, aScore, bScore;
        scanf("%d %d %d %d", &a, &b, &aScore, &bScore);
        a--; b--;

        if (aScore > bScore) {
            teamScores[a] += 3;
        } else if (bScore > aScore) {
            teamScores[b] += 3;
        } else {
            teamScores[a] += 1;
            teamScores[b] += 1;
        }

        if (a > b) {
            combinations.erase({b, a});
        } else {
            combinations.erase({a, b});
        }
    }

    calculateCombination(gamesPlayed, favorite, combinations, teamScores);
    printf("%d", totalWins);

    return 0;
}