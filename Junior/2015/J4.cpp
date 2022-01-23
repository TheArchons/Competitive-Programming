#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

void printVecPair(vector<pair<int, int>> vec){
    for(pair<int, int> i : vec){
        cout << i.first << " " << i.second << endl;
    }
    //cout << endl;
}

int main() {
    int numActions, time = 0;
    scanf("%d\n", &numActions);
    unordered_map<int, int> receives; // <phone, time>
    vector<pair<int, int>> output; //<phone, time>
    for (int i = 0; i < numActions; i++) {
        char action;
        int number;
        scanf("\n%c %d", &action, &number);
        if (action == 'R') {
            receives[number] = time;
            time++;
        }
        if (action == 'W') {
            time += number-1;
        }
        if (action == 'S') {
            output.push_back(make_pair(number, time - receives[number]));
            time++;
        }
    }
    printVecPair(output);
}