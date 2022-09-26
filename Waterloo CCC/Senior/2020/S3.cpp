#include <iostream>
#include <string>
#include <map>
#include <set>

using namespace std;

bool isPerm(map<char, int>& m1, map<char, int>& m2) {
    for (int i = 0; i < 26; i++) {
        char letter = 'a' + i;
        if (m1[letter] != m2[letter]) {
            return false;
        }
    }
    return true;
}

int main() {
    string needle, haystack;
    cin >> needle >> haystack;
    int needle_size = needle.size();
    int haystack_size = haystack.size();

    int count = 0;

    if (needle_size > haystack_size) { // if needle is bigger than haystack, no need to search
        cout << 0 << endl;
        return 0;
    }

    map<char, int> needle_map;
    map<char, int> haystack_map;

    // add all letters of the alphabet to the map
    for (int i = 0; i < 26; i++) {
        needle_map[(char)('a' + i)] = 0;
        haystack_map[(char)('a' + i)] = 0;
    }

    // calculate the frequency of each letter in the needle
    for (int i = 0; i < needle_size; i++) {
        needle_map[needle[i]]++;
    }

    // calculate the frequency of the first needle_size letters of the haystack
    for (int i = 0; i < needle_size; i++) {
        haystack_map[haystack[i]]++;
    }

    set<size_t> found_positions;
    hash<string> str_hash;

    // check if the frequency of the first needle_size letters of the haystack is equal to the frequency of the needle
    if (needle_map == haystack_map) {
        found_positions.insert(str_hash(haystack.substr(0, needle_size)));
        count++;
    }

    // sliding window to check if the frequency of the next letters of the haystack is equal to the frequency of the needle
    for (int i = needle_size; i < haystack_size; i++) {
        haystack_map[haystack[i]]++;
        haystack_map[haystack[i - needle_size]]--;
        if (isPerm(needle_map, haystack_map) && found_positions.find(str_hash(haystack.substr(i - needle_size + 1, needle_size))) == found_positions.end()) {
            found_positions.insert(str_hash(haystack.substr(i - needle_size + 1, needle_size)));
            count++;
        }
    }

    cout << count << endl;
}