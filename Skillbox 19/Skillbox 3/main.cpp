#include <iostream>
#include <fstream>
#include <vector>

const std::string path = "C:\\Users\\ailyi\\CLionProjects\\Skillbox\\Skillbox 19\\Skillbox 3\\data.txt";

std::vector<std::string> names;
std::vector<std::string> surnames;
std::vector<int> money;
std::vector<std::string> dates;

void fillVectors(std::string path);

int summOfMoney();

std::string richestMan();

int fingRichest();

int main() {
    fillVectors(path);
    std::cout << summOfMoney() << std::endl;
    std::cout << richestMan() << std::endl;
    return 0;
}

void fillVectors(std::string path) {
    std::string strDummy;
    int intDummy;
    std::ifstream stream;

    stream.open(path);
    if (stream.is_open()) {
        do {
            strDummy = "";
            intDummy = 0;

            stream >> strDummy;
            names.push_back(strDummy);

            stream >> strDummy;
            surnames.push_back(strDummy);

            stream >> intDummy;
            money.push_back(intDummy);

            stream >> strDummy;
            dates.push_back(strDummy);
        } while (!stream.eof());
    } else {
        std::cout << "File is not opened. Incorrect path." << std::endl;
    }
    stream.close();
}

int summOfMoney() {
    int summ = 0;
    for (int i: money) {
        summ += i;
    }
    return summ;
}

std::string richestMan() {
    std::string fullname = names[fingRichest()] + " " + surnames[fingRichest()];
    return fullname;
}

int fingRichest() {
    int richestIndex = 0, wallet = 0;
    for (int i = 0; i < money.size(); i++) {
        if (wallet < money[i]) {
            wallet = money[i];
            richestIndex = i;
        }
    }
    return richestIndex;
}
