#include <iostream>
using namespace std;

int isPrime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

int main() {
    int inputs;
    cin >> inputs;
    for (int i = 0; i < inputs; i++) {
        int input, output, out2 = 1;
        cin >> input;
        output = input*2;
        output = output-1;
        while (!isPrime(output) || !isPrime(out2)) {
            output--;
            out2++;
        }
        cout << out2 << " " << output << endl;
    }
}