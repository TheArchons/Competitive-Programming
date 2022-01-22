#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;

void printVec(vector<int> vec){
    for(int i:vec){
        cout << i << " ";
    }
    cout << endl;
}
void print2dVec(vector<vector<int>> vec){
    for(vector<int> i : vec){
        printVec(i);
    }
    cout << endl;
}

void printQueue(queue<int> q){
    while(!q.empty()){
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}

bool isShop(vector<int> shops, int i){
    //quicksearch for shop
    for(int j = 0; j < shops.size(); j++){
        if(shops[j] == i){
            return true;
        }
    }
    return false;
}

int main(){
    int numLines,numShops;
    vector<int> shopLocations;

    scanf("%d %d\n",&numLines,&numShops);
    for(int i=0;i<numShops;i++){
        int shopIndex;
        cin >> shopIndex;
        shopLocations.push_back(shopIndex);
    }
    vector<vector<int>> tree(numLines);

    for(int i=0;i<numLines-1;i++){
        int src,dst;
        cin >> src;
        cin >> dst;
        tree[src].push_back(dst);
        tree[dst].push_back(src);
    }
    //pick a random spot to call our tail
    //expand to find outself another node to call as our head
    //  move the head and tail in all directions (breadth first)
    //  if the head sees that the tail has already been there, dont
    //      go down that path (as the tail will get there first), and vice versa
    //  If either the head or tail sees a new node, assign that node to whichever
    //      head or tail has reached that node (order doesnt matter)
    //  Once we have found a new head/tail, clear the nodes, and start counting
    //      up again

    // print tree
    //cout << endl;
    //print2dVec(tree);
    int head,tail;
    tail = head = shopLocations[0];
    shopLocations.erase(shopLocations.begin());
    int steps = 0;
    //bfs to find head

    while(!shopLocations.empty()){
        queue<vector<int>> hToVisit, tToVisit; //head and tail to visit. Vector to keep track of steps
        hToVisit.push({head}); tToVisit.push({tail});
        int curr = hToVisit.front().front();
        vector<vector<int>> visitedTree = tree; //copy of tree to keep track of visited nodes
        vector<int> toVisit;
        bool foundShop = false;
        //bool foundHShop, foundTShop;
        //foundHShop = foundTShop = false;
        while (true){
            while(!hToVisit.front().empty()) { //bfs one layer for head
                curr = hToVisit.front().front();
                hToVisit.front().erase(hToVisit.front().begin());
                for(int i = 0; i < visitedTree[curr].size(); i++){
                    if (visitedTree[curr][i] == -1 || visitedTree[curr][i] == tail || visitedTree[curr][i] == head){
                        continue;
                    }
                    if(!isShop(shopLocations,visitedTree[curr][i])){
                        toVisit.push_back(visitedTree[curr][i]); //add to queue and mark as visited
                        visitedTree[curr][i] =  -1;
                    }
                    else{
                        head = visitedTree[curr][i]; //found head, so assign it
                        shopLocations.erase(find(shopLocations.begin(),shopLocations.end(),head));
                        //foundHShop = true;
                        foundShop = true;
                        steps++;
                        break;
                    }
                }
                if(foundShop){
                    break;
                }
            }
            if (foundShop) {
                break;
            }
            if (!toVisit.empty()) {
                hToVisit.pop();
                hToVisit.push(toVisit);
                toVisit.clear();
            }
            while(!tToVisit.front().empty()) { //bfs one layer for tail
                curr = tToVisit.front().front();
                tToVisit.front().erase(tToVisit.front().begin());
                for(int i = 0; i < visitedTree[curr].size(); i++){
                    if (visitedTree[curr][i] == -1 || visitedTree[curr][i] == tail || visitedTree[curr][i] == head) {
                        continue;
                    }
                    if(!isShop(shopLocations,visitedTree[curr][i])){
                        toVisit.push_back(visitedTree[curr][i]); //add to queue and mark as visited
                        visitedTree[curr][i] = -1;
                    }
                    else{
                        tail = visitedTree[curr][i]; //found tail, so assign it
                        shopLocations.erase(find(shopLocations.begin(),shopLocations.end(),tail));
                        //foundTShop = true;
                        steps++;
                        foundShop = true;
                        break;
                    }
                }
                if (foundShop) {
                    break;
                }
            }
            if (foundShop) {
                break;
            }
            if (!toVisit.empty()) {
                tToVisit.pop();
                tToVisit.push(toVisit);
                toVisit.clear();
            }
            //pop tToVisit if not empty
            steps++;
        }
    }
    cout << steps;
    return 0;
}