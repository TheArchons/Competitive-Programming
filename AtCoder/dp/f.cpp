#include <bits/stdc++.h>

using namespace std;

bool isEnd = false;

vector<vector<int>> dp;

string firstStr, secondStr;
int firstLen, secondLen;

void dfs(int i, int j, vector<char> &currStr) {
    if (isEnd) return;

    if (i == firstLen && j == secondLen && dp[i][j] == currStr.size()) {
        for (char c : currStr) {
            cout << c;
        }
        cout << endl;
        isEnd = true;
        return;
    }

    if (firstStr[i] == secondStr[j]) {
        currStr.push_back(firstStr[i]);
        dfs(i + 1, j + 1, currStr);
        currStr.pop_back();
    }

    if (i + 1 <= firstLen) {
        dfs(i + 1, j, currStr);
    }

    if (j + 1 <= secondLen) {
        dfs(i, j + 1, currStr);
    }

    return;
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    //freopen("f.input", "r", stdin); // for testing

    cin >> firstStr >> secondStr;

    firstLen = firstStr.length();
    secondLen = secondStr.length();

    dp.resize(firstLen + 1, vector<int>(secondLen + 1, 0));
    for (int i = 1; i <= firstLen; i++) {
        for (int j = 1; j <= secondLen; j++) {
            if (firstStr[i - 1] == secondStr[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    vector<char> currStr;
    dfs(0, 0, currStr);

    return 0;
}