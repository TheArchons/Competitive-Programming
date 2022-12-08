#include <bits/stdc++.h>
using namespace std;

/*
Store all the boxes in a vector
Compare each box with the other boxes.
Save a vector of points where at least one box is present, and one for each section where a box overlaps another (prevent duplicates by checking if the point is within another)
For each point, if there are at least T overlapping boxes, calculate the area of the section by taking the minimum of the boxes' dimensions
*/

struct box {
    int x1, y1, x2, y2;
};

pair<int, int> compareTopLeft(box a, box b) {
    if (a.x1 <= b.x2 && a.y1 <= b.y2) return make_pair(a.x1, a.y1); 
    else return make_pair(-1, -1);
}

pair<int, int> compareTopRight(box a, box b) {
    if (a.x2 >= b.x1 && a.y1 <= b.y2) return make_pair(a.x2, a.y1);
    else return make_pair(-1, -1);
}

pair<int, int> compareBottomLeft(box a, box b) {
    if (a.x1 <= b.x2 && a.y2 >= b.y1) return make_pair(a.x1, a.y2);
    else return make_pair(-1, -1);
}

pair<int, int> compareBottomRight(box a, box b) {
    if (a.x2 >= b.x1 && a.y2 >= b.y1) return make_pair(a.x2, a.y2);
    else return make_pair(-1, -1);
}

int main() {
    int n, t;
    scanf("%d %d", &n, &t);

    vector<box> boxes(n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d %d", &boxes[i].x1, &boxes[i].y1, &boxes[i].x2, &boxes[i].y2);
    }

    vector<pair<int, int>> points; // x, y
    for (int i = 0; i < boxes.size(); i++) {
        for (int j = i+1; j < boxes.size(); j++) {
            // test for overlap
            // DRY? What's that?
            pair<int, int> topLeft = compareTopLeft(boxes[i], boxes[j]);
            pair<int, int> topRight = compareTopRight(boxes[i], boxes[j]);
            pair<int, int> bottomLeft = compareBottomLeft(boxes[i], boxes[j]);
            pair<int, int> bottomRight = compareBottomRight(boxes[i], boxes[j]);

            if (topLeft.first != -1) {
                points.push_back(topLeft);
            } else if (topRight.first != -1) {
                points.push_back(topRight);
            } else if (bottomLeft.first != -1) {
                points.push_back(bottomLeft);
            } else if (bottomRight.first != -1) {
                points.push_back(bottomRight);
            }
        }
    }
}