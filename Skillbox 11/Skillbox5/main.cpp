#include <iostream>

bool symbolsAllowed(std::string str);

bool isCorrect(std::string str1, std::string str2, std::string str3);

bool xWon(std::string str1, std::string str2, std::string str3);

bool oWon(std::string str1, std::string str2, std::string str3);

bool inAROW(std::string str, char c);

std::string getCol(std::string str1, std::string str2, std::string str3, int i);

std::string getCross(std::string str1, std::string str2, std::string str3, int i);

int main() {

    std::string str1, str2, str3;
    std::cout << "Enter field: " << std::endl;
    std::cin >> str1;
    std::cin >> str2;
    std::cin >> str3;

    if (isCorrect(str1, str2, str3)) {
        if (xWon(str1, str2, str3)) std::cout << "Petya won" << std::endl;
        else if (oWon(str1, str2, str3)) std::cout << "Vanya won" << std::endl;
        else std::cout << "Nobody" << std::endl;
    } else {
        std::cout << "Incorrect" << std::endl;
    }
    return 0;
}

bool symbolsAllowed(std::string str) {
    if (str.length() != 3) {
        std::cout << "1";
        return false;
    }
    for (char c : str) {
        if (c != 'X' && c != 'O' && c != '.') return false;
    }
    return true;
}

bool isCorrect(std::string str1, std::string str2, std::string str3) {
    if (!symbolsAllowed(str1) || !symbolsAllowed(str2) || !symbolsAllowed(str3))    return false;

    std::string str = str1 + str2 + str3;
    int countX = 0, countO = 0;

    for (char c : str) {
        if (c == 'X') countX++;
        else if (c == 'O') countO++;
    }

    if (xWon(str1, str2, str3) && (countO >= countX)) return false;
    if (oWon(str1, str2, str3) && (countO != countX)) return false;
    if (countO > countX || (countX - countO) > 1) return false;
    if (inAROW(getCross(str1, str2, str3, 1), 'X') && inAROW(getCross(str1, str2, str3, 2), 'X')) return false;

    return true;
}

bool inAROW(std::string str, char c) {
    for (char symbol : str) {
        if (c != symbol) return false;
    }
    return true;
}

std::string getCol(std::string str1, std::string str2, std::string str3, int i) {
    std::string col;
    col += str1[i];
    col += str2[i];
    col += str3[i];
    return col;
}

std::string getCross(std::string str1, std::string str2, std::string str3, int i) {
    std::string cross;
    if (i == 1) {
        cross += str1[0];
        cross += str2[1];
        cross += str3[2];
    } else {
        cross += str3[0];
        cross += str2[1];
        cross += str1[2];
    }

    return cross;
}

bool xWon(std::string str1, std::string str2, std::string str3) {
    if (inAROW(str1, 'X') || inAROW(str2, 'X') || inAROW(str3, 'X') || inAROW(getCol(str1, str2, str3, 0), 'X') || inAROW(getCol(str1, str2, str3, 1), 'X')
        || inAROW(getCol(str1, str2, str3, 2), 'X') || inAROW(getCross(str1, str2, str3, 1), 'X') || inAROW(getCross(str1, str2, str3, 2), 'X') ) return true;
    else return false;
}

bool oWon(std::string str1, std::string str2, std::string str3) {
    if (inAROW(str1, 'O') || inAROW(str2, 'O') || inAROW(str3, 'O') || inAROW(getCol(str1, str2, str3, 0), 'O') || inAROW(getCol(str1, str2, str3, 1), 'O')
        || inAROW(getCol(str1, str2, str3, 2), 'O') || inAROW(getCross(str1, str2, str3, 1), 'O') || inAROW(getCross(str1, str2, str3, 2), 'O') ) return true;
    else return false;
}