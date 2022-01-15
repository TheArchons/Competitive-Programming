#include <iostream>
#include <string>
using namespace std;

int main() {
    string input;
    cin >> input;
    int hour = stoi(input.substr(0, 2));
    int minute;
    //int minute = stoi(input.substr(3, 2));
    //dont forget to account for 23:59 and 00:60
    int distance = 0;
    for (minute = stoi(input.substr(3, 2)); distance < 120; minute += 20) {
        if (minute == 60) {
            minute = 0;
            hour++;
            if (hour == 24) {
                hour = 0;
            }
        }
        //halftime for rush hour
        if ((7 <= hour && hour < 10) || (15 <= hour && hour < 19)) {
            distance += 10;
        }
        else {
            distance += 20;
        }
    }
    //subtract extra distance
    int add = 120-distance;
    minute += add;
    //reverse minute
    if (minute < 0) {
        minute += 60;
        hour--;
    }
    //Final Convert
    if (minute == 60) {
        minute = 0;
        hour++;
        if (hour == 24) {
            hour = 0;
        }
    }
    string strHour;
    if (hour < 10) {
        strHour = "0" + to_string(hour);
    }
    else {
        strHour = to_string(hour);
    }
    string strMinute;
    if (minute < 10) {
        strMinute = "0" + to_string(minute);
    }
    else {
        strMinute = to_string(minute);
    }
    cout << strHour << ":" << strMinute << endl;
    return 0;
}