#include "Phone.h"

int main() {
    Phone *phone = new Phone();
    std::string control;
    do {
        std::cout << "Enter your command (add, call or sms): " << std::endl;
        std::cin >> control;
        if (control == "add") phone->add();
        else if (control == "call") phone->call();
        else if (control == "sms") phone->sms();
        else if (control != "exit") std::cout << "Invalid input. Try again." << std::endl;
    } while (control != "exit");
    return 0;
}
