#include <iostream>
#include <string>
#include <unordered_map>
#include <limits>

using namespace std;

int main() {
    int s1Len, s2Len;
    scanf("%d %d", &s1Len, &s2Len);
    string s1, s2;
    cin >> s1 >> s2;
    unordered_map<char, int> s1Map;
    int total, max;
    max = total = 0;
    for (char c : s1) {
        s1Map[c]++;
        if (s1Map[c] > max) {
            max = s1Map[c];
        }
    }
    for (char c : s2) {
        total += s1Map[c];
    }
    int min = numeric_limits<int>::max();
    for (char c : s2) {
        if (s1Map[c] < min) {
            min = s1Map[c];
        }
    }
    total += max-min;
    printf("%d\n", total);
}