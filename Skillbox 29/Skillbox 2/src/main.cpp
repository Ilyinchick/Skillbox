#include "Circle.h"
#include "Rectangle.h"
#include "Triangle.h"

int main() {
    Circle c(5);
    Rectangle r(5, 7);
    Triangle t(3, 5, 5);

    Shape::printParams(&t);
    return 0;
}
