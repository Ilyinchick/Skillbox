#include <iostream>
#include <fstream>
#include <ctime>

const std::string path = "C:\\Users\\ailyi\\CLionProjects\\Skillbox\\Skillbox 20\\Skillbox 2\\picture.txt";

void enterSize(int* height, int* width);

void printPicture(int height, int width);

int main() {
    std::srand(std::time(nullptr));
    int height, width;

    enterSize(&height, &width);
    printPicture(height, width);

    return 0;
}

void enterSize(int* height, int* width) {
    std::cout << "Enter hight and width of picture: " << std::endl;
    std::cin >> *height >> *width;
}

void printPicture(int height, int width) {
    std::ofstream stream(path);

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            stream << rand() % 2;
        }
        stream << std::endl;
    }
    stream.close();
}
