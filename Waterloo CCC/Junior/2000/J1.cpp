#include <iostream>

using namespace std;

int main() {
    int startDay, days;
    scanf("%d %d", &startDay, &days);
    printf("Sun Mon Tue Wed Thr Fri Sat\n");//days of the week starting with sunday
    for (int i = 0; i < startDay-1; i++) {
        printf("    ");
    }
    for (int i = 0; i < days; i++) {
        printf("%3d ", i + 1);
        if ((i + startDay) % 7 == 0) {
            printf("\n");
        }
    }
    printf("\n");
}