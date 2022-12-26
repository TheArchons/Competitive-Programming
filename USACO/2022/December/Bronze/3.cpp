#include <bits/stdc++.h>

using namespace std;

/*
1. for every line, compare with every other line with a different result
2. if the same value at the same index is the same, then it's a lie
*/

void testCase() {
    int valsPerLine, lineNum;
    cin >> valsPerLine >> lineNum;

    vector<vector<bool>> lines;
    vector<bool> results;

    for (int i = 0; i < lineNum; i++) {
        vector<bool> line;
        string temp;
        cin >> temp;
        
        for (int j = 0; j < valsPerLine; j++) {
            line.push_back(temp[j] == '1');
        }

        bool res;
        cin >> res;

        lines.push_back(line);
        results.push_back(res);
    }

    // check for duplicates
    map<int, bool> seen;
    for (int i = 0; i < lineNum; i++) {
        int hash = 0;
        for (int j = 0; j < valsPerLine; j++) {
            hash += lines[i][j] * pow(10, j);
        }

        if (seen.find(hash) != seen.end()) {
            if (seen[hash] != results[i]) {
                cout << "LIE" << endl;
                return;
            }
        } else {
            seen[hash] = results[i];
        }
    }

    // get the value for 00. By default, it's 0
    int zeroRes = 0;
    for (int i = 0; i < lineNum; i++) {
        int oneCount = 0;
        for (int j = 0; j < valsPerLine; j++) {
            if (lines[i][j]) {
                oneCount++;
            }
        }

        if (oneCount == 0) {
            zeroRes = results[i];
        }
    }
    
    // check if all 11 are valid
    for (int i = 0; i < lineNum; i++) {
        int oneCount = 0;
        for (int j = 0; j < valsPerLine; j++) {
            if (lines[i][j]) {
                oneCount++;
            }
        }

        if (oneCount == 2) {
            bool foundErr = false;

            set<int> seen;

            for (int j = 0; j < lineNum; j++) {
                // add to seen
                int hash = 0;
                for (int k = 0; k < valsPerLine; k++) {
                    if (lines[j][k]) {
                        hash += pow(10, k);
                    }
                }

                if (seen.find(hash) != seen.end()) {
                    continue;
                }

                seen.insert(hash);
                int oneCount = 0;
                for (int k = 0; k < valsPerLine; k++) {
                    if (lines[j][k]) {
                        oneCount++;
                    }
                }

                if (oneCount == 1) {
                    if (results[i] != results[j]) {
                        if (zeroRes == results[i] || foundErr) {
                            cout << "LIE" << endl;
                            return;
                        }
                        foundErr = true;
                    }
                }
            }
        }
    }

    cout << "OK" << endl;

    return;
}

int main() {
    //freopen("re.input", "r", stdin); // for testing
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    int testCases;
    cin >> testCases;

    for (int i = 0; i < testCases; i++) {
        testCase();
    }
}
