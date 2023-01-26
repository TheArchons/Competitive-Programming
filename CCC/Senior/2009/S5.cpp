#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> area(30001, vector<int>(1001, 0));

void updateDiff(int x, int y, int bitrate) {
    if (x <= 0) x = 1;

    // check for out of bounds
    if (x > 30000 || y > 1000 || y <= 0) return;

    area[x][y] += bitrate;

    return;
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    //freopen("5.input", "r", stdin); // for testing
    
    int maxX, maxY;
    cin >> maxX >> maxY;

    int wirelessNum;
    cin >> wirelessNum;

    for (int i = 0; i < wirelessNum; i++) {
        int x, y, radius, bitrate;
        cin >> x >> y >> radius >> bitrate;

        // do left side top
        for (int posY = y + radius, posX = x; posY >= y; posY--, posX--) {
            updateDiff(posX, posY, bitrate);
        }


        // do left side bottom
        for (int posY = y - 1, posX = x - radius + 1; posY >= y - radius; posY--, posX++) {
            updateDiff(posX, posY, bitrate);
        }


        // do right side top
        for (int posY = y + radius, posX = x + 1; posY >= y; posY--, posX++) {
            updateDiff(posX, posY, bitrate * -1);
        }


        // do right side bottom
        for (int posY = y - 1, posX = x + radius; posY >= y - radius; posY--, posX--) {
            updateDiff(posX, posY, bitrate * -1);
        }
    }

    // find max
    int maxBitrate, maxCount, currBitrate;
    maxBitrate = maxCount = currBitrate = 0;

    for (int i = 1; i <= maxX; i++) {
        currBitrate = 0;
        for (int j = 1; j <= maxY; j++) {
            currBitrate += area[j][i];
            if (currBitrate > maxBitrate) {
                maxBitrate = currBitrate;
                maxCount = 1;
            } else if (currBitrate == maxBitrate) {
                maxCount++;
            }
        }
    }
    
    cout << maxBitrate << endl << maxCount << endl;

    return 0;
}