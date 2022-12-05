#include <iostream>
using namespace std;

int main() {
    int temperature;
    cin >> temperature;
    temperature = (temperature*5)-400;
    cout << temperature << endl;
    if (temperature == 100) {
        cout << 0;
        return 0;
    }
    else if (temperature > 100) {
        cout << -1;
        return 0;
    }
    else {
        cout << 1;
        return 0;
    }
}