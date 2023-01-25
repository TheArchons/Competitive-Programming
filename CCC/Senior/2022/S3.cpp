#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    //freopen("3.input", "r", stdin); // for testing
    
    int notes, maxPitch, sampleNum;
    cin >> notes >> maxPitch >> sampleNum;

    if (notes > sampleNum) {
        cout << "-1" << endl;
        return 0;
    }

    vector<int> pitches(notes, 1);
    int currSamples = notes;
    int regularMax = maxPitch - 1;
    int lastPitchLocation = 1;

    for (int i = 1; i < notes; i++) {
        int pitch;
        int wantedSamples = sampleNum - currSamples;
        if (!wantedSamples) break;
        lastPitchLocation = i;
        int prevPitch = pitches[i-1];
        if (i < maxPitch) {
            if (wantedSamples >= i) {
                pitch = i + 1;
                currSamples += pitch - 1;
            } else {
                pitch = i - wantedSamples;
                currSamples += wantedSamples;
            }
        } else {
            pitch = prevPitch >= maxPitch ? 1 : prevPitch + 1;
            if (wantedSamples < regularMax) {
                pitch += wantedSamples;
                currSamples += wantedSamples;
            } else {
                currSamples += regularMax;
            }
        }

        pitches[i] = pitch;
    }

    // set everything past lastPitchLocation to the last pitch
    for (int i = lastPitchLocation + 1; i < notes; i++) {
        pitches[i] = pitches[lastPitchLocation];
    }

    if (sampleNum != currSamples) {
        cout << "-1" << endl;
        return 0;
    }

    for (int i = 0; i < notes; i++) {
        cout << pitches[i] << " ";
    }

    cout << endl;

    return 0;
}