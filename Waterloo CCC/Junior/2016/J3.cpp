#include <stdio.h>
#include <string>
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

/*int size(char *ptr) {
    int offset, count;
    offset = count = 0;
    while (ptr[count + offset] != '\0') {
        offset++;
        count++;
    }
    return count;
}*/

char reverse(char ptr[]) {
    char temp;
    for(int i = 0; i < sizeof(ptr); i++) {
        temp = ptr[i];
        ptr[i] = ptr[-i];
        ptr[-i] = temp;
    }
}

char SubStr(char ptr[], int start, int end) {
    char temp[end-start];
    for(int i = start; i <= end; i++) {
        temp[i-start] = ptr[i];
    }
    ptr = temp;
}

main() {
    char input[] = "";
    int maxPali, pali = 0;
    scanf("%s", input);
    for (int i = 0; i < sizeof(input); i++) {
        for (int j = i; j > 0; j--) {
            char subStr[] = SubStr(input, j, i);
            if (reverse(subStr) == subStr) {
                printf("%s\n", subStr);
            }
        }
    }
}