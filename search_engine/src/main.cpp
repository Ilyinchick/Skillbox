#include <iostream>
#include "../include/ConverterJSON.h"


int main() {
    auto atw = new ConverterJSON();
    std::cout << atw->print() << std::endl;
    return 0;
}
