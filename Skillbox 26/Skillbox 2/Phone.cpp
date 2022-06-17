#include "Phone.h"

void Phone::add() {
    phoneBook.push_back(Contact::createContact());
}

void Phone::call() {
    std::string input;
    std::cout << "Enter account name or number:" << std::endl;
    std::cin >> input;

    if (input[0] == '+') {
        if (findByNumber(input)) std::cout << "Calling " << input << " ... " << std::endl;
        else std::cout << "No contact with such number." << std::endl;
    } else {
        if (findByName(input)) std::cout << "Calling " << input << " ... " << std::endl;
        else std::cout << "No contact with such name." << std::endl;
    }
}

void Phone::sms() {
    std::string input, text;
    std::cout << "Enter account name or number:" << std::endl;
    std::cin >> input;

    if (input[0] == '+') {
        if (findByNumber(input)) {
            std::cout << "Enter your message:" << std::endl;
            std::cin.get();
            std::getline(std::cin, text);
            std::cout << "Message \"" << text << "\" sended to " << input << "." << std::endl;
        } else std::cout << "No contact with such number." << std::endl;
    } else {
        if (findByName(input)) {
            std::cout << "Enter your message:" << std::endl;
            std::cin.get();
            std::getline(std::cin, text);
            std::cout << "Message \"" << text << "\" sended to " << input << "." << std::endl;
        } else std::cout << "No contact with such name." << std::endl;
    }
}


bool Phone::findByNumber(std::string number) {
    for (Contact c: phoneBook) {
        if (c.getNumber() == number) return true;
    }
    return false;
}

bool Phone::findByName(std::string name) {
    for (Contact c: phoneBook) {
        if (c.getName() == name) return true;
    }
    return false;
}