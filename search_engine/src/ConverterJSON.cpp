#include "../include/ConverterJSON.h"
#include "fstream"
#include "iostream"
#include "fs_exception.h"


std::string ConverterJSON::getDoc(std::string path) {
    std::ifstream file;
    std::string answer, buff;

    file.open(path);
    if (!file.is_open())  throw FileNotFoundException();

    while(file) {
        std::getline(file, buff);
        answer.append(buff.append(" "));
        buff.clear();
    }

    if (answer.length() <= 1)   throw EmptyFileException();

    return answer;
}
