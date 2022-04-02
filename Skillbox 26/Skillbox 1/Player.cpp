#include <string>
#include <vector>
#include "Track.cpp"

class Player {
    std::vector<Track> trackList;
    Track activeTrack;


public:
    void play(std::string name) {
        for (Track t: trackList) {
            if (t.getName() == name) {
                activeTrack = t;
                activeTrack.play();
                break;
            }
        }
    }

    void pause() {
        activeTrack.pause();
    }

    void next() {
        activeTrack.setStatus(true);
        nextTrack();
        activeTrack.play();
    }

    void stop() {
        if (!activeTrack.getStatus()) {
            nextTrack();
            activeTrack.setStatus(true);
            std::cout << "Paused" << std::endl;
        }
    }

    void nextTrack() {
        int i = std::rand() % trackList.size();
        activeTrack = trackList[i];
    }

    void addTrack(Track* track) {
        trackList.push_back(*track);
    }
};
