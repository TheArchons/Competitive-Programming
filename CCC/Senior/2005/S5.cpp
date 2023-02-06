#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    //freopen("5.input", "r", stdin); // for testing. Comment out for submissions

    int gameNum; cin >> gameNum;

    multiset<int> scores;

    int total = 0;

    for (int i = 0; i < gameNum; i++) {
        int score; cin >> score;

        auto it = scores.upper_bound(score);
        
        total += distance(it, scores.end()) + 1;

        scores.insert(score);
    }

    float avg = (float) total / gameNum;

    cout << setprecision(2) << fixed << avg << endl;

    return 0;
}