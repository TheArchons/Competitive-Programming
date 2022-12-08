#include <iostream>
using namespace std;

int main() {
    int lines, total = 0;
    scanf("%d\n", &lines);
    char answers[lines];
    for (int i = 0; i < lines; i++) {
        scanf("%c\n", &answers[i]);
    }
    for (int i = 0; i < lines; i++) {
        char temp;
        scanf("%c\n", &temp);
        if (answers[i] == temp) {
            total++;
        }
    }
    //scanf("%c");
    printf("%d", total);
}