#include <stdio.h>
#include <vector>
#include <algorithm>


using namespace std;

int main() {
    int len;
    vector<int> villages;
    scanf("%d", &len);
    for (int i = 0; i < len; i++) {
        int temp;
        scanf("%d", &temp);
        villages.push_back(temp);
    }
    //sort
    sort(villages.begin(), villages.begin()+len);
    int prev, prevTotal;
    float prevArea, min;
    prevTotal = 0;
    min = prev = -1;
    for (int i : villages) {
        if (prev == -1) {
            prev = i;
            prevArea = 0;
            continue;
        }
        float area = prevArea + ((i - prev)/2);
        
        if (prevArea == 0) {
            prevArea = area-prevArea;
            continue;
        }
        prevArea = area-prevArea;
        if (min == -1 || (area-prevTotal < min && area-prevTotal > 0)) {
            min = area-prevTotal;
        }
        prevTotal += area-prevTotal;
    }
    //1 decimal
    printf("%.1f\n", min);
    return 0;
}