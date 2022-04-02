#include "Player.cpp"
#include <iostream>

void initializeTrackList(Player* player);

std::string enterStr();

int main() {
    Player* player = new Player;
    initializeTrackList(player);
    std::string str;
    while (true) {
        str = enterStr();
        if (str == "exit") break;
        else if (str == "play") {
        std::cout << "Enter track name: " << std::endl;
        std::string trackName;
        std::cin >> trackName;
        player->play(trackName);
        } else if (str == "pause") player->pause();
        else if (str == "next") player->next();
        else player->stop();
    }
    delete player;
    player = nullptr;
    return 0;
}

void initializeTrackList(Player* player) {
    std::time_t t = std::time(nullptr);
    std::tm date = *std::localtime(&t);

    std::string name;
    for (int i = 1; i <= 10; i ++) {
        Track* track = new Track();
        track->setName("Song#" + std::to_string(i));
        track->setDate(date);
        track->setDuration(i*2);
        track->setStatus(true);
        player->addTrack(track);
    }

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
