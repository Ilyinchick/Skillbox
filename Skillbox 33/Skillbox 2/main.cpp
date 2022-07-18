#include <iostream>
#include <ctime>

class CatchFishException : public std::exception {
public:
    const char *what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW override {
        return "Fish catched!";
    }
};

class CatchBootException : public std::exception {
public:
    const char *what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW override {
        return "Boot catched!";
    }
};



char arr[9][9];

int getRandom(int max) {
    return std::rand() % max;
}

void fillArr(char a) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            arr[i][j] = a;
        }
    }
}

void putChar(const char c) {
    int x = getRandom(9), y = getRandom(9);

    while (arr[x][y] != ' ') {
        x = getRandom(9);
        y = getRandom(9);
    }
    //std::cout << x << " " << y << std::endl;
    arr[x][y] = c;
}

void fillField() {
    fillArr(' ');
    for (int i = 0; i < 3; i++) {
        putChar('b');
    }
    putChar('f');
}

void tryToCatch() {
    int x, y;
    while (true) {
        std::cout << "Enter coordinates: " << std::endl;
        std::cin >> x >> y;
        if (x >= 0 && x < 9 && y >= 0 && y < 9) {
            if (arr[x][y] == 'f') throw CatchFishException();
            else if (arr[x][y] == 'b') throw CatchBootException();
            else std::cout << "No result" << std::endl;
        } else std::cout << "Invalid coordinates." << std::endl;
    }

}


int main() {
    std::srand(std::time(nullptr));

    fillField();
    try {
        tryToCatch();
    } catch (CatchFishException &fish){
        std::cerr << fish.what() << std::endl;
    } catch (CatchBootException &boot) {
        std::cerr << boot.what() << std::endl;
    }
    return 0;
}
