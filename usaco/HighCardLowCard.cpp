#include <stdio.h>
#include <set>
#include <unordered_set>

using namespace std;

int main() {
    freopen("cardgame.in", "r", stdin); freopen("cardgame.out", "w", stdout);
    int n;
    scanf("%d", &n);

    int opponentCards[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &opponentCards[i]);
    }

    set<int> cards;
    for (int i = 1; i <= 2 * n; i++) {
        cards.insert(i);
    }

    for (int i = 0; i < n; i++) {
        cards.erase(opponentCards[i]);
    }

    int points = 0;
    const int half = n / 2;
    for (int i = n; i > 0; i--) {
        if (i > half) {
            auto it = cards.upper_bound(opponentCards[i - 1]);
            it--;
            if (it != cards.end()) {
                points++;
                cards.erase(it);
            }
        }
        else {
            auto it = cards.lower_bound(opponentCards[i - 1]);
            if (it != cards.end()) {
                points++;
                cards.erase(it);
            }
        }
    }

    printf("%d", points);
    
}