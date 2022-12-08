#include <stdio.h>
#include <iostream>
#include <string>
#include <limits>
using namespace std;

int main() {
    unsigned int loops = 0, time = 0, timeDiff;
    float maxSpeed = 0.0;
    string temp = "", loopStr;
    getline(cin, loopStr);
    loops = stoi(loopStr);
    int distance, timeAndPosition[loops][2], posDiff;
    //splits input into array of ints (timeAndPosition)
    for (int i = 0; i < loops; i++) {
        getline(cin, temp);
        time = stoul(temp.substr(0, temp.find(' ')));
        distance = stoul(temp.substr(temp.find(' '), temp.length()));
        timeAndPosition[i][0] = time; timeAndPosition[i][1] = distance;
    }
    //perform time calcs compared to the next 
    for (int i = 0; i < loops; i++) {
        int closestTime = numeric_limits<int>::max();
        int closestTimeIndex = 0;
        for (int j = 0; j < loops; j++) {
            if (timeAndPosition[j][0] < closestTime && timeAndPosition[j][0] > timeAndPosition[i][0]) {
                closestTime = timeAndPosition[j][0];
                closestTimeIndex = j;
            }
        }
        timeDiff = timeAndPosition[closestTimeIndex][0] - timeAndPosition[i][0];
        posDiff = abs(timeAndPosition[closestTimeIndex][1] - timeAndPosition[i][1]);
        
        if ((float) posDiff/ (float) timeDiff > maxSpeed) {
            maxSpeed = (float) posDiff/ (float) timeDiff;
        }
    }
    printf("%.2f", maxSpeed);
}

/* 
    [0, 100]
    [20,50]
    [10, 120]
Sort by 1st num
    [0, 100]
    [10, 120]
    [20, 50]
abs(num[2][2] - num[1][2]) / abs(num[2][1] - num[1][1])

120-100 = 20
10 - 0 = 10
20/10 = 2

-120 - -100 = 20
-10 - 0 = 10
20/10 = 2
*/