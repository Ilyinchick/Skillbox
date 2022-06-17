#include "Contact.h"
#include "InputControl.h"

Contact Contact::createContact() {
    std::string nname, nnumber;
    std::cout << "Enter contact name: " << std::endl;
    std::cin >> nname;
    do {
        std::cout << "Enter contact number: " << std::endl;
        std::cin >> nnumber;
        if (!checkNumber(nnumber)) std::cout << "Invalid value. Try Again." << std::endl;
    } while (!checkNumber(nnumber));
    Contact *contact = new Contact();
    contact->name = nname;
    contact->number = nnumber;
    return *contact;
}

std::string Contact::getName() {
    return name;
}

std::string Contact::getNumber() {
    return number;
}
