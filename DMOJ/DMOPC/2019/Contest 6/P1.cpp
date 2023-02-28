#include <bits/stdc++.h>

using namespace std;

typedef long double ld;

struct Point {
    ld x, y;
};

struct Line {
    Point a, b;
    ld slope() {
        ld s = (b.y - a.y) / (b.x - a.x);
        if (isnan(s)) return 0;
        if (isinf(s)) return abs(s);
        return s;
    };
    ld yIntercept() {
        return a.y - slope() * a.x;
    };
};

struct formula {
    ld m, b;
};

Point getPoint() {
    Point p;
    cin >> p.x >> p.y;
    return p;
}

bool sameLine(Line l1, Line l2) {
    if (isinf(l1.slope()) && isinf(l2.slope())) {
        return l1.a.x == l2.a.x;
    }

    if (isinf(l1.slope()) || isinf(l2.slope())) {
        return false;
    }

    return l1.slope() == l2.slope() && l1.yIntercept() == l2.yIntercept();
}

ld getY(ld m, ld b, ld x) {
    return m * x + b;
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    // freopen("1.input", "r", stdin); // For testing. Comment out for submissions

    Line l1, l2;
    l1.a = getPoint(); l1.b = getPoint();
    l2.a = getPoint(); l2.b = getPoint();

    if (l1.slope() == l2.slope()) {
        if (sameLine(l1, l2)) {
            cout << "coincident";
        } else {
            cout << "parallel";
        }
    } else {
        // get intersection point
        formula f1, f2; // slope intercept form


        f1.m = l1.slope();
        f1.b = l1.yIntercept();

        f2.m = l2.slope();
        f2.b = l2.yIntercept();

        cout << fixed << setprecision(7);

        if (isinf(f1.m)) {
            cout << l1.a.x << " " << getY(f2.m, f2.b, l1.a.x);
        } else if (isinf(f2.m)) {
            cout << l2.a.x << " " << getY(f1.m, f1.b, l2.a.x);
        } else {
            ld m = f1.m - f2.m;
            ld b = f2.b - f1.b;
            ld x = b / m;

            if (!x) {
                x = 0;
            }

            cout << x << " " << getY(f1.m, f1.b, x);
        }
    }

    return 0;
}