#include <bits/stdc++.h>

using namespace std;

const int unknown = 1000001;

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    //freopen("3.input", "r", stdin); // for testing
    
    vector<vector<int>> square(3, vector<int>(3, unknown));

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            string temp;
            cin >> temp;
            if (temp != "X") {
                square[i][j] = stoi(temp);
            }
        }
    }

    // fill in guaranteed values
    
    // rows
    for (int i = 0; i < 3; i++) {
        int one, two, three;
        one = square[i][0];
        two = square[i][1];
        three = square[i][2];

        if (one != unknown && two != unknown && three == unknown) {
            square[i][2] = two + (two - one);
        } else if (one != unknown && two == unknown && three != unknown) {
            square[i][1] = one + (three - one) / 2;
        } else if (one == unknown && two != unknown && three != unknown) {
            square[i][0] = two - (three - two);
        }
    }

    // columns
    for (int i = 0; i < 3; i++) {
        int one, two, three;
        one = square[0][i];
        two = square[1][i];
        three = square[2][i];

        if (one != unknown && two != unknown && three == unknown) {
            square[2][i] = two + (two - one);
        } else if (one != unknown && two == unknown && three != unknown) {
            square[1][i] = one + (three - one) / 2;
        } else if (one == unknown && two != unknown && three != unknown) {
            square[0][i] = two - (three - two);
        }
    }

    // print square
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << square[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}