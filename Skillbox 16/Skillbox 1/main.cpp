#include <iostream>
#include <string>

void printStr(float number);

float speedup();

float isValid();

char text[100];
float currentSpeed = 0;

int main() {

    do {
        currentSpeed = speedup();
        std::cout << text << std::endl;
    } while (currentSpeed > 0);

    std::cout << "Congratulations!" << std::endl;
    return 0;
}

void printStr(float number) {
    std::sprintf(text, "Current speed is %.2f km/h.", number);
}

float speedup() {
    float delta;
    std::cout << "Enter speed to increase: " << std::endl;
    std::cin >> delta;
    currentSpeed += delta;
    currentSpeed = isValid();
    printStr(currentSpeed);
    return currentSpeed;
}

float isValid() {
    if (currentSpeed <= 0) {
        std::cout << "You has stopped." << std::endl;
        return 0;
    } else if (currentSpeed >= 150) {
        std::cout << "You have already reached high limit of speed is 150 km/h" << std::endl;
        return 150;
    } else return currentSpeed;
}
