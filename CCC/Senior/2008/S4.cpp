#include <bits/stdc++.h>

using namespace std;

int maxScore;

void recurse(vector<int> cards, int currScore, int usedCount) {
    if (cards.empty()) {
        if (currScore <= 24) {
            maxScore = max(maxScore, currScore);
        }
        return;
    }

    for (int i = 0; i < cards.size(); i++) {
        int currCard = cards[i];
        vector<int> newCards;
        for (int j = 0; j < cards.size(); j++) {
            if (j != i) {
                newCards.push_back(cards[j]);
            }
        }

        recurse(newCards, currScore + currCard, usedCount + 1);
        recurse(newCards, currScore - currCard, usedCount + 1);
        if (usedCount) {
            recurse(newCards, currScore * currCard, usedCount + 1);
            if (currScore % currCard == 0) {
                recurse(newCards, currScore / currCard, usedCount + 1);
            }
        }
    }
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    freopen("4.input", "r", stdin); // for testing. Comment out for submissions

    int handNum; cin >> handNum;

    vector<vector<int>> cards(4, vector<int>(handNum));

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < handNum; j++) {
            cin >> cards[i][j];
        }
    }

    for (int i = 0; i < handNum; i++) {
        maxScore = 0;
        vector<int> currCards(4);
        for (int j = 0; j < 4; j++) {
            currCards[j] = cards[j][i];
        }
        recurse(currCards, 0, 0);

        cout << maxScore << endl;
    }

    return 0;
}