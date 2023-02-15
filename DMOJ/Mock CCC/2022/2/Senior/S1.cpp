#include <bits/stdc++.h>

using namespace std;

vector<vector<bool>> exams;
int studentNum, examLen;
int maxMin = 0;

void recurse(vector<bool> ans, int curr) {
    if (curr == examLen) {
        int minVal = INT_MAX;
        for (int i = 0; i < studentNum; i++) {
            int count = 0;
            for (int j = 0; j < examLen; j++) {
                if (ans[j] == exams[i][j]) {
                    count++;
                }
            }

            if (count < minVal) {
                minVal = count;
            }
        }

        if (minVal > maxMin) {
            maxMin = minVal;
        }

        return;
    }

    recurse(ans, curr + 1);
    ans[curr] = !ans[curr];
    recurse(ans, curr + 1);

    return;
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    //freopen("1.input", "r", stdin); // for testing

    cin >> studentNum >> examLen;

    exams.resize(studentNum, vector<bool>(examLen));
    for (int i = 0; i < studentNum; i++) {
        for (int j = 0; j < examLen; j++) {
            char c;
            cin >> c;
            exams[i][j] = c == 'T';
        }
    }

    vector<bool> ans(examLen, true);

    recurse(ans, 0);

    cout << maxMin << endl;

    return 0;
}