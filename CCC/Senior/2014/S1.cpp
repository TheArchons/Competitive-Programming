#include <iostream>
#include <queue>
using namespace std;

int main() {
    int friends, rounds, output, counted, x, count;
    cin >> friends;
    cin >> rounds;
    queue<int> multiples, printed, printedClone;
    int incFriends[friends], incFriendsClone[friends];
    output = friends;
    for (int i = 0; i < friends; i++) {
        incFriends[i] = i+1;
    }
    for (int i = 0; i < rounds; i++) {
        int temp;
        cin >> temp;
        multiples.push(temp);
    }
    while(!empty(multiples)) {
        x = 0;
        count = 1;
        int multiple = multiples.front();
        multiples.pop();
        //remove 0s from list
        for(int i = 0; i < friends; i++) {
            if(incFriends[i] != 0) {
                incFriendsClone[x] = incFriends[i];
                x++;
            }
        }
        for(int i = 0; i < x; i++) {
            incFriends[i] = incFriendsClone[i];
        }
        for(int i = x; i < friends; i++) {
            incFriends[i] = 0;
        }
        bool empty = true;
        while(count <= x/multiple) {
            incFriends[(count*multiple)-1] = 0;
            count++;
        }
    }
    x = 0;
    for(int i = 0; i < friends; i++) {
        if(incFriends[i] != 0) {
            incFriendsClone[x] = incFriends[i];
            x++;
        }
    }
    for(int i = 0; i < x; i++) {
        incFriends[i] = incFriendsClone[i];
    }
    for(int i = x; i < friends; i++) {
        incFriends[i] = 0;
    }
    for(int i = 0; i < x; i++) {
        if(incFriends[i] != 0) {
            cout << incFriends[i] << endl;
        }
    }
    return 0;
}
