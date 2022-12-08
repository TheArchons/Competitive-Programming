#include <stdio.h>


int main() {
    int month, day;
    scanf("%d", &month);
    scanf("%d", &day);
    if (month == 1) {
        printf("Before");
        return 0;
    } 
    if (month != 2) {
        printf("After");
        return 0;
    }
    if (day < 18) {
        printf("Before");
        return 0;
    }
    if (day > 18) {
        printf("After");
        return 0;
    }
    printf("Special");
    return 0;
}