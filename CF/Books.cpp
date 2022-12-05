//https://codeforces.com/contest/279/problem/B

#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

int main() {
    int number_of_books, time;
    scanf("%d %d", &number_of_books, &time);

    int books[number_of_books]; int sum = 0;
    for (int i = 0; i < number_of_books; i++) {
        scanf("%d", &books[i]);
        sum += books[i];
    }

    int max_books = 0;

    int left; int right; int curr_sum;
    curr_sum = left = right = 0;

    while (right < number_of_books) {
        if (curr_sum + books[right] <= time) {
            curr_sum += books[right];
            right++;
            max_books = max(max_books, right - left);
        } else {
            curr_sum -= books[left];
            left++;
        }
    }

    if (curr_sum <= time) {
        max_books = max(max_books, right - left);
    }

    printf("%d", max_books);
}