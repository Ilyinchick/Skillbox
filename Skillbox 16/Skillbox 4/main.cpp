#include <iostream>
#include <string>

enum Notes {
    DO = 1,
    RE = 2,
    MI = 4,
    FA = 8,
    SOL = 16,
    LA = 32,
    SI = 64
} note;

void printNote(Notes note);

int charToInt(char c);

Notes getNote(int i);

std::string input();

int main() {
    std::cout << "Enter 12 combinations: " << std::endl;
    for (char c : input()) {
        note = getNote(charToInt(c));
        printNote(note);
    }
    return 0;
}

void printNote(Notes note) {
     if (note == 1) {
        std::cout << "DO ";
    } else if (note == 2) {
         std::cout << "RE ";
     } else if (note == 4) {
         std::cout << "MI ";
     } else if (note == 8) {
         std::cout << "FA ";
     } else if (note == 16) {
         std::cout << "SOL ";
     } else if (note == 32) {
         std::cout << "LA ";
     } else if (note == 64) {
         std::cout << "SI ";
     }
}

Notes getNote(int i) {
    if (i == 1) return DO;
    if (i == 2) return RE;
    if (i == 4) return MI;
    if (i == 8) return FA;
    if (i == 16) return SOL;
    if (i == 32) return LA;
    if (i == 64) return SI;
}

int charToInt(char c) {
    int note = c - 48;
    note = 1 << (note - 1);
    return note;
}

std::string input() {
    std::string str, buffer;
    for (int i = 0; i < 12; i++) {
        std::cin >> buffer;
        str += buffer;
    }
    return str;
}