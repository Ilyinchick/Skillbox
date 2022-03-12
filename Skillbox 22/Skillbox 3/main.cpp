#include <iostream>
#include <map>

bool isAnagram(std::string str1, std::string str2);

bool containsChar(char a, std::map<char, char>* someMap);

int main() {
    std::string str1, str2;
    std::cout << "Enter two words: " << std::endl;
    std::cin >> str1 >> str2;
    if (isAnagram(str1, str2)) std::cout << "These words are anagram." << std::endl;
    else std::cout << "These words are not anagram." << std::endl;
    return 0;
}

bool isAnagram(std::string str1, std::string str2) {
    std::map<char, char> oMap;
    for (char c: str1) {
        oMap.insert(std::make_pair(c, c));
    }
    for (char c: str2) {
        if (oMap.count(oMap.find(c)->first) == 0) return false;
    }
    return true;
}
