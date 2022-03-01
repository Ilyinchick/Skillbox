#include <iostream>
#include <fstream>
#include <vector>

const std::string path = "C:\\Users\\ailyi\\CLionProjects\\Skillbox\\Skillbox 21\\Skillbox 1\\data.txt";

struct person {
    std::string name = "default";
    std::string date = "12.12.2022";
    int summ = 0;
};

std::string enterString();

int enterSumm();

std::string fullname(std::string name, std::string surname);

bool isValidData(std::string name, std::string date, int summ);

bool isValidString(std::string str);

bool isValidDate(std::string date);

bool isValidSumm(int summ);

void writeData(std::string path, std::string name, std::string date, int summ);

void addPersonToList();

void printList();

std::string printPerson(person& man);


int main() {
    std::string dummy = "list";

    while (true) {
        std::cout << "Input you command (list, add or exit): " << std::endl;
        std::cin >> dummy;
        if (dummy == "exit") break;
        else if (dummy == "add") {
            addPersonToList();
        } else if (dummy == "list") {
            printList();
        } else {
            std::cout << "Not valid command, try again." << std::endl;
        }
    }

    return 0;
}


std::string enterString() {
    std::string name;
    std::cin >> name;
    return name;
}

int enterSumm() {
    int summ;
    std::cin >> summ;
    return summ;
}

bool isValidData(std::string name, std::string date, int summ) {
    if (isValidString(name) && isValidDate(date) && isValidSumm(summ)) return true;
    else return false;
}

bool isValidString(std::string str) {
    if (str.length() != 0) return true;
    else return false;
}

bool isValidDate(std::string date) {
    std::string dummy;

    dummy = date.substr(0, 2);
    if (std::stoi(dummy) < 0 || std::stoi(dummy) > 31) return false;
    dummy = date.substr(3, 2);
    if (std::stoi(dummy) < 1 && std::stoi(dummy) > 12) return false;
    dummy = date.substr(6);
    if (std::stoi(dummy) != 2022) return false;

    return true;
}

bool isValidSumm(int summ) {
    if (summ < 0) return false;
    else return true;
}

void writeData(std::string path, std::string name, std::string date, int summ) {
    std::ofstream stream;
    stream.open(path, std::ios::app);
    stream << name << " " << date << " " << summ << std::endl;
    stream.close();
}

std::string fullname(std::string name, std::string surname) {
    return name + " " + surname;
}

void addPersonToList() {
    person man;
    std::string name, surname;

    std::cout << "Enter date in 'Name Surname DD.MM.YYYY summ' format: " << std::endl;

    name = enterString();
    surname = enterString();
    man.name = fullname(name, surname);
    man.date = enterString();
    man.summ = enterSumm();

    if (isValidData(man.name, man.date, man.summ)) {
        writeData(path, man.name,man.date, man.summ);
    } else {
        std::cout << "Data is not valid." << std::endl;
    }
}

void printList() {
    std::string name, surname;
    person dummy;
    std::ifstream stream;
    stream.open(path);
    while (!stream.eof()) {
        stream >> name >> surname;
        if (stream.eof()) break;
        dummy.name = fullname(name, surname);
        stream >> dummy.date >> dummy.summ;
        std::cout << printPerson(dummy) << std::endl;
    }
    stream.close();
}

std::string printPerson(person& man) {
    return man.name + " " + man.date + " " + std::to_string(man.summ);
}