#include <iostream>
#include <string>
using namespace std;

int main() {
    int iCount, loops;
    string loopStr, temp;
    getline(cin, loopStr);
    loops = stoi(loopStr);
    string output[loops];
    for (int i = 0; i < loops; i++) {
        getline(cin, temp);
        int pos = temp.find(" ");
        iCount = stoi(temp.substr(0, pos));
        temp = temp.substr(pos + 1);
        for (int j = 1; j <= iCount; j++) {
            output[i] += temp;
        }
    }
    for (int i = 0; i < loops; i++) {
        cout << output[i] << endl;
    }
    return 0;
}