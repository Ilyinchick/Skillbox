#include "ram.h"

int ram[8];

void write() {
    input(ram);
}

void read() {
    display(ram);
}

int* getRam() {
    return ram;
}