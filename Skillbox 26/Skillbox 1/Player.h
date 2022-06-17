#pragma once

#include <string>
#include <vector>
#include "Track.h"

class Player {
    std::vector<Track> trackList;
    Track activeTrack;

public:

    void play();

    void pause();

    void next();

    void stop();

    void nextTrack();

    Track getActiveTrack();

    int getTrackListSize();
};
