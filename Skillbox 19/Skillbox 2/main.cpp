#include <iostream>
#include <fstream>
#include <vector>

std::string enterStr();

bool openFile(const std::string &path);

std::vector<std::string> getDataFromFile(const std::string &path);

int main() {
    std::vector<std::string> data;
    std::string path;
    while (path != "end") {
        path = enterStr();
        if (openFile(path)) {
            data = getDataFromFile(path);
            for (std::string s: data) {
                std::cout << s << std::endl;
            }
        }
    }

    return 0;
}

std::string enterStr() {
    std::string str;
    std::cout << "Enter path to file: " << std::endl;
    std::getline(std::cin, str);
    return str;
}

bool openFile(const std::string &path) {
    bool flag;
    std::ifstream stream;
    stream.open(path);
    if (stream.is_open()) {
        std::cout << "File is successfully opened." << std::endl;
        flag = true;
    } else {
        std::cout << "File is not opened, incorrect path." << std::endl;
        flag = false;
    }
    stream.close();
    return flag;
}

std::vector<std::string> getDataFromFile(const std::string &path) {
    std::vector<std::string> data;
    std::string buff;
    std::ifstream stream;

    stream.open(path);

    while (!stream.eof()) {
        stream >> buff;
        data.push_back(buff);
    }
    return data;
}