#include <iostream>
#include <math.h>

struct vec {
    float x, y;
    void print() {
        std::cout << "(" << x << ", " << y << ")" << std::endl;
    }
};

void add(vec* example);

void subtract(vec* example);

void scale(vec* example);

void length(vec* example);

void normalize(vec* example);

std::string inputCommand();

void control(std::string command, vec* example);

float enterFloat();

void enterVec(vec* example);


int main() {
    std::string command;
    vec example;

    enterVec(&example);
    example.print();
    command = inputCommand();
    control(command, &example);

    return 0;
}

std::string inputCommand() {
    std::string str;
    std::cout << "Enter your command: (add, subtract, scale etc.) " << std::endl;
    std::cin >> str;
    if (str == "subtract" || str == "scale" || str == "add" || str == "normalize" || str == "length") {
        return str;
    } else {
        std::cout << "Incorrect command, try again.." << std::endl;
        inputCommand();
    }
}

void control(std::string command, vec* example) {
    if (command == "add") add(example);
    if (command == "subtract") subtract(example);
    if (command == "scale") scale(example);
    if (command == "normalize") normalize(example);
    if (command == "length") length(example);
}

float enterFloat() {
    float f;
    std::cout << "Enter number: " << std::endl;
    std::cin >> f;
    return f;
}

void enterVec(vec* example) {
    example -> x = enterFloat();
    example -> y = enterFloat();
}

void add(vec* example) {
    std::cout << "Enter operant to add. " << std::endl;
    example -> x += enterFloat();
    example -> y += enterFloat();
    std::cout << "Result vector: ";
    example->print();
}

void subtract(vec* example) {
    std::cout << "Enter operant to subtract. " << std::endl;
    example -> x -= enterFloat();
    example -> y -= enterFloat();
    std::cout << "Result vector: ";
    example->print();
}

void scale(vec* example) {
    float scale;
    std::cout << "Enter scale to multiply: " << std::endl;
    scale = enterFloat();
    example -> x *= scale;
    example -> y *= scale;
    std::cout << "Result vector: ";
    example->print();
}

void length(vec* example) {
    float lenght;
    lenght = sqrt( pow((example -> x), 2) + pow((example -> y), 2) );
    std::cout << "Vector's lenght is " << lenght;
}

void normalize(vec* example) {
    float lenght;
    lenght = sqrt( pow((example -> x), 2) + pow((example -> y), 2) );
    example -> x /= lenght;
    example -> y /= lenght;
    std::cout << "Result vector: ";
    example->print();
}

