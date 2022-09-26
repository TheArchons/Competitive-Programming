#include <iostream>
using namespace std;

int main() {
    int time, addable;
    cin >> time;
    addable = 0;
    int loopCount = time/720;
    addable += loopCount * 31;//adds 31 everytime the clock passes 12 hours
    time -= 720*loopCount;
    int hour = time / 60;
    while (hour >= 0) { //adds the hours for the last 12 hours
        if (hour < 10) {
            if (hour == 0) { //adds the first hour if it is over 34 minutes (12:34)
                if (time >= 34) {
                    addable++;
                }
                break;
            }
            for (int testAdd = (hour*-1) + 1; 0 <= testAdd+hour && testAdd + hour <= 6; testAdd++) { //loops through possible differences
                if (testAdd + hour + testAdd < 10 && testAdd + hour + testAdd >= 0 && hour != time/60) { //tests if the difference is valid for the second value
                    if (testAdd + hour == 6 && testAdd+hour+testAdd != 0) {
                        continue;
                    }
                    addable += 1;
                }
                else if(testAdd + hour + testAdd < 10 && testAdd + hour + testAdd >= 0 && hour == time/60 && (testAdd+hour)*10 + (testAdd+testAdd+hour) <= (time - (hour*60)) )  { //unique test for the first hour
                    addable += 1;
                }
            }
        }
        else if(hour == 11 && time >= 671) {
            addable += 1;
        }
        hour--;
    }
    cout << addable;
    return 0;
}