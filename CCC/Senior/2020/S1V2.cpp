#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int steps;
    scanf("%d", &steps);
    pair<int, int> measurements[steps];
    for (int i = 0; i < steps; i++) {
        scanf("%d %d", &measurements[i].first, &measurements[i].second);
    }
    //sort measurements
    sort(measurements, measurements+steps);
    float max = 0;
    for (int i = 1; i < steps; i++) {
        int timeDiff = measurements[i].first - measurements[i-1].first; //time difference
        int distanceDiff = abs(measurements[i].second - measurements[i-1].second); //distance difference
        float speed = float(distanceDiff) / float(timeDiff); //speed
        if (speed > max) {
            max = speed;
        }
    }
    printf("%f\n", max);
    return 0;
}