#include <iostream>
#include <string>
#include <sstream>

enum {
    POWER = 1,
    OUTLETS = 2,
    IN_LIGHT = 4,
    OUT_LIGHT = 8,
    HOUSE_HEATING = 16,
    BOILER = 32,
    AIR_CONDITIONER = 64
};

int state = 0;

int inTemp;
int outTemp;
std::string timeH = "00:00";
bool movement;
bool light;
int lightTemp;


void inputValues();

void print();

void timeIncrease();

void controlSwitches();

void inLight(bool light);

void outLight();

void tempLight();

void boiler();

void houseHeating();

void conditioner();

void checkLightInput(std::string str);

void checkMovementInput(std::string str);

int getTime();

int main() {
    state |= POWER;
    state |= OUTLETS;

    for (int i = 0; i < 48; i++) {
        print();
    }
    return 0;
}

void print() {
    std::cout << "Time is " << timeH << "." << std::endl;
    inputValues();
    controlSwitches();
    timeIncrease();
}

void inputValues() {
    std::stringstream text;
    std::string values, isMovement, lightStatus;

    std::cout << "Enter indoor and outdoor temperature, is movement outdoor (yes/no) and light status (on/off): " << std::endl;
    std::getline(std::cin, values);

    text << values;
    text >> inTemp >> outTemp >> isMovement >> lightStatus;

    checkMovementInput(isMovement);
    checkLightInput(lightStatus);
}

void checkLightInput(std::string str) {
    if (str == "on") {
        light = true;
    } else if (str == "off") {
        light = false;
    } else {
        std::cout << "Invalid data, try again." << std::endl;
        inputValues();
    }
    inLight(light);
}

void checkMovementInput(std::string str) {
    if (str == "yes") {
        movement = true;
    } else if (str == "no") {
        movement = false;
    } else {
        std::cout << "Invalid data, try again." << std::endl;
        inputValues();
    }
}

void timeIncrease() {
    int timeValue = getTime();
    timeValue++;
    if (timeValue == 24) timeValue = 0;
    if (timeValue < 10) timeH = "0" + std::to_string(timeValue) + ":00";
    else timeH = std::to_string(timeValue) + ":00";
}

void controlSwitches() {
    outLight();
    tempLight();
    boiler();
    houseHeating();
    conditioner();
}

void inLight(bool light) {
    if (!(state & IN_LIGHT) && light) {
        std::cout << "Light is on." << std::endl;
        state |= IN_LIGHT;
    } else if ((state & IN_LIGHT) && !light) {
        std::cout << "Light is off." << std::endl;
        state &= ~IN_LIGHT;
    }
}

void outLight() {
    int timeValue = getTime();
    if ((timeValue > 16 || timeValue < 5) && movement && !(state & OUT_LIGHT)) {
        state |= OUT_LIGHT;
        std::cout << "Out light is on." << std::endl;
    } else if ((state & OUT_LIGHT) && !movement) {
        state &= ~OUT_LIGHT;
        std::cout << "Out light is off." << std::endl;
    }
}

void tempLight() {
    int timeValue = getTime();
    if (state & IN_LIGHT && (timeValue >= 16 && timeValue < 20)) {
        lightTemp = 5000 - (2300/4) * (timeValue - 15);
    }
    if (timeValue < 1) lightTemp = 5000;
    if (state & IN_LIGHT)  std::cout << "Light temperature is " << lightTemp << "K." << std::endl;
}

void boiler() {
    if (!(state & BOILER) && outTemp < 0) {
        std::cout << "Boiler is on." << std::endl;
        state |= BOILER;
    } else if ((state & BOILER) && outTemp > 5) {
        std::cout << "Boiler is off." << std::endl;
        state &= ~BOILER;
    }
}

void houseHeating() {
    if (!(state & HOUSE_HEATING) && inTemp < 22) {
        std::cout << "House heating is on." << std::endl;
        state |= HOUSE_HEATING;
    } else if ((state & HOUSE_HEATING) && inTemp >= 25) {
        std::cout << "House heating is off." << std::endl;
        state &= ~HOUSE_HEATING;
    }
}

void conditioner() {
    if (!(state & AIR_CONDITIONER) && inTemp >= 30) {
        std::cout << "Air conditioner is on." << std::endl;
        state |= AIR_CONDITIONER;
    } else if ((state & AIR_CONDITIONER) && inTemp <= 25) {
        std::cout << "Air conditioner is off." << std::endl;
        state &= ~AIR_CONDITIONER;
    }
}

int getTime() {
    std::string str;
    str += timeH[0];
    str += timeH[1];
    int timeValue = std::stoi(str);
    return timeValue;
}

