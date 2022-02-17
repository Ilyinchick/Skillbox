#include <iostream>
#include <string>

enum Notes {
    DO = 1,
    RE,
    MI,
    FA,
    SOL,
    LA,
    SI
} note;

void printNote(Notes note);

int charToInt(char c);

Notes getNote(int i);

std::string input();

int main() {
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
     } else if (note == 3) {
         std::cout << "MI ";
     } else if (note == 4) {
         std::cout << "FA ";
     } else if (note == 5) {
         std::cout << "SOL ";
     } else if (note == 6) {
         std::cout << "LA ";
     } else if (note == 7) {
         std::cout << "SI ";
     }
}

Notes getNote(int i) {
    if (i == 1) return DO;
    if (i == 2) return RE;
    if (i == 3) return MI;
    if (i == 4) return FA;
    if (i == 5) return SOL;
    if (i == 6) return LA;
    if (i == 7) return SI;
}

int charToInt(char c) {
    return c - 48;
}

std::string input() {
    std::string str, buffer;
    for (int i = 0; i < 12; i++) {
        std::cin >> buffer;
        str += buffer;
    }
    return str;
}