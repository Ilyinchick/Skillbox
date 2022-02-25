#include <iostream>
#include <fstream>

const std::string inPath = "C:\\Users\\ailyi\\CLionProjects\\Skillbox\\Skillbox 20\\Skillbox 3\\river.txt";
const std::string outPath = "C:\\Users\\ailyi\\CLionProjects\\Skillbox\\Skillbox 20\\Skillbox 3\\basket.txt";

int fishesCatched = 0;

std::string enterFish();

void readBasket();

void catchFish(std::string fish);

bool isValidFish(std::string fish);

int main() {
    readBasket();
    std::string fish;

    while (true) {
        fish = enterFish();
        if (fish == "end") break;
        catchFish(fish);
    }
    return 0;
}

std::string enterFish() {
    std::string fish;
    std::cout << "Enter which fish do you want to catch or type 'end' to end: " << std::endl;
    std::cin >> fish;
    return fish;
}

void readBasket() {
    std::ifstream stream;
    stream.open(outPath);
    if (stream.is_open()) {
        stream >> fishesCatched;
    } else {
        std::cout << "There is no basktet." << std::endl;
    }
    stream.close();
}

void catchFish(std::string fish) {
    std::ofstream outStream(outPath);

    if (isValidFish(fish)) {
        fishesCatched++;
        outStream << fishesCatched;
    }

    outStream.close();
}

bool isValidFish(std::string fish) {
    std::ifstream stream;
    std::string dummy;

    stream.open(inPath);
    if (stream.is_open()) {
        while (!stream.eof()) {
            stream >> dummy;
            if (dummy == fish) return true;
        }
    } else {
        std::cout << "File is not opened. Incorrect path." << std::endl;
        return false;
    }
    std::cout << "There is no such fish." << std::endl;
    return false;
}
