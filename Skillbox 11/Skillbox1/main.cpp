#include <iostream>

std::string encrypt_cezar(std::string str, int key);

std::string decrypt_cezar(std::string str, int key);

bool isValidSymbol(char c);

int main() {
    std::string str;
    int key;

    std::cout << "Enter text to encrypt: " << std::endl;
    getline(std::cin, str);
    std::cout << "Enter key to encrypt: " << std::endl;
    std::cin >> key;

    str = encrypt_cezar(str, key);
    std::cout << str;
    std::cout << "\nDecrypt: \n" << decrypt_cezar(str, key) << std::endl;
}

bool isValidSymbol(char c) {
    if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122)) return true;
    else return false;
}

std::string encrypt_cezar(std::string str, int key) {
    int cryptSymbol;

    for (char &i: str) {

        if (isValidSymbol(i)) {
            cryptSymbol = (int)i;

            for (int x = 0; x < key; x++) {
                cryptSymbol++;
                if (cryptSymbol == 123) cryptSymbol = 65;
                if (cryptSymbol == 91) cryptSymbol = 97;
            }
            i = (char)cryptSymbol;
        }
    }
    return str;
}

std::string decrypt_cezar(std::string str, int key) {
    return encrypt_cezar(str, std::abs(key%52 - 52));
}