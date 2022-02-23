#include <iostream>
#include <fstream>

int countOfMatches(std::string aimStr);

std::string enterStr();

const char* path = "C:\\Users\\ailyi\\CLionProjects\\Skillbox\\Skillbox 19\\Skillbox 1\\worlds.txt";

int main() {

    std::cout << countOfMatches(enterStr());
    return 0;
}

int countOfMatches(std::string aimStr) {
    std::fstream stream;
    std::string str;
    int count = 0;

    stream.open(path);
    while (!stream.eof()) {
        stream >> str;
        if (str == aimStr) count++;
    }
    stream.close();

    return count;
}

std::string enterStr() {
    std::string str;
    std::cout << "Enter word to search: " << std::endl;
    std::cin >> str;
    return str;
}
