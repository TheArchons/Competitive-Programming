#include <bits/stdc++.h>

using namespace std;

#define squareType vector<vector<int>>
#define noNumber 1000001

bool isLineEmpty(vector<int> line) {
    for (int i : line) {
        if (i != noNumber) {
            return false;
        }
    }

    return true;
}

pair<vector<int>, bool> fillLine(vector<int> line) {
    int filledNum = noNumber;
    for (int i = 0; i < line.size(); i++) {
        if (line[i] != noNumber) {
            if (filledNum == noNumber) {
                filledNum = line[i];
            } else {
                return make_pair(line, false);
            }
        }
    }

    for (int i = 0; i < line.size(); i++) {
        line[i] = filledNum;
    }

    return make_pair(line, true);
}

bool squareCompleted(squareType square) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (square[i][j] == noNumber) {
                return false;
            }
        }
    }

    // check for validity
    for (auto row : square) {
        if (row[1] + (row[1] - row[0]) != row[2]) {
            return false;
        }
    }

    for (int i = 0; i < 3; i++) {
        if (square[1][i] + (square[1][i] - square[0][i]) != square[2][i]) {
            return false;
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
    int inputNum = 0; int firstNum = 69;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            string num;
            cin >> num;
            if (num != "X") {
                square[i][j] = stoi(num);
                inputNum++;
                firstNum = square[i][j];
            }
        }
    }

   square = calculateGuarantees(calculateGuarantees(square));

    // calculate edge cases where there are no numbers or only one number
    if (inputNum == 0 || inputNum == 1) {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                square[i][j] = firstNum;
            }
        }
        printSquare(square);
        return 0;
    }

    // calculate the edgeCase where there are two numbers
    int numberCount = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (square[i][j] != noNumber) {
                numberCount++;
            }
        }
    }

    if (numberCount == 2) {
        // try rows
        squareType tempSquare = square;
        for (int i = 0; i < 3; i++) {
            int rowNum = noNumber;
            for (int j = 0; j < 3; j++) {
                if (tempSquare[i][j] != noNumber) {
                    rowNum = tempSquare[i][j];
                }
            }
            for (int j = 0; j < 3; j++) {
                tempSquare[i][j] = rowNum;
            }
        }

        tempSquare = calculateGuarantees(tempSquare);
        if (squareCompleted(tempSquare)) {
            printSquare(tempSquare);
            return 0;
        }

        // try columns
        for (int i = 0; i < 3; i++) {
            int colNum = noNumber;
            for (int j = 0; j < 3; j++) {
                if (square[j][i] != noNumber) {
                    colNum = square[j][i];
                }
            }
            for (int j = 0; j < 3; j++) {
                square[j][i] = colNum;
            }
        }

        square = calculateGuarantees(square);
        printSquare(square);
        return 0;
    }

    //if all numbers are in one row or column, set the other two to be the same
    int lineCount, rowNum;
    lineCount = rowNum = 0;
    for (int i = 0; i < 3; i++) {
        if (!isLineEmpty(square[i])) {
            lineCount++;
            rowNum = i;
        }
    }

    if (lineCount == 1) {
        vector<int> row = square[rowNum];

        for (int i = 0; i < 3; i++) {
            square[i] = row;
        }

        printSquare(square);
        return 0;
    }

    lineCount = rowNum = 0;
    for (int i = 0; i < 3; i++) {
        vector<int> column(3);
        for (int j = 0; j < 3; j++) {
            column[j] = square[j][i];
        }

        if (!isLineEmpty(column)) {
            lineCount++;
            rowNum = i;
        }
    }

    if (lineCount == 1) {
        vector<int> column(3);
        for (int j = 0; j < 3; j++) {
            column[j] = square[j][rowNum];
        }

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                square[i][j] = column[i];
            }
        }

        printSquare(square);
        return 0;
    }

    // try to fill every row
    for (int i = 0; i < 3; i++) {
        pair<vector<int>, bool> temp = fillLine(square[i]);
        if (temp.second) {
            squareType tempSquare = square;
            tempSquare[i] = temp.first;
            tempSquare = calculateGuarantees(calculateGuarantees(tempSquare));
            if (squareCompleted(tempSquare)) {
                printSquare(tempSquare);
                return 0;
            }
        }
    }

    // try to fill every column
    for (int i = 0; i < 3; i++) {
        vector<int> column(3);
        for (int j = 0; j < 3; j++) {
            column[j] = square[j][i];
        }

        pair<vector<int>, bool> temp = fillLine(column);

        if (temp.second) {
            squareType tempSquare = square;
            for (int j = 0; j < 3; j++) {
                tempSquare[j][i] = temp.first[j];
            }
            tempSquare = calculateGuarantees(calculateGuarantees(tempSquare));
            if (squareCompleted(tempSquare)) {
                printSquare(tempSquare);
                return 0;
            }
        }
    }

    printSquare(square);

    return 0;
}
