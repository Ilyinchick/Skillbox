#include "Player.h"


void Player::play() {
    Track *track = new Track();
    track->initializeTrack();
    trackList.push_back(*track);
    activeTrack = *track;
    activeTrack.play();
}

void Player::pause() {
    activeTrack.pause();
}

void Player::next() {
    nextTrack();
    activeTrack.setStatus(true);
    activeTrack.play();
}

void Player::stop() {
    if (!activeTrack.getStatus()) {
        nextTrack();
        activeTrack.setStatus(true);
        std::cout << "Stopped" << std::endl;
    }
}


void Player::nextTrack() {
    int i = std::rand() % trackList.size();
    activeTrack = trackList[i];
}

Track Player::getActiveTrack() {
    return activeTrack;
}

int Player::getTrackListSize() {
    return trackList.size();
}
