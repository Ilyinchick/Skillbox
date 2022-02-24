#include <iostream>
#include <fstream>

std::ifstream stream;

std::string enterPath();

bool isFileOpened(std::string path);

bool checkExtension(std::string path);

bool checkStorage(char buffer[]);

int main() {
    char buffer[4];
    std::string inPath = enterPath();

    if (isFileOpened(inPath)) {
        stream.open(inPath, std::ios::binary);
        stream.read(buffer, sizeof(buffer));
        stream.close();
        if (checkStorage(buffer) && checkExtension(inPath)) std::cout << "This is PNG file." << std::endl;
        else std::cout << "This is not PNG file." << std::endl;
    } else {
        std::cout << "File is not opened. Incorrect path." << std::endl;
    }
    return 0;
}

std::string enterPath() {
    std::string str;
    std::cout << "Enter path to file: " << std::endl;
    std::getline(std::cin, str);
    return str;
}

bool isFileOpened(std::string path) {
    stream.open(path);
    bool flag;

    if (stream.is_open()) flag = true;
    else flag = false;

    stream.close();
    return flag;
}

bool checkExtension(std::string path) {
    std::string str = path.substr(path.length() - 4, path.length());
    if (str == ".png") return true;
    else return false;
}

bool checkStorage(char buffer[]) {
    if (buffer[0] == (char)-119) {
        if (buffer[1] == 'P' && buffer[2] == 'N' && buffer[3] == 'G') return true;
    }
    return false;
}
