#include <iostream>
#include <map>

void add(const std::string str, const int count, std::map<std::string, int> &map) {
    if (map.find(str) != map.end()) {
        if (count < 0) throw std::invalid_argument("cannot add less then 0 elements");
        map.find(str)->second += count;
    } else {
        map.insert(std::make_pair(str, count));
    }
}

void subtract(const std::string str, const int count, std::map<std::string, int> &map) {
    if (map.find(str) != map.end()) {
        if (count < 0) throw std::invalid_argument("Cannot subtract less then 0 elements");
        if (count > map.find(str)->second) throw std::invalid_argument("Cannot subtract");
        map.find(str)->second -= count;
        if (map.find(str)->second == 0) map.erase(str);
    } else {
        throw std::invalid_argument("There is no such item");
    }
}

void printBucket(const std::map<std::string, int> &map) {
    std::cout << "Bucket: " << std::endl;
    for (std::pair<std::string, int> pair: map) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }
}

int main() {
    std::map<std::string, int> map;
    std::string command;
    int count;

    while (command != "end") {
        std::cout << "Enter your command (add, subtract or end): " << std::endl;
        std::cin >> command;
        try {
            if (command == "add") {
                std::cout << "Enter position to add and count: " << std::endl;
                std::cin >> command >> count;
                add(command, count, map);
            } else if (command == "subtract") {
                std::cout << "Enter position to subtract and count: " << std::endl;
                std::cin >> command >> count;
                subtract(command, count, map);
            } else if (command != "end") std::cout << "There is no such command." << std::endl;
        } catch (std::invalid_argument &exception) {
            std::cerr << exception.what() << std::endl;
        }
        printBucket(map);
    }

    return 0;
}
