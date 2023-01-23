#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    //freopen("1.input", "r", stdin); // for testing
    
    set<int> cubes;
    set<int> squares;

    for (int i = 0; i < 100001; i++) {
        cubes.insert(pow(i, 3));
        squares.insert(pow(i, 2));
    }

    set<int> squareAndCube;
    for (int cube : cubes) {
        if (squares.find(cube) != squares.end()) {
            squareAndCube.insert(cube);
        }
    }

    int lower, upper, total = 0;
    cin >> lower >> upper;
    for (auto i = squareAndCube.lower_bound(lower); *i <= upper; i++) {
        total++;
    }

    cout << total << endl;

    return 0;
}