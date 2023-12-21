#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    // freopen("CourseSchedule.input", "r", stdin); // For testing. Comment out for submissions

    int courseNum; cin >> courseNum;
    int requirementNum; cin >> requirementNum;

    vector<vector<int>> requirements(courseNum);

    for (int i = 0; i < requirementNum; i++) {
        int a; cin >> a; int b; cin >> b; a--; b--;

        requirements[a].push_back(b);
    }

    vector<int> state(courseNum, 0);
    // 0 - not visited
    // 1 - visited once
    // 2 - all children visited

    vector<int> result;

    for (int i = 0; i < courseNum; i++) {
        if (state[i]) {
            continue;
        }

        stack<int> prev;

        prev.push(i);

        state[i] = 1;

         while (!prev.empty()) {
            int curr = prev.top();
            bool found = false;

            for (int j = 0; j < requirements[curr].size(); j++) {
                int next = requirements[curr][j];

                if (state[next] == 1) {
                    // contains a cycle
                    cout << "IMPOSSIBLE" << endl;
                    return 0;
                }

                if (state[next] == 0) {
                    found = true;
                    prev.push(next);
                    state[next] = 1;
                    break;
                }
            }

            if (!found) {
                result.push_back(curr + 1);
                state[curr] = 2;
                prev.pop();
            }
        }
    }

    // print result in reverse
    for (int i = 0; i < courseNum; i++) {
        cout << result[courseNum - i - 1] << endl;
    }

    return 0;
}