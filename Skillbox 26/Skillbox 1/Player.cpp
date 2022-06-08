#include <string>
#include <vector>
#include "Track.cpp"

class Player {
    std::vector<Track> trackList;
    Track activeTrack;


public:

    void play() {
        Track *track = new Track();
        track->initializeTrack();
        trackList.push_back(*track);
        activeTrack = *track;
        activeTrack.play();
    }

    void pause() {
        activeTrack.pause();
    }

    void next() {
        nextTrack();
        activeTrack.setStatus(true);
        activeTrack.play();
    }

    void stop() {
        if (!activeTrack.getStatus()) {
            nextTrack();
            activeTrack.setStatus(true);
            std::cout << "Stopped" << std::endl;
        }
    }



    void nextTrack() {
        int i = std::rand() % trackList.size();
        activeTrack = trackList[i];
    }

    Track getActiveTrack() {
        return activeTrack;
    }

    int getTrackListSize() {
        return trackList.size();
    }
};
