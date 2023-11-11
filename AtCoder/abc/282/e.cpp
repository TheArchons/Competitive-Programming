// https://atcoder.jp/contests/abc282/tasks/abc282_e
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct ballEdge {
    int ball1;
    int ball2;
    ll score;

    bool operator<(const ballEdge& b) const {
        return this->score < b.score;
    }
};

const int maxBallNum = 505;

vector<int> ds(maxBallNum);
vector<int> dsh(maxBallNum, 1);

ll totalScore = 0;

int findRep(int ball) {
    while(ds[ball] != ball) {
        ball = ds[ball];
    }

    return ball;
}

void unionBalls(int rep1, int rep2) {
    if (dsh[rep1] < dsh[rep2]) {
        swap(rep1, rep2);
    }

    if (dsh[rep1] == dsh[rep2]) {
        dsh[rep1]++;
    }

    ds[rep2] = rep1;

    return;
}

ll powMod(ll base, ll exp, ll modVal) {
    if (!exp) {
        return 1;
    }

    ll halfPow = powMod(base, exp / 2, modVal);
    halfPow = halfPow * halfPow % modVal;
    if (exp % 2) { // exp is odd
        halfPow = halfPow * base % modVal;
    }

    return halfPow % modVal;
}

void initDs() {
    for (int i = 0; i < maxBallNum; i++) {
        ds[i] = i;
    }
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    // freopen("e.input", "r", stdin); // For testing. Comment out for submissions

    initDs();

    int ballNum; cin >> ballNum;
    ll maxInt; cin >> maxInt;

    vector<int> balls(ballNum);

    for (int i = 0; i < ballNum; i++) {
        cin >> balls[i];
    }

    priority_queue<ballEdge> ballEdges;

    for (int i = 0; i < ballNum; i++) {
        ll currBall = balls[i];

        for (int j = i+1; j < ballNum; j++) {
            ll ball2 = balls[j];

            ballEdge currEdge;
            currEdge.ball1 = i;
            currEdge.ball2 = j;
            currEdge.score = (powMod(currBall, ball2, maxInt) + powMod(ball2, currBall, maxInt)) % maxInt;

            ballEdges.push(currEdge);
        }
    }

    while (!ballEdges.empty()) {
        ballEdge currBall = ballEdges.top();
        ballEdges.pop();

        int rep1, rep2;
        rep1 = findRep(currBall.ball1);
        rep2 = findRep(currBall.ball2);

        if (rep1 != rep2) {
            totalScore += currBall.score;

            unionBalls(rep1, rep2);
        }
    }

    cout << totalScore << endl;

    return 0;
}