#include <iostream>

bool dotCheck(std::string str);

bool allowedSymbols(std::string str);

int numbersComare(std::string str1, std::string str2);

std::string removeFrontZeros(std::string str);

bool containsDigit(std::string str);

int lengthBeforeDot(std::string str);

int negativeNumbersCompare(std::string str1, std::string str2);

bool zerosCompare(std::string str1, std::string str2);

int main() {
    int answer;

    std::string str1, str2;
    std::cout << "Enter first number: " << std::endl;
    std::cin >> str1;
    std::cout << "Enter second number: " << std::endl;
    std::cin >> str2;

    if (dotCheck(str1) && dotCheck(str2) && allowedSymbols(str1) && allowedSymbols(str2)) {
        if (str1[0] == '-' && str2[0] == '-') answer = negativeNumbersCompare(str1, str2);
        else answer = numbersComare(str1, str2);
        if (answer == 1) std::cout << "More" << std::endl;
        else if (answer == 2) std::cout << "Less" << std::endl;
        else if (answer == 3) std::cout << "Equal" << std::endl;
    } else {
        std::cout << "Not valid numbers" << std::endl;
    }
}

bool dotCheck(std::string str) {
    bool flag = false;
    if (str[str.length()] == '.') return false;

    for(char c : str) {
        if (c == '.') {
            if (!flag) flag = true;
            else return false;
        }
    }
    return true;
}

bool allowedSymbols(std::string str) {
    if (!containsDigit(str)) return false;
    if (str[0] != '-' && str[0] != '.' && (str[0] < '0' || str[0] > '9')) return false;
    for (int i = 1; i < str.length(); i++) {
        if ( (str[i] < '0' || str[i] > '9') && str[i] != '.') return false;
    }
    return true;
}

std::string removeFrontZeros(std::string str) {
    std::string answer;
    int start, counter = 0;

    if (str[0] == '-') {
        counter++;
        start = 1;
    }   else start = 0;

    for (int i = start; i < str.length(); i++) {
        if (str[i] != '0') break;
        counter++;
    }
    for (int i = counter; i < str.length(); i++) {
        answer += str[i];
    }
    return answer;
}

int numbersComare(std::string str1, std::string str2) {
    int min;
    str1 = removeFrontZeros(str1);
    str2 = removeFrontZeros(str2);

    if (lengthBeforeDot(str1) > lengthBeforeDot(str2))  return 1;
    else if (lengthBeforeDot(str1) < lengthBeforeDot(str2)) return 2;

    if (str1.length() == str2.length()) {
        for (int i = 0; i < str1.length(); i++) {
            if (str1[i] > str2[i]) return 1;
            else if (str1[i] < str2[i]) return 2;
        }
        return 3;
    } else {
        str1.length() < str2.length() ? min = str1.length() : min = str2.length();
        for (int i = 0; i < min; i++) {
            if (str1[i] > str2[i]) return 1;
            else if (str1[i] < str2[i]) return 2;
        }

        if (str1.length() > str2.length()) {
            for (int i = str2.length(); i < str1.length(); i++) {
                if (str1[i] != '0' && str1[i] != '.') return 1;
            }
        } else {
            for (int i = str1.length(); i < str2.length(); i++) {
                if (str2[i] != '0' && str2[i] != '.') return 2;
            }
        }
        return 3;
    }

}

bool containsDigit(std::string str) {
    for (char c : str) {
        if (c >= '0' && c <= '9') return true;
    }
    return false;
}

int lengthBeforeDot(std::string str) {
    int length = 0;
    for (char c : str) {
        if (c == '.') break;
        length++;
    }
    return length;
}

int negativeNumbersCompare(std::string str1, std::string str2) {
    if (zerosCompare(str1, str2)) return 3;

    int min;
    str1 = removeFrontZeros(str1);
    str2 = removeFrontZeros(str2);

    if (lengthBeforeDot(str1) < lengthBeforeDot(str2))  return 1;
    else if (lengthBeforeDot(str1) > lengthBeforeDot(str2)) return 2;

    if (str1.length() == str2.length()) {
        for (int i = 0; i < str1.length(); i++) {
            if (str1[i] < str2[i]) return 1;
            else if (str1[i] > str2[i]) return 2;
        }
        return 3;
    } else {
        str1.length() < str2.length() ? min = str1.length() : min = str2.length();
        for (int i = 0; i < min; i++) {
            if (str1[i] < str2[i]) return 1;
            else if (str1[i] > str2[i]) return 2;
        }

        if (str1.length() > str2.length()) {
            for (int i = str2.length(); i < str1.length(); i++) {
                if (str1[i] != '0' && str1[i] != '.') return 2;
            }
        } else {
            for (int i = str1.length(); i < str2.length(); i++) {
                if (str2[i] != '0' && str2[i] != '.') return 1;
            }
        }
        return 3;
    }
}

bool zerosCompare(std::string str1, std::string str2) {
    if (str1.length() == 1 && str1[0] == '0' && str2.length() == 2 && str2[0] == '-' && str2[1] == '0') return true;
    if (str2.length() == 1 && str2[0] == '0' && str1.length() == 2 && str1[0] == '-' && str1[1] == '0') return true;
    if (str1.length() == 2 && str1[0] == '-' && str1[1] == '0'
        && str2.length() == 2 && str2[0] == '-' && str2[1] == '0') return true;
    return false;
}
