#include "Swimmer.h"
#include <thread>
#include <vector>
#include <mutex>

std::vector<Swimmer*> swimmers;

std::vector<Swimmer*> sorted;
std::mutex m;

void swim(Swimmer* s) {
    int distance = 0, time = 0;
    while (distance < 100) {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        time++;
        distance = time * s->getSpeed();
        if (distance > 100) distance = 100;
        std::cout << s->getName() << " swam " << distance << " meters." << std::endl;
    }
    s->setTotalTime(time);
    std::cout << s->getName() << " has finished!" << std::endl;

    m.lock();
    sorted.push_back(s);
    m.unlock();
}

void initVector() {
    std::string name;
    int speed;

    m.lock();
    for (int i = 0; i < 6; i++) {
        std::cout << "Enter name for swimmer #" << i+1 << ": " << std::endl;
        std::cin >> name;
        std::cout << "Enter speed for swimmer: " << std::endl;
        std::cin >> speed;
        swimmers.push_back(new Swimmer(name, speed));
    }
    m.unlock();
}

void clearVectors() {
    for (Swimmer* s: swimmers) {
        s = nullptr;
        delete s;
    }
    for (Swimmer* s: sorted) {
        s = nullptr;
        delete s;
    }
}

void printSorted() {
    for (Swimmer* s: sorted) {
        std::cout << s->getName() << " has finished with total time is " << s->getTotalTime() << "." << std::endl;
    }
}

int main() {
    initVector();

    std::thread s1(swim, swimmers[0]);
    std::thread s2(swim, swimmers[1]);
    std::thread s3(swim, swimmers[2]);
    std::thread s4(swim, swimmers[3]);
    std::thread s5(swim, swimmers[4]);
    std::thread s6(swim, swimmers[5]);

    s1.join();
    s2.join();
    s3.join();
    s4.join();
    s5.join();
    s6.join();

    printSorted();
    clearVectors();

    return 0;
}
