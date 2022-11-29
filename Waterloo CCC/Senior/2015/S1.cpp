#include <stdio.h>
#include <stack>

using namespace std;

int main() {
    int numbers;
    scanf("%d", &numbers);

    stack<int> prevNumbers;
    int sum = 0;
    for (int i = 0; i < numbers; i++) {
        int number;
        scanf("%d", &number);
        if (number == 0) {
            sum -= prevNumbers.top();
            prevNumbers.pop();
        } else {
            sum += number;
            prevNumbers.push(number);
        }
    }

    printf("%d", sum);
}