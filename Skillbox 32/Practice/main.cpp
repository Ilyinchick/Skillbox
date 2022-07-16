#include <iostream>
#include <fstream>
#include "nlohmann/json.hpp"

struct Some {
    std::string name;
    std::string surname;
    int age;
};

int main() {
    Some s, s2;
    std::ofstream file("record.json");


    s = {"Mike", "Vazovskiy", 20};

    nlohmann::json obj = {
            {"name", s.name},
            {"surname", s.surname},
            {"age", s.age}}, obj2;

    file << obj;
    file.close();

    std::ifstream input("record.json");
    input >> obj2;

    s2.name = obj2["name"];
    s2.surname = obj2["surname"];
    s2.age = obj2["age"];

    std::cout << s2.name << " " << s2.surname << " " << s2.age << std::endl;

    input.close();


    return 0;
}

