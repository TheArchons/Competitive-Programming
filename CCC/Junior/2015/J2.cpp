#include <stdio.h>
#include <iostream>
#include <string>

int main() {
    std::string text;
    int happies = 0, sads = 0;
    getline(std::cin, text);
    for (int i = 2; i < text.length(); i++) {
        if (text[i] == ')' && text[i-1] == '-' && text[i-2] == ':') {
            happies++;
        }
        else if (text[i] == '(' && text[i-1] == '-' && text[i-2] == ':') {
            sads++;
        }
    }
    if (happies == 0 && sads == 0) {
        printf("none");
        return 0;
    }
    if (happies > sads) {
        printf("happy");
    }
    else if (happies < sads) {
        printf("sad");
    }
    else {
        printf("%s", "unsure");
    }
    return 0;
}