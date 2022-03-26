#include "disk.h"


void save(int* arr) {
    std::ofstream stream;
    stream.open(path);
    for (int i = 0; i < 8; i++) {
        stream << *(arr + i) << " ";
    }
    stream.close();
}

void load(int* arr) {
    std::ifstream stream;
    stream.open(path);
    for (int i = 0; i < 8; i++) {
        stream >> *(arr + i);
    }
    stream.close();
}