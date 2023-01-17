#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    freopen("3.input", "r", stdin); // for testing
    
    int notes, maxPitch, sampleNum;
    cin >> notes >> maxPitch >> sampleNum;

    vector<int> result(notes, 1);

    int currSamples = sampleNum - notes;
    if (currSamples < 0) {
        cout << "-1" << endl;
        return 0;
    }
    if (!currSamples) {
        for (int i = 0; i < notes; i++) {
            cout << result[i] << " ";
        }
        cout << endl;
        return 0;
    }

    int last = 0;

    for (int i = 1; i < notes && currSamples > 0; i += 2) {
        result[i] = 2;
        currSamples -= 2;
        if (i == notes - 1) {
            currSamples++;
        }
        last = i;
    }

    // end behaviour
    if (currSamples < -1 || currSamples > 0) {
        cout << "-1" << endl;
        return 0;
    }

    if (currSamples != 0) {
        // currSamples < 0
        // if even, impossible
        if (notes % 2 == 0) {
            cout << "-1" << endl;
            return 0;
        }
        // move the last sample to the end
        result[notes - 1] = 2;
        result[last] = 1;
    }

    for (int i = 0; i < notes; i++) {
        cout << result[i] << " ";
    }
    cout << endl;
    return 0;
}