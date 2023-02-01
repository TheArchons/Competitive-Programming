#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    //freopen("1.input", "r", stdin); // for testing. Comment out for submissions

    int minTemp = INT_MAX; string minCity = "";

    while (true) {
        string cityName; cin >> cityName;

        int temperature; cin >> temperature;

        if (temperature < minTemp) {
            minTemp = temperature;
            minCity = cityName;
        }

        if (cityName == "Waterloo") break;
    }

    cout << minCity << endl;

    return 0;
}