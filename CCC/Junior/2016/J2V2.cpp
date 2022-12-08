#include <iostream>
#include <string>
 
using namespace std;

int main() {
    int matrix[4][4];
    //split input into 4x4 matrix
    for (int i = 0; i < 4; i++) {
        string temp = "";
        int total = -1;
        int prev = 0;
        int index = 0;
        getline(cin, temp);
        for (int j = 0; j < temp.length(); j++) {
            string sub = "";
            if (temp[j] == ' ') {
                sub = temp.substr(prev, j - prev);
                matrix[i][index] = stoi(sub);
                prev = j+1;
                index++;
            }
        }
        //final Num
        string sub = temp.substr(prev, temp.length() - prev);
        matrix[i][index] = stoi(sub);
    }
    //check if magic
    //horizontal 1
    int firstSum = matrix[0][0] + matrix[0][1] + matrix[0][2] + matrix[0][3];
    /*//vertical 1
    if (firstSum != matrix[0][0] + matrix[1][0] + matrix[2][0] + matrix[3][0]) {
        cout << "not magic\n";
        return 0;
    }*/
    //horizontal
    for (int i = 1; i < 4; i++) {
        int sum = matrix[i][0] + matrix[i][1] + matrix[i][2] + matrix[i][3];
        if (firstSum != sum) {
            cout << "not magic\n";
            return 0;
        }
    }
    for (int i = 0; i < 4; i++) {
        int sum = matrix[0][i] + matrix[1][i] + matrix[2][i] + matrix[3][i];
        if (firstSum != sum) {
            cout << "not magic\n";
            return 0;
        }
    }
    cout << "magic\n";
    return 0;
}