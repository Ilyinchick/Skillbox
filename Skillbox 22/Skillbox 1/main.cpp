#include <iostream>
#include <map>
#include <vector>


bool ifContainsChar(std::string str, char a);

std::string getStringFromInput();

bool isOneWord(std::string str);

bool isNumber(std::string str);

std::string getFirstWord(std::string str);

std::string getSecondWord(std::string str);

std::string reverseString(std::string str);

std::string findBySurname(std::string str, std::map<std::string, std::string> someMap);

void printNumbers(std::string str, std::map<std::string, std::vector<std::string>> surnameMap);

int main() {

    std::map<std::string, std::string> phoneMap;
    std::map<std::string, std::vector<std::string>> surnameMap;

    std::string str, buff;
    while (true) {
        std::cout << "Enter command: " << std::endl;
        str = getStringFromInput();
        if (str == "exit") break;

        else if (isOneWord(str)) {
            if (isNumber(str)) {
                if (phoneMap.count(str) > 0) {
                    std::cout << phoneMap.find(str)->second << std::endl;
                } else std::cout << "There is no such number" << std::endl;
            } else {
                if (surnameMap.count(str) > 0) {
                    printNumbers(str, surnameMap);
                } else std::cout << "There is no such person" << std::endl;
            }
        } else {
            phoneMap.insert(std::make_pair(getFirstWord(str), getSecondWord(str)));
            if (surnameMap.count(getSecondWord(str)) != 0) {
                surnameMap.find(getSecondWord(str))->second.push_back(getFirstWord(str));
            } else {
                std::vector<std::string> vec;
                vec.push_back(getFirstWord(str));
                surnameMap.insert(std::make_pair(getSecondWord(str), vec));
            }
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

void printNumbers(std::string str, std::map<std::string, std::vector<std::string>> surnameMap) {
    std::vector<std::string> vec = surnameMap.find(str)->second;
    for (std::string s: vec) {
        std::cout << s << " ";
    }
    std::cout << std::endl;
}
