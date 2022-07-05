#include "Dog.h"
#include "Counting.h"
#include "Swimming.h"
#include "Dancing.h"

int main() {
    Dog d;

    d.addTalent(new Counting());
    //d.addTalent(new Dancing());
    d.addTalent(new Swimming());

    d.showTalents();

    return 0;
}
