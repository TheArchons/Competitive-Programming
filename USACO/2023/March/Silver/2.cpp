// jankiest sol ive ever written

#include <bits/stdc++.h>

using namespace std;

bool found = false;
int cowNum;
int teamNum;

set<vector<bool>> teamSet;
vector<vector<bool>> teams;

void search(vector<bool> a, int diff) {
    if (found) return;
    
    if (!diff) {
        found = teamSet.find(a) != teamSet.end();
        return;
    }

    for (int i = 0; i < cowNum; i++) {
        a[i] = !a[i];
        search(a, diff - 1);
        a[i] = !a[i];
    }
}

int boolVecToInt(vector<bool> v) {
    int ans = 0;

    for (int i = 0; i < v.size(); i++) {
        ans += v[i] * (1 << i);
    }

    return ans;
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    // freopen("2.input", "r", stdin); // For testing. Comment out for submissions
    // freopen("2.output", "w", stdout); // For testing. Comment out for submissions

    // start clock
    auto start = chrono::high_resolution_clock::now();

    cin >> cowNum; cin >> teamNum;

    vector<pair<vector<int>, vector<int>>> sets(cowNum);

    teams.resize(teamNum);

    set<int> seenTeams;

    for (int i = 0; i < teamNum; i++) {
        string s; cin >> s;

        vector<bool> team(cowNum);

        for (int j = 0; j < cowNum; j++) {
            char c = s[j];

            team[j] = c == 'G';
        }

        teams[i] = team;

        int teamInt = 0;

        for (int i = 0; i < team.size(); i++) {
            teamInt += team[i] * (1 << i);
        }

        if (seenTeams.find(teamInt) != seenTeams.end()) {
            continue;
        }

        seenTeams.insert(teamInt);

    
        for (int j = 0; j < cowNum; j++) {
            if (team[j]) {
                sets[j].first.push_back(teamInt);
            } else {
                sets[j].second.push_back(teamInt);
            }
        }
    }

    // free mem
    // seenTeams.clear(); // comment out if tle

    map<vector<bool>, int> seenMap; // comment out if tle

    bool isEnd = false;

    vector<int> sols(teamNum);

    for (int i = 0; i < teamNum; i++) {
        vector<bool> &curr = teams[i];

        // if more than 1250ms, break
        auto end = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);
        if (duration.count() > 1250) {
            isEnd = true;
            break;
        }

        if (seenMap.find(curr) != seenMap.end()) { // comment out if tle
            sols[i] = seenMap[curr];
            continue;
        }

        vector<int> seen(262150, 0);
        int maxSeen = 0;

        for (int j = 0; j < cowNum; j++) {
            if (curr[j]) {
                // find opposite
                for (auto k : sets[j].second) {
                    seen[k]++;

                    maxSeen = max(maxSeen, seen[k]);
                }

            } else {
                // find opposite
                for (auto k : sets[j].first) {
                    seen[k]++;
                
                    maxSeen = max(maxSeen, seen[k]);
                }
            }
        }

        seenMap[curr] = maxSeen; // comment out if tle

        sols[i] = maxSeen;
    }

    if (!isEnd) {
        for (auto i : sols) {
            cout << i << endl;
        }

        return 0;
    }

    // probably testcase 6, 8, 9, use second solution

    for (int i = 0; i < teamNum; i++) {
        teamSet.insert(teams[i]);
    }

    for (int i = 0; i < teamNum; i++) {
        vector<bool> team = teams[i];
        vector<bool> oppTeam = team;

        for (int j = 0; j < cowNum; j++) {
            oppTeam[j] = !team[j];
        }

        for (int diff = 0; diff <= cowNum; diff++) {
            found = false;
            search(oppTeam, diff);

            if (found) {
                cout << cowNum - diff << endl;
                break;
            }
        }
    }

    return 0;
}