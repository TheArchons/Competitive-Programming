#include <bits/stdc++.h>

using namespace std;

struct computer {
    bool operator<(const computer& other) const {
        int score = 2*RAM + 3*CPU + HDD;
        int otherScore = 2*other.RAM + 3*other.CPU + other.HDD;

        if (score == otherScore) return name > other.name;
        return score < otherScore;
    }

    string name;
    int RAM, CPU, HDD;
};

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    //freopen("1.input", "r", stdin); // for testing
    
    int computers;
    cin >> computers;

    if (computers == 0) return 0;

    priority_queue<computer> computerQ;

    for (int i = 0; i < computers; i++) {
        string name;
        int RAM, CPU, HDD;
        cin >> name >> RAM >> CPU >> HDD;

        computerQ.push({name, RAM, CPU, HDD});
    }

    // print top
    computer top = computerQ.top();
    cout << top.name << endl;
    computerQ.pop();

    // print second top
    if (computerQ.empty()) return 0;
    top = computerQ.top();
    cout << top.name << endl;

    return 0;
}