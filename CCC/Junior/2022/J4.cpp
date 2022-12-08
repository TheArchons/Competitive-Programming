#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

int main() {
    unordered_map<string, vector<string>> sameGroup;
    int pairs;
    int violations = 0;
    scanf("%d", &pairs);
    for (int i = 0; i < pairs; i++) {
        string a, b;
        cin >> a >> b;
        sameGroup[a].push_back(b);
        //sameGroup[b].push_back(a);
    }

    unordered_map<string, vector<string>> diffGroups;
    scanf("%d", &pairs);
    for (int i = 0; i < pairs; i++) {
        string a, b;
        cin >> a >> b;
        diffGroups[a].push_back(b);
        //diffGroups[b].push_back(a);
    }

    scanf("%d", &pairs);
    for (int i = 0; i < pairs; i++) {
        unordered_set<string> group;
        string a, b, c;
        cin >> a >> b >> c;
        string groupArr[3] = {a, b, c};
        group.insert(a); group.insert(b); group.insert(c);

        for (int i = 0; i < 3; i++) {
            string curr = groupArr[i];
            for (string s : sameGroup[curr]) {
                if (group.find(s) == group.end()) {
                    violations++;
                }
            }
            for (string s : diffGroups[curr]) {
                if (group.find(s) != group.end()) {
                    violations++;
                }
            }
        }
    }

    printf("%d\n", violations);
    return 0;
}