#include <bits/stdc++.h>

using namespace std;

int charToInt(char c) {
    if (c >= 'a') {
        return c - 'a' + 26;
    } else {
        return c - 'A';
    }
}

void solve() {
    string startStr; cin >> startStr;
    string endStr; cin >> endStr;

    int strLen = startStr.length();

    vector<char> graph(52, '.');

    int total = 0;

    for (int i = 0; i < strLen; i++) {
        char curr = startStr[i];
        int currInt = charToInt(curr);

        char endCurr = endStr[i];

        char currGraph = graph[currInt];

        if (currGraph == '.') {
            graph[currInt] = endCurr;
            if (curr != endCurr) {
                total++;
            }
        } else if (currGraph != endCurr) {
            cout << -1 << endl;
            return;
        }
    }

    bool usedAll = false;

    if (startStr != endStr) {
        vector<bool> visited(52, false);
        int uniqueCount = 0;

        for (int i = 0; i < strLen; i++) {
            if (!visited[i]) {
                uniqueCount++;
                visited[i] = true;
            }
        }

        usedAll = uniqueCount >= 52;
    }

    // if usedAll and has loop, impossible

    // loop detection
    bool foundLoop = false;
    for (int i = 0; i < 52; i++) {
        vector<bool> visitedNodes(52, false);
        queue<char> q;
        // add to queue
        if (i < 26) {
            q.push('A' + i);
        } else {
            q.push('a' + i - 26);
        }

        while (!q.empty()) {
            char curr = q.front();
            q.pop();

            int currInt = charToInt(curr);
            char next = graph[currInt];

            if (visitedNodes[currInt] && next != curr) {
                foundLoop = true;
                total++;
                graph[currInt] = '.'; // remove loop
                break;
            }

            visitedNodes[currInt] = true;

            if (next != '.' && next != curr) {
                q.push(next);
            }
        }
    }

    if (usedAll && foundLoop) {
        cout << -1 << endl;
        return;
    }

    cout << total << endl;

    return;
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    //freopen("1.input", "r", stdin); // for testing. Comment out for submissions

    int testCases; cin >> testCases;

    while (testCases--) {
        solve();
    }

    return 0;
}