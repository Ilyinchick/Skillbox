#include <iostream>
#include <map>

bool isAnagram(std::string str1, std::string str2);

void buildMap(std::map<char, int>* someMap, std::string str);

int main() {
    std::string str1, str2;
    std::cout << "Enter two words: " << std::endl;
    std::cin >> str1 >> str2;
    if (isAnagram(str1, str2)) std::cout << "These words are anagram." << std::endl;
    else std::cout << "These words are not anagram." << std::endl;
    return 0;
}

bool isAnagram(std::string str1, std::string str2) {
    if (str1.length() != str2.length()) return false;
    std::map<char, int> oMap, bMap;

    buildMap(&oMap, str1);
    buildMap(&bMap, str2);

    std::map<char, int>::iterator it = oMap.begin();

    while (it != oMap.end()) {
        if (bMap.find(it->first)->second != it->second) return false;
        it++;
    }
    return true;
}

void buildMap(std::map<char, int>* someMap, std::string str) {
    for (char c: str) {
        if (someMap -> count(someMap -> find(c) -> first) != 0) {
            someMap -> find(c) -> second++;
        } else {
            someMap -> insert(std::make_pair(c, 1));
        }
    }
}
