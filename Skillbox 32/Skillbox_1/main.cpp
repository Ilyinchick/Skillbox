#include <iostream>
#include <fstream>
#include "nlohmann/json.hpp"

int main() {
    nlohmann::json film;
    film["name"] = "The Shawshank Redemption";
    film["country"] = "USA";
    film["date"] = 1994;
    film["production company"] = "Castle Rock Entertainment";
    film["screenplay by"] = "Frank Darabont";
    film["directed by"] = "Frank Darabont";
    film["produced by"] = "Niki Marvin";
    film["actors"] = {"Tim Robbins", "Morgan Freeman", "Bob Gunton", "William Sadler", "Clancy Brown", "Gil Bellows", "James Whitmore"};

    std::ofstream file("film.json");
    file << film;
    file.close();

    return 0;
}
