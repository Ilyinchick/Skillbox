#include "Player.h"
#include <iostream>

std::string enterStr();

int main() {
    Player *player = new Player;
    std::string str;

    while (true) {
        str = enterStr();
        if (str == "exit") break;
        else if (str == "play") {
            if (player->getActiveTrack().getStatus() || player->getTrackListSize() < 1) player->play();
        } else if (str == "pause") player->pause();
        else if (str == "next") player->next();
        else player->stop();
    }
    delete player;
    player = nullptr;
    return 0;
}

std::string enterStr() {
    std::string str;
    std::cout << "Enter your command (play, pause, next, stop, exit): " << std::endl;
    std::cin >> str;
    if (str == "play" || str == "pause" || str == "next" || str == "stop" || str == "exit") return str;
    else {
        std::cout << "Invalid valuse. Try again." << std::endl;
        return enterStr();
    }
}
