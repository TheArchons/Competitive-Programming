#include <iostream>
using namespace std;

int main() {
    int num, shifts, output, temp;
    cin >> num >> shifts;
    output = num;
    for (int i = 0; i < shifts; i++) {
        temp = num;
        for (int j = 0; j < i + 1; j++) {
            temp *= 10;
        }
        output += temp;
    }
    cout << output;
}