#include <sstream>
#include <iostream>

bool symbolsAllowed(std::string str);

int countMatches(std::string str, char symbol);

bool countDots(std::string str);

bool zerosCheck(std::string str);

bool basicLengthCheck(std::string str);

bool dotsCheck(std::string str);

bool valuesCheck(std::string str);


int main() {
    std::string str;
    std::cout << "Enter IP adress: ";
    std::cin >> str;
    if (symbolsAllowed(str) && dotsCheck(str) && valuesCheck(str) && zerosCheck(str)) {
        std::cout << "Yes";
    } else std::cout << "\nNo";
    return 0;
}

bool symbolsAllowed(std::string str) {
    for(char c : str) {
        if ((c < '0' || c > '9') && c != '.')  {
            std::cout << "Symbols not allowed";
            return false;
        }
    }
    return true;
}

int countMatches(std::string str, char symbol) {
    int count = 0;
    for (char c : str) {
        if (c == symbol) count++;
    }
    return count;
}

bool countDots(std::string str) {
    if (countMatches(str, '.') != 3) {
        std::cout << "Not correct count of dots";
        return false;
    }
    else return true;
}

bool zerosCheck(std::string str) {
    for (int i = 0; i < str.length() - 2; i++) {
        if (str[i] == '0' && str[i+1] == '0' || str[i+1] == '0' && str[i+2] == '0') {
            std::cout << "Zeros error";
            return false;
        }
        if (str[i] == '.' && str[i+1] == '0' && str[i+2] != '.') return false;
    }
    return true;
}

bool basicLengthCheck(std::string str) {
    if (str.length() < 7 || str.length() > 15) return false;
    else return true;
}

bool dotsCheck(std::string str) {
    if (str[0] == '.' || str[str.length()] == '.') {
        std::cout << "Start or finish symbol is dot";
        return false;
    }

    for (int i = 0; i < str.length(); i++) {
        if (str[i] == '.'&& str[i+1] == '.') {
            std::cout << "Two dots in a row";
            return false;
        }
    }
    return countDots(str);
}

bool valuesCheck(std::string str) {
    std::string strValue;
    int value = 0;

    for(int i = 0; i < str.length(); i++) {
        if (str[i] == '.') {
            std::stringstream ss;
            ss << strValue;
            ss >> value;
            if (strValue[0] == '0' && value != 0) return false;
            if (value < 0 || value > 255) {
                std::cout << "Not correct value";
                return false;
            }
            else {
                strValue = "";
                continue;
            }
        } else strValue += str[i];
    }
    std::stringstream ss;
    ss << strValue;
    ss >> value;
    if (value < 0 || value > 255) {
        std::cout << "Not correct value";
        return false;
    }

    return true;
}