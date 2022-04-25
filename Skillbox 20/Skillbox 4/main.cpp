#include <iostream>
#include <fstream>
#include <ctime>
#include <vector>

const std::string path = "C:\\Users\\ailyi\\CLionProjects\\Skillbox\\Skillbox 20\\Skillbox 4\\bank.bin";

int bank[6] = {0, 0, 0, 0, 0, 0};

void fillBank();

int enterSumm();

int calculateBankSumm();

void fillBills();

bool enterCommand();

void calculateTransaction(int* summ, int nominal, int index);

int main() {
    int summ, bankSumm;
    std::string command;

    std::srand(std::time(nullptr));

    do {
        std::cout << "Enter your command (+\\-)" << std::endl;
        std::cin >> command;
        if (command != "+" && command != "-") std::cout << "Invalid command. Try again" << std::endl;
    } while (command != "+" && command != "-");

    if (command == "+") {
        fillBank();
    } else {
        fillBills();
        bankSumm = calculateBankSumm();
  //       std::cout << bankSumm << std::endl;          // check banksumm to test
        summ = enterSumm();



        if (summ <= bankSumm && summ % 100 == 0) {
            calculateTransaction(&summ, 5000, 5);
            calculateTransaction(&summ, 2000, 4);
            calculateTransaction(&summ, 1000, 3);
            calculateTransaction(&summ, 500, 2);
            calculateTransaction(&summ, 200, 1);
            calculateTransaction(&summ, 100, 0);
        } else {
            std::cout << "Invalid summ to get." << std::endl;
        }
    }

    return 0;
}

void fillBank() {
    std::ofstream stream(path, std::ios::binary);
    int dummy;
    for (int i = 0; i < 1000; i++) {
        dummy = rand() % 6 + 1;

        switch(dummy) {
            case 1 : {
                dummy = 100;
                stream.write((char*)&dummy, sizeof(dummy));
                break;
            } case 2 : {
                dummy = 200;
                stream.write((char*)&dummy, sizeof(dummy));
                break;
            } case 3 : {
                dummy = 500;
                stream.write((char*)&dummy, sizeof(dummy));
                break;
            } case 4 : {
                dummy = 1000;
                stream.write((char*)&dummy, sizeof(dummy));
                break;
            } case 5 : {
                dummy = 2000;
                stream.write((char*)&dummy, sizeof(dummy));
                break;
            } case 6 : {
                dummy = 5000;
                stream.write((char*)&dummy, sizeof(dummy));
                break;
            }
        }
    }
    stream.close();
}

int enterSumm() {
    int summ;
    std::cout << "Enter summ you wat to get: " << std::endl;
    std::cin >> summ;
    return summ;
}

int calculateBankSumm() {
    int bankSumm = 0, dummy;
    std::ifstream stream;

    stream.open(path, std::ios::binary);
    while (!stream.eof()) {
        stream.read((char*)&dummy, sizeof(int));
        bankSumm += dummy;
    }
    stream.close();
    return bankSumm;
}

void fillBills() {
    std::ifstream stream(path, std::ios::binary);
    int dummy;

    while (!stream.eof()) {
        stream.read((char*)&dummy, sizeof(int));
        switch (dummy) {
            case 100 : {
                bank[0]++;
                break;
            } case 200 : {
                bank[1]++;
                break;
            } case 500 : {
                bank[2]++;
                break;
            } case 1000 : {
                bank[3]++;
                break;
            } case 2000 : {
                bank[4]++;
                break;
            } case 5000 : {
                bank[5]++;
                break;
            }
        }

    }
    stream.close();
}

void calculateTransaction(int* summ, int nominal, int index) {
    int countBills = *summ / nominal;
    if (countBills >= bank[index])  countBills = bank[index];
    bank[index] -= countBills;
    *summ -= countBills * nominal;
    if (index == 0) {
        if (*summ == 0) {
            std::cout << "You successfully get your money. Everithing is OK." << std::endl;
        } else {
            std::cout << "We dont have enough bills. Sorry." << std::endl;
        }
    }
}