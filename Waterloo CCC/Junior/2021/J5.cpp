#include <iostream>
#include <string>

int main() {
    int columns, rows, inputs, total = 0, Rs = 0, Cs = 0, temp2 = 0;
    std::string temp;
    std::getline(std::cin, temp);
    rows = std::stoi(temp);
    std::getline(std::cin, temp);
    columns = std::stoi(temp);
    std::getline(std::cin, temp);
    inputs = std::stoi(temp);
    bool rArray[rows] = {0}, cArray[columns] = {0};
    for (int i = 0; i < inputs; i++) {
        std::string input;
        std::getline(std::cin, input);
        char cOrR = input[0];
        int index = std::stoi(input.substr(2, input.length()));
        if (cOrR == 'R') {
            if (rArray[index - 1]) {
                rArray[index - 1] = false;
            }
            else {
                rArray[index - 1] = true;
            }
        } else {
            if (cArray[index - 1]) {
                cArray[index - 1] = false;
            }
            else {
                cArray[index - 1] = true;
            }
        }
    }
    for (int i = 0; i < rows; i++) {
        if (rArray[i]) {
            Rs++;
        }
    }
    for (int i = 0; i < columns; i++) {
        if (cArray[i]) {
            Cs++;
        }
    }
    total = Cs*(rows-Rs);
    total += Rs*(columns-Cs);
    std::cout << total;
}