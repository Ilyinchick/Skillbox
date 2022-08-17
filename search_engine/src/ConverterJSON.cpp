#include "../include/ConverterJSON.h"
#include "fstream"
#include "iostream"
#include "fs_exception.h"
#include "nlohmann/json.hpp"

const std::string VERSION = "0.1";


std::string ConverterJSON::getDoc(const std::string& path) {
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

void ConverterJSON::testConfigJson(const std::string& path) {
    std::ifstream file(path);
    if (!file.is_open()) throw FileNotFoundException();

    nlohmann::json dict;
    file >> dict;
    if (dict.empty()) throw EmptyFileException();
    if (!dict.contains("config")) throw NoConfigFieldException();
    if (dict.find("config").value().empty()) throw ConfigFieldIsEmptyException();
    if (dict.find("config")->find("version").value() != VERSION) throw IncorrectVersionJsonException();

}

void ConverterJSON::testRequestsJson(const std::string &path) {
    std::ifstream file(path);
    nlohmann::json dict;

    if (!file.is_open()) throw FileNotFoundException();
    file >> dict;
    if (dict.empty()) throw EmptyFileException();
    if (!dict.contains("requests")) throw NoRequestsFieldException();
    if (dict.find("requests").value().empty()) throw EmptyRequestsFieldException();

}
