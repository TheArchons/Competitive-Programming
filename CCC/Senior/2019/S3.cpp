#include <bits/stdc++.h>

using namespace std;

#define squareType vector<vector<int>>
#define noNumber 1000001

bool squareCompleted(squareType square) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (square[i][j] == noNumber) {
                return false;
            }
        }
    }

    return true;
}

void printSquare(squareType square) {
    for (auto row : square) {
        for (auto col : row) {
            cout << col << " ";
        }
        cout << endl;
    }
}

vector<int> calculateRowColumn(vector<int> line) {
    if (line[0] != noNumber && line[1] != noNumber && line[2] == noNumber) {
        line[2] = line[1] + (line[1] - line[0]);
    } else if (line[0] != noNumber && line[1] == noNumber && line[2] != noNumber) {
        line[1] = line[0] + (line[2] - line[0]) / 2;
    } else if (line[0] == noNumber && line[1] != noNumber && line[2] != noNumber) {
        line[0] = line[1] - (line[2] - line[1]);
    }

    return line;
}

squareType calculateGuarantees(squareType square) {
    //check rows
    
    for (int i = 0; i < 3; i++) {
        square[i] = calculateRowColumn(square[i]);
    }

    // check columns
    for (int i = 0; i < 3; i++) {
        vector<int> column(3);
        for (int j = 0; j < 3; j++) {
            column[j] = square[j][i];
        }

        column = calculateRowColumn(column);

        for (int j = 0; j < 3; j++) {
            square[j][i] = column[j];
        }
    }

    return square;
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    //freopen("3.input", "r", stdin); // for testing
    
    squareType square(3, vector<int>(3, noNumber));

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            string num;
            cin >> num;
            if (num != "X") {
                square[i][j] = stoi(num);
            }
        }
    }

    square = calculateGuarantees(calculateGuarantees(square));

    printSquare(square);

    return 0;
}
