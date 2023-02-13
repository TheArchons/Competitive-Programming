#include <bits/stdc++.h>

using namespace std;

int noteNum;
int maxPitch;
int goodSamples;

vector<int> notes;

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    //freopen("3.input", "r", stdin); // For testing. Comment out for submissions

    cin >> noteNum;
    cin >> maxPitch;
    cin >> goodSamples;

    notes.resize(noteNum, -1); // the first maxPitch notes are just for padding. Start at + maxPitch

    int currSamples = noteNum;

    if (goodSamples < currSamples) {
        cout << "-1\n";
        return 0;
    }

    int currNote;

    for (currNote = 0; currNote < maxPitch && currNote <= goodSamples - currSamples; currNote++) {
        notes[currNote] = currNote + 1;
        currSamples += currNote;
    }

    for (; currNote < noteNum && currSamples + maxPitch - 1 <= goodSamples; currNote++) {
        notes[currNote] = notes[currNote - maxPitch];
        currSamples += maxPitch - 1;
    }

    if (currNote < noteNum) {
        notes[currNote] = notes[currNote - (goodSamples - currSamples) - 1];
        currSamples = goodSamples;
        currNote++;
    }

    if (currSamples != goodSamples) {
        cout << "-1\n";
        return 0;
    }

    int lastNote = notes[currNote - 1];

    for (int i = 0; i < noteNum; i++) {
        if (notes[i] == -1) {
            notes[i] = lastNote;
        }

        cout << notes[i] << " ";
    }

    return 0;
}