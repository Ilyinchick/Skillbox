#include <iostream>
#include <fstream>

const std::string path = "C:\\Users\\ailyi\\CLionProjects\\Skillbox\\Skillbox 20\\Skillbox 1\\data.txt";


std::string enterString();

int enterSumm();

bool isValidData(std::string name, std::string surname, std::string date, int summ);

bool isValidString(std::string str);

bool isValidDate(std::string date);

bool isValidSumm(int summ);

void writeData(std::string path, std::string name, std::string surname, std::string date, int summ);

int main() {
    std::string name, surname, date;
    int summ;

    std::cout << "Enter date in 'Name Surname DD.MM.YYYY summ' format: " << std::endl;

    name = enterString();
    surname = enterString();
    date = enterString();
    summ = enterSumm();

    if (isValidData(name, surname, date, summ)) {
        writeData(path, name, surname, date, summ);
    } else {
        std::cout << "Data is not valid." << std::endl;
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

bool isValidData(std::string name, std::string surname, std::string date, int summ) {
    if (isValidString(name) && isValidString(surname) && isValidDate(date) && isValidSumm(summ)) return true;
    else return false;
}

bool isValidString(std::string str) {
    if (str.length() != 0) return true;
    else return false;
}

bool isValidDate(std::string date) {
    std::string dummy;

    if(date.length() < 10) return false;

    dummy = date.substr(0, 2);
    if (std::stoi(dummy) < 0 || std::stoi(dummy) > 31) return false;
    dummy = date.substr(3, 2);
    if (std::stoi(dummy) < 1 && std::stoi(dummy) > 12) return false;
    dummy = date.substr(6);
    if (std::stoi(dummy) > 2022) return false;

    return true;
}

bool isValidSumm(int summ) {
    if (summ < 0) return false;
    else return true;
}

void writeData(std::string path, std::string name, std::string surname, std::string date, int summ) {
    std::ofstream stream;
    stream.open(path, std::ios::app);
    stream << name << " " << surname << " " << date << " " << summ << std::endl;
    stream.close();
}