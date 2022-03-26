#include <iostream>
#include "ram.h"
#include "cpu.h"
#include "gpu.h"
#include "disk.h"
#include "kbd.h"
#include "inputControl.h"


int main() {
    std::string str;
    do {
        str = enterString();
        if (str == "exit") break;
        else if (str == "sum") compute(getRam());
        else if (str == "save") save(getRam());
        else if (str == "load") load(getRam());
        else if (str == "display") display(getRam());
        else input(getRam());
    } while (true);

    return 0;
}
