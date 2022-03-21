#include "disk.h"


void save(int arr[8]) {
    std::ofstream stream;
    stream.open(path);
    for (int i; i < 8; i++) {
        stream << arr[i];
    }
    stream.close();
}

void load(int arr[8]) {
    std::ifstream stream;
    stream.open(path);
    for (int i; i < 8; i++) {
        stream >> arr[i];
    }
    stream.close();
}