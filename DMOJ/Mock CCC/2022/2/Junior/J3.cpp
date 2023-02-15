#include <iostream>

using namespace std;

int main() {
    int lines, left, right;
    bool isOdd = false;
    left = right = 0;
    scanf("%d", &lines);
    int scores[lines];
    for (int i = 0; i < lines; i++) {
        scanf("%d", &scores[i]);
    }
    if (lines == 1) {
        printf("Andrew is sad.\n");
        return 0;
    }
    for (int i = 0; i < lines/2; i++) {
        left += scores[i];
        right += scores[lines - i - 1];
    }
    //add middle if odd
    int pos = (lines/2);
    if (lines % 2 == 1) {
        left += scores[lines/2];
        isOdd = true;
        pos++;
    }
    
    bool wentLeft, wentRight;
    wentLeft = wentRight = false;
    while (left != right) {
        if (left > right) {
            if (wentRight) {
                printf("Andrew is sad.\n");
                return 0;
            }
            wentLeft = true;
            left -= scores[pos-1];
            right += scores[pos-1];
            pos -= 1;
        }
        else {
            if (wentLeft) {
                printf("Andrew is sad.\n");
                return 0;
            }
            wentRight = true;
            left += scores[pos];
            right -= scores[pos];
            pos += 1;
        }
    }
    printf("%d\n", pos);
    return 0;
}