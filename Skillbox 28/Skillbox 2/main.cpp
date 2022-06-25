#include <iostream>
#include <thread>
#include <mutex>
#include <assert.h>

std::mutex m;
bool isStationAvailable = true;

void trainArrived(int number) {
    assert(isStationAvailable);
    isStationAvailable = false;
    std::string command;

    do {
        std::cout << "Train " << number << " arrived to a station.\nType 'depart' to depart it:" << std::endl;
        std::cin >> command;
        if (command != "depart") std::cout << "Invalid command. Try again." << std::endl;
    } while (command != "depart");

    std::cout << "Train " << number << " has been departed." << std::endl;
    isStationAvailable = true;
}

void train(int number, int time) {
    std::this_thread::sleep_for(std::chrono::seconds(time));
    if (!isStationAvailable) std::cout << "Train " << number << " is waiting in queue." << std::endl;
    m.lock();
    trainArrived(number);
    m.unlock();
}

int main() {
    std::thread t1(train, 1, 2);
    std::thread t2(train, 2, 15);
    std::thread t3(train, 3, 30);

    t1.join();
    t2.join();
    t3.join();

    return 0;
}
