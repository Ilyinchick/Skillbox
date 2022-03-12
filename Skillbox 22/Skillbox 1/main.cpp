#include <iostream>
#include <map>


bool ifContainsChar(std::string str, char a);

std::string getStringFromInput();

bool isOneWord(std::string str);

bool isNumber(std::string str);

std::string getFirstWord(std::string str);

std::string getSecondWord(std::string str);

std::string reverseString(std::string str);

std::string findBySurname(std::string str, std::map<std::string, std::string> someMap);

void printNumbers(std::string str, std::map<std::string, std::string> someMap);

int main() {
    std::map <std::string, std::string> someMap;
    std::string str;
    while (true) {
        std::cout << "Enter command: " << std::endl;
        str = getStringFromInput();
        if (str == "exit") break;
        else if (isOneWord(str)) {
            if (isNumber(str)) {
                std::cout << someMap.find(str)->second << std::endl;
            } else {
                printNumbers(str, someMap);
            }
        } else {
            someMap.insert(std::make_pair(getFirstWord(str), getSecondWord(str)));
        }
    }


    return 0;
}

bool ifContainsChar(std::string str, char a) {
    for (char c: str) {
        if (c == a) return true;
    }
    return false;
}

std::string getStringFromInput() {
    std::string str;
    std::getline(std::cin, str);
    return str;
}

bool isOneWord(std::string str) {
    if (ifContainsChar(str, ' ')) return false;
    else return true;
}

bool isNumber(std::string str) {
    for (char c: str) {
        if (c == '-') return true;
    }
    return false;
}

std::string getFirstWord(std::string str) {
    std::string word;
    for (char c: str) {
        if (c == ' ') break;
        word += c;
    }
    return word;
}

std::string getSecondWord(std::string str) {
    str = reverseString(str);
    str = getFirstWord(str);
    return reverseString(str);
}

std::string reverseString(std::string str) {
    std::string reversedStr;
    for (int i = str.length() - 1; i >= 0; i--) {
        reversedStr += str[i];
    }
    return reversedStr;
}

void printNumbers(std::string str, std::map<std::string, std::string> someMap) {
    std::map<std::string, std::string>::iterator it;
    for (it = someMap.begin(); it != someMap.end(); it++) {
        if (it->second == str)  std::cout << it->first << " ";
    }
    std::cout << std::endl;
}
