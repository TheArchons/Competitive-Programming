#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

int main() {
    string input, output;
    int prevSplit = 0, cityDist[4], timesAdded = 0, sumArr[5];;
    getline(cin, input);
    for (int i = 0; i < input.length(); i++) {
        if (input[i] == ' ') {
            cityDist[timesAdded] = stoi(input.substr(prevSplit, i - prevSplit));
            prevSplit = i;
            timesAdded++;
        }
    }
    cityDist[3] = stoi(input.substr(prevSplit, input.length()));
    sumArr[0] = 0;
    for (int i = 1; i < 5; i++) {
        sumArr[i] = cityDist[i-1] + sumArr[i - 1];
    }
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            output += to_string(abs(sumArr[j] - sumArr[i])) + " ";
        }
        cout << output << endl;
        output = "";
    }
    return 0;
}