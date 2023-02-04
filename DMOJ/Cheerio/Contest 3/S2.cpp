#include <bits/stdc++.h>

using namespace std;

/*
1. if you opponent is shooting and they have ammo, block
2. if you have ammo and your opponent is not blocking, shoot
3. reload
*/

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    //freopen("2.input", "r", stdin); // for testing. Comment out for submissions

    int actionNum; cin >> actionNum;

    vector<char> actions(actionNum);

    for (int i = 0; i < actionNum; i++) {
        char c; cin >> c;

        actions[i] = c;
    }

    int yourAmmo = 0;
    int oppAmmo = 0;

    int yourScore = 0;

    for (int i = 0; i < actionNum; i++) {
        char curr = actions[i];

        if (curr == 'F') {
            if (oppAmmo > 0) {
                oppAmmo--;
            } else {
                if (yourAmmo > 0) {
                    yourAmmo--;
                    yourScore++;
                } else {
                    yourAmmo = 1;
                }
            }
        } else if (curr == 'B') {
            yourAmmo++;
        } else {
            oppAmmo++;
            if (yourAmmo > 0) {
                yourAmmo--;
                yourScore++;
            } else {
                yourAmmo = 1;
            }
        }
    }

    cout << yourScore << "\n";

    return 0;
}