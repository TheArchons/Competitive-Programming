#include <stdio.h>

using namespace std;

int main() {
    int maxWeight, numCars;
    scanf("%d\n%d", &maxWeight, &numCars);

    int cars[numCars];
    for (int i = 0; i < numCars; i++) {
        scanf("%d", &cars[i]);
    }

    int carTotal = 0;
    for (int i = 0; i < 4 && i < numCars; i++) {
        carTotal += cars[i];
        if (carTotal > maxWeight) {
            printf("%d", i);
            return 0;
        }
    }

    if (numCars <= 4) {
        printf("%d", numCars);
        return 0;
    }

    for (int i = 4; i < numCars; i++) {
        carTotal += cars[i];
        carTotal -= cars[i - 4];
        if (carTotal > maxWeight) {
            printf("%d", i);
            return 0;
        }
    }

    printf("%d", numCars);
    return 0;
}