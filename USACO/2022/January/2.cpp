#include <bits/stdc++.h>

using namespace std;

bool possible = false;

int dice_beats_dice(int* dice_a, int* dice_b) {
    int suma, sumb;
    suma = sumb = 0;

    // calc sum of dice_a
    for (int i = 0; i < 4; i++) {
        int curr = dice_a[i];
        for (int j = 0; j < 4; j++) {
            if (dice_b[j] < curr) {
                suma++;
            }
        }
    }

    // calc sum of dice_b
    for (int i = 0; i < 4; i++) {
        int curr = dice_b[i];
        for (int j = 0; j < 4; j++) {
            if (dice_a[j] < curr) {
                sumb++;
            }
        }
    }

    if (suma > sumb) {
        return 1;
    } else if (sumb == suma) {
        return 2;
    } else {
        return 0;
    }
}

void generate(int* arr, int index, int (*die)[4]) {
    if (index == 4) {
        // return if any dice beats two other dice
        int AB, AC, BC, BA, CA, CB;
        AB = dice_beats_dice(die[0], die[1]);
        AC = dice_beats_dice(die[0], arr);
        BC = dice_beats_dice(die[1], arr);
        BA = dice_beats_dice(die[1], die[0]);
        CA = dice_beats_dice(arr, die[0]);
        CB = dice_beats_dice(arr, die[1]);

        // return if any of them = 2
        if (AB == 2 || AC == 2 || BC == 2 || BA == 2 || CA == 2 || CB == 2) {
            return;
        }

        if (AC & AB) {
            return;
        } else if (BC & BA) {
            return;
        } else if (CA & CB) {
            return;
        }

        // must be non-transitive
        possible = true;

        return;
    }

    for (int i = 1; i <= 10; i++) {
        arr[index] = i;
        generate(arr, index + 1, die);
    }

    return;
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    //freopen("2.input", "r", stdin); // For testing. Comment out for submissions

    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        int die[2][4];

        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 4; j++) {
                cin >> die[i][j];
            }
        }

        int arr[4];
        possible = false;
        generate(arr, 0, die);

        if (possible) {
            cout << "yes" << endl;
        } else {
            cout << "no" << endl;
        }
    }

    return 0;
}