#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

struct box{
    int lx, rx, by, ty;
    int tint;
    box(int lx, int rx, int by, int ty, int tint){
        this->lx = lx;
        this->rx = rx;
        this->by = by;
        this->ty = ty;
        this->tint = tint;
    }

    bool isColliding(box &other) {
        //check to see if 2 boxes are colliding
        if ((this->lx < other.rx && this->ty > other.by) || (this->lx < other.rx && this->by < other.ty) || (this->rx > other.lx && this->ty > other.by) || (this->rx > other.lx && this->by < other.ty)) {
            return true;
        }
        return false;
    }
};

int main() {
    //box1 and 2
    int box1lx, box1rx, box1by, box1ty, box2lx, box2rx, box2by, box2ty, tint;
    
    return 0;
}