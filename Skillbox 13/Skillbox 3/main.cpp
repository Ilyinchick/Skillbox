#include <iostream>
#include <vector>
#include <string>

void printDb(int counter);

std::vector <int> db(20, 0);

int main() {

    int n = 0, counter = 0;
    std::cout << "Enter visitors list: " << std::endl;
     do {
        std::cin >> n;
         if (n == -1) {
             printDb(counter);
             break;
         }  else {
             if (counter == 19) counter = 0;
             db[counter] = n;
             counter++;
         }
    } while (true);

    return 0;
}

void printDb(int counter) {
    std::string str;
    for (int i = counter; i < db.size(); i++) {
        if (db[i] != 0) str += std::to_string(db[i]) + " ";
    }
    for (int i = 0; i < counter; i++) {
        if (db[i] != 0) str += std::to_string(db[i]) + " ";
    }
    std::cout << str;
}