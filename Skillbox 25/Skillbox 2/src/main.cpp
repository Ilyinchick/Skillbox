#include <iostream>
#include "cpu.h"
#include "gpu.h"
#include "disk.h"
#include "kbd.h"
#include "ram.h"

int main() {
    std::string str;
    do {
        str = enterString();
        if (str == "exit") break;
        else if (str == "summ") compute(ram);
        else if (str == "save") save(ram);
        else if (str == "load") load(ram);
        else if (str == "display") display(ram);
        else input(ram);
    } while (true);

    return 0;
}
