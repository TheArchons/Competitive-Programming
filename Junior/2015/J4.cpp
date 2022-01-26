#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

void printVecPair(vector<pair<int, int>> vec){
    for(pair<int, int> i : vec){
        printf("%d %d\n",i.first,i.second);
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
        }
        if (action == 'W') {
            time += number-1;
        }
        else {
            time++;
        }
        if (action == 'S') {
            bool broke = false;
            for (int i = 0; i < output.size(); i++) {
                if (output[i].first == number) {
                    broke = true;
                    output[i].second += time - 1 - receives[number];
                    break;
                }
                if (output[i].first > number) {
                    broke = true;
                    output.insert(output.begin()+i, make_pair(number, time - 1 - receives[number]));
                    break;
                }
            }
            if (!broke) {
                output.push_back(make_pair(number, time - 1 - receives[number]));
            }
            //output.push_back(make_pair(number, time - receives[number]));
            //dont forget to account if number is already in output
            receives.erase(number);
        }
    }
    //remove all numbers that didnt receive a reply
    for (int i = 0; i < output.size(); i++) {
        //exists in receives
        if (receives.find(output[i].first) != receives.end()) {
            //remove from receives
            receives.erase(output[i].first);
            output[i].second = -1;
        }
    }
    //add remaning receives to output
    for (unordered_map<int, int>::iterator it = receives.begin(); it != receives.end(); it++) {
        bool broke = false;
        for (int i = 0; i < output.size(); i++) {
            if (output[i].first > it->first) {
                broke = true;
                output.insert(output.begin()+i, make_pair(it->first, -1));
                break;
            }
        }
        if (!broke) {
            output.push_back(make_pair(it->first, -1));
        }
    }
    printVecPair(output);
}