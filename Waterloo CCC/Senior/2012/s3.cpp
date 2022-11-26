#include <stdio.h>
#include <map>
#include <math.h>
#include <unordered_set>

using namespace std;

int main() {
    int sensorNum;
    scanf("%d", &sensorNum);
    
    int max1, max2, min1, min2, freq1, freq2;
    max1 = max2 = 2000001;
    min1 = min2 = -2000001;
    freq1 = freq2 = 0;
    map<int, int> sensors;
    unordered_set<int> maxVals;

    for (int i = 0; i < sensorNum; i++) {
        int sensor;
        scanf("%d", &sensor);
        sensors[sensor]++;
        if (sensors[sensor] > freq1) {
            freq2 = freq1;
            max2 = max1;
            min2 = min1;
            freq1 = sensors[sensor];
            max1 = min1 = sensor;
            maxVals.clear();
            maxVals.insert(sensor);
        } else if (sensors[sensor] == freq1) {
            maxVals.insert(sensor);
            if (sensor > max1) {
                max1 = sensor;
            } else if (sensor < min1) {
                min1 = sensor;
            }
        } else if (sensors[sensor] > freq2) {
            freq2 = sensors[sensor];
            max2 = min2 = sensor;
        } else if (sensors[sensor] == freq2) {
            if (sensor > max2) {
                max2 = sensor;
            } else if (sensor < min2) {
                min2 = sensor;
            }
        }
    }
    if (max2 == 2000001) {
        max2 = max1;
        min2 = min1;
    }
    printf("%d", max(abs(max1 - min2), abs(max2 - min1)));
}