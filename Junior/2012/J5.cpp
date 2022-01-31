#include <iostream>
#include <vector>
#include <stack>
#include <string>
using namespace std;

bool isSorted(vector<string> &v) {
    for (int i = 0; i < v.size()-1; i++) {
        if (v[i].length() != 1 || v[i+1].length() != 1) {
            return false;
        }
        if (stoi(v[i]) > stoi(v[i+1])) {
            return false;
        }
    }
    return true;
}

bool vectorMatch(vector<string> &v1, vector<string> &v2) {
    for (int i = 0; i < v1.size(); i++) {
        if (v1[i] != v2[i]) {
            return false;
        }
    }
    return true;
}

bool vectorSearch(vector<vector<string>> &v, vector<string> &find) {
    for (int i = 0; i < size(v); i++) {
        if (vectorMatch(v[i], find)) {
            return true;
        }
    }
    return false;
}

int findMinStep(int len, vector<string> &coins) {
    vector<vector<vector<string>>> toSearch;
    toSearch.push_back(vector<vector<string>> {coins});
    vector<vector<string>> perms = toSearch.back();
    coins = perms.back();
    toSearch.pop_back();
    vector<vector<string>> visited;
    int steps = 0;
    while(true) {
        if (perms.empty()) {
            perms = toSearch.back();
            steps++;
            toSearch.pop_back();   
        }
        coins = perms.back();
        perms.pop_back();
        vector<vector<string>> newPerms;
        for (int i = 0; i < len; i++) {
            if (coins[i].length() == 0) {
                continue;
            }
            char tempChar = coins[i][0];
            coins[i] = coins[i].substr(1, coins[i].size()-1);
            if (i > 0 && vectorSearch(visited, coins)) {
                coins[i-1] = tempChar + coins[i-1];
                /*if (vectorSearch(visited, coins)) {
                    coins[i+1] = coins[i+1].substr(1, coins[i+1].size()-1);
                    continue;
                }*/
                newPerms.push_back(coins);
                visited.push_back(coins);
                if (isSorted(coins)) return steps;
                coins[i-1] = coins[i-1].substr(1, coins[i-1].size()-1);
            }
            if (i < len-1 && vectorSearch(visited, coins)) {
                coins[i+1] = tempChar + coins[i+1];
                /*if (vectorSearch(visited, coins)) {
                    coins[i-1] = coins[i-1].substr(1, coins[i-1].size()-1);
                    continue;
                }*/
                newPerms.push_back(coins);
                visited.push_back(coins);
                if (isSorted(coins)) return steps;
                coins[i+1] = coins[i+1].substr(1, coins[i+1].size()-1);
            }
            coins[i] = tempChar + coins[i];

        }
        if (!newPerms.empty()) {
            toSearch.push_back(newPerms);
        }
        /*else{
            return (-1);
        }*/
    }
    return (-1);
    printf("done");
}

int main() {
    while(true) {
        int len;
        vector<string> coins;
        scanf("%d", &len);
        if (len == 0) {
            break;
        }
        for (int i = 0; i < len; i++) {
            int coin;
            scanf("%d", &coin);
            coins.push_back(to_string(coin));
        }
        int print = findMinStep(len, coins);
        if (print == -1) {
            printf("IMPOSSIBLE\n");
        }
        else {
            printf("%d\n", print);
        }
    }
}