#include "Circle.h"
#include "Rectangle.h"
#include "Square.h"
#include "Triangle.h"

int main() {
    Circle* c = new Circle(new Coordinate(1, 2), 3);
    Rectangle* r = new Rectangle(new Coordinate(), 3, 4);
    Square* s = new Square(new Coordinate(10, -3), 12);
    Triangle* t = new Triangle(new Coordinate(-10, 20), 5);

    c->print();
    r->print();
    s->print();
    t->print();

    delete c;
    delete r;
    delete s;
    delete t;

    return 0;
}
