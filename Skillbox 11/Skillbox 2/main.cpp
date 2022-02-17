#include <iostream>

bool atSymbol(std::string str);

bool firstPartCheck(std::string str);

bool secondPartCheck(std::string str);

bool dotCheck(std::string str);

bool contains(std::string str, char symbol);

int countMatches(std::string str, char symbol);

bool beforeCheck(std::string str);

bool afterCheck(std::string str);

bool partsLength(std::string str);

std::string partBefore(std::string str, char symbol);

std::string partAfter(std::string str, char symbol);

bool correctCheck(std::string str);


int main() {
    std::string str;
    std::cout << "Enter email: ";
    std::cin >> str;
    if (correctCheck(str)) std::cout << "Yes";
    else std::cout << "No";
    return 0;
}


bool correctCheck(std::string str) {
    if (firstPartCheck(str) && secondPartCheck(str) && partsLength(str) && dotCheck(str) && atSymbol(str)) return true;
    else return false;
}

bool firstPartCheck(std::string str) {
    std::string first = partBefore(str, '@'), allowed = "!#$%&'*+-/=?^_`{|}~";
    for (char c : first) {
        if ( !( (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9') || c == '.' || c == '-' ||
                contains(allowed, c) ) ) return false;
    }
    return true;
}

bool secondPartCheck(std::string str) {
    std::string second = partAfter(str, '@');
    for (char c : second) {
        if ( !( (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9') || c == '.' || c == '-' ) ) return false;
    }
    return true;
}

bool partsLength(std::string str) {
    std::string first, second;
    first = partBefore(str, '@');
    second = partAfter(str, '@');

    if (first.length() < 1 || first.length() > 64) return false;
    if (second.length() < 1 || second.length() > 63) return false;

    return true;
}

bool dotCheck(std::string str) {
    std::string first, second;
    first = partBefore(str, '@');
    second = partAfter(str, '@');

    if (first[0] == '.' || first[first.length()] == '.') return false;
    if (second[0] == '.' || second[second.length()] == '.') return false;

    for (int i = 0; i < first.length(); i++) {
        if (first[i] == '.' && first[i+1] == '.') return false;
    }
    for (int i = 0; i < second.length(); i++) {
        if (second[i] == '.' && second[i+1] == '.') return false;
    }
    return true;
}

std::string partAfter(std::string str, char symbol) {
    bool flag = false;
    std::string partAfter = "";
    for (char c : str) {
        if (c == symbol) {
            flag = true;
            continue;
        }
        if (flag) partAfter += c;
    }
    return partAfter;
}

std::string partBefore(std::string str, char symbol) {
    std::string firstPart = "";
    for (char c : str) {
        if (c == symbol) break;
        firstPart += c;
    }
    return firstPart;
}

bool atSymbol(std::string str) {
    if (countMatches(str, '@') != 1) return false;
    else return true;
}

bool contains(std::string str, char symbol) {
    for (char c : str) {
        if (c == symbol) return true;
    }
    return false;
}

int countMatches(std::string str, char symbol) {
    int count = 0;
    for (char c : str) {
        if (c == symbol) count++;
    }
    return count;
}