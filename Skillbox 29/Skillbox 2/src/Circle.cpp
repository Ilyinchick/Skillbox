#include "Circle.h"

double Circle::square() {
    return M_PI * radius * radius;
}

std::string Circle::getType() {
    return "Circle";
}

Shape::BoundingBoxDimensions Circle::dimensions() {
    return Shape::BoundingBoxDimensions(radius * 2, radius * 2);
}
