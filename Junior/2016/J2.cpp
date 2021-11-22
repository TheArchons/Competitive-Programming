#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    int firstSum;
    for (int i = 0; i < 4; i++) {
        string temp = "";
        int prevLoc = 0, sum = 0;
        getline(cin, temp);
        for (int j = 0; j < temp.length(); j++) {
            string sub = "";
            if (temp[j] == ' ') {
                sub = temp.substr(prevLoc, j - prevLoc);
                prevLoc = j + 1;
                sum += stoi(sub);
            }
        }
        string sub = temp.substr(prevLoc, temp.length() - prevLoc);
        sum += stoi(sub);
        if (i == 0) {
            firstSum = sum;
        }
        else if (firstSum != sum){
            cout << "not magic\n";
            return 0;
        }
        //Make sure you account for the last int in the string
    }
    cout << "magic\n";
}