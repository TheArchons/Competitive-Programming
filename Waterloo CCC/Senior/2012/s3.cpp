#include <stdio.h>
#include <map>
#include <math.h>
#include <algorithm>
#include <unordered_map>

using namespace std;

int main() {
    int sensorNum;
    scanf("%d", &sensorNum);

    unordered_map<int, int> sensorMap;
    
    for(int i = 0; i < sensorNum; i++) {
        int sensor;
        scanf("%d", &sensor);
        sensorMap[sensor]++;
    }

    int maxFreq, secondMaxFreq;
    maxFreq = secondMaxFreq = 0;
    for (auto it = sensorMap.begin(); it != sensorMap.end(); it++) {
        if (it->second > maxFreq) {
            secondMaxFreq = maxFreq;
            maxFreq = it->second;
        } else if (it->second > secondMaxFreq) {
            secondMaxFreq = it->second;
        }
    }

    int maxFreqSensor, secondMaxFreqSensor, minFreqSensor, secondMinFreqSensor;
    maxFreqSensor = secondMaxFreqSensor = -20000001;
    minFreqSensor = secondMinFreqSensor = 20000001;

    for (auto it = sensorMap.begin(); it != sensorMap.end(); it++) {
        if (it->second == maxFreq) {
            maxFreqSensor = max(maxFreqSensor, it->first);
            minFreqSensor = min(minFreqSensor, it->first);
        }
        else if (it->second == secondMaxFreq) {
            secondMaxFreqSensor = max(secondMaxFreqSensor, it->first);
            secondMinFreqSensor = min(secondMinFreqSensor, it->first);
        }
    }

    printf("%d", max(abs(maxFreqSensor - secondMinFreqSensor), abs(secondMaxFreqSensor - minFreqSensor)));
}