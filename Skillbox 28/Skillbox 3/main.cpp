#include <iostream>
#include <queue>
#include <thread>
#include <mutex>
#include <assert.h>


std::mutex m;

std::queue<std::string> waiter;
std::queue<std::string> kitchen;
std::queue<std::string> courier;

bool isKitchenAvailable = true;

int range(int min, int max) {
    return std::rand() % (max - min) + min + 1;
}

std::string randomMeal() {
    int rand = std::rand() % 5;
    if (rand == 0) return "Pizza";
    else if (rand == 1) return "Soup";
    else if (rand == 2) return "Steak";
    else if (rand == 3) return "Sushi";
    else if (rand == 4) return "Salad";
    else std::cout << "Error in randomizer" << std::endl;
    return "Error";
}

void cookMeal(std::string meal) {
    std::cout << "Order for " << meal << " is ready to deliver." << std::endl;
    isKitchenAvailable = false;
    kitchen.push(meal);
    waiter.pop();
}

void generateMeals() {
    while (courier.size() < 10) {
        std::this_thread::sleep_for(std::chrono::seconds(range(5, 10)));
        m.lock();
        waiter.push(randomMeal());
        std::cout << "Order for " << waiter.back() << " is taken." << std::endl;
        m.unlock();
    }
}

void cookMeals() {
    while (courier.size() < 10) {
        if (isKitchenAvailable && !waiter.empty()) {
            std::this_thread::sleep_for(std::chrono::seconds(range(5, 15)));
            m.lock();
            cookMeal(waiter.front());
            m.unlock();
            isKitchenAvailable = true;
        }
    }
}

void takeTasks() {
    while (courier.size() < 10) {
        std::this_thread::sleep_for(std::chrono::seconds(30));
        while (kitchen.size() > 0) {
            courier.push(kitchen.front());
            std::cout << "Meal " << kitchen.front() << " delivered." << std::endl;
            kitchen.pop();
        }
        std::cout << "Total " << courier.size() << " meals delivered." << std::endl;
    }

}

int main() {

    std::thread waiterThread(generateMeals);
    std::thread chefThread(cookMeals);
    std::thread courierThread(takeTasks);

    chefThread.join();
    waiterThread.join();
    courierThread.join();

    return 0;
}
