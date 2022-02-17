#include <iostream>

std::string first;

std::string second;

char exp;

std::string inputStr();

void parse(std::string str);

float expression();

int main() {
    parse(inputStr());
    std::cout << expression() << std::endl;
    return 0;
}

std::string inputStr() {
    std::string str;
    std::cout << "Enter expression:" << std::endl;
    std::getline(std::cin, str);
    return str;
}

void parse(std::string str) {
    bool flag = true;
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/') {
            exp = str[i];
            flag = false;
            i++;
        } else if (flag) {
            first += str[i];
        } else {
            second += str[i];
        }
    }
}

float expression() {
    float answer;
    if (exp == '-') {
        answer = std::stof(first) - std::stof(second);
    } else if (exp == '*') {
        answer = std::stof(first) * std::stof(second);
    } else if (exp == '+') {
        answer = std::stof(first) + std::stof(second);
    } else if (exp == '/') {
        answer = std::stof(first) / std::stof(second);
    }
    return answer;
}
