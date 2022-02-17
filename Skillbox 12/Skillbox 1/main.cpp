#include <iostream>

int main() {
    std::string residents[10];
    int index;

    std::cout << "Enter residents: " << std::endl;

    for (int i = 0; i < 10; i++) {
        std::cin >> residents[i];
    }

    for (int i = 0; i < 3; i++) {
        do {
            std::string str;
            char a;
            std::cout << "Enter flat's number: ";
            std::cin >> str;
            if (str.length() > 1 && str[0] == '1' && str[1] == '0') index = 10;
            else {
                a = str[0];
                if (a < 48 || a > 57) continue;
                else index = a - 48;
            }
            if (index < 0 || index > 10) continue;
        } while (index < 0 || index > 10);
        std::cout << residents[index-1] << std::endl;
    }

    return 0;
}

