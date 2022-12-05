#include <iostream>
#include <string>
using namespace std;

int main() {
    int inputs, maxBid = 0;
    string maxBidder;
    cin >> inputs;
    for (int i = 0; i < inputs; i++) {
        string name;
        int price;
        cin >> name >> price;
        if (price > maxBid) {
            maxBid = price;
            maxBidder = name;
        }
    }
    cout << maxBidder << endl;
    return 0;
}