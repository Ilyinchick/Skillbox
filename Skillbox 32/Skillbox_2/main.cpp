#include <iostream>
#include <nlohmann/json.hpp>
#include <fstream>


void fillDb() {
    nlohmann::json db;
    db["The Shawshank Redemption"] = {{"country",            "USA"},
                                      {"date",               1994},
                                      {"production company", "Castle Rock Entertainment"},
                                      {"screenplay by",      "Frank Darabont"},
                                      {"directed by",        "Frank Darabont"},
                                      {"produced by",        "Niki Marvin"},
                                      {"actors",             {{"Tim Robbins", "Andy Dufresne"}, {"Morgan Freeman", "Ellis Boyd Red Redding"}, {"Bob Gunton", "Samuel Norton"}}}};

    db["Gladiator"] = {{"country",            "USA"},
                       {"date",               2000},
                       {"production company", "DreamWorks Pictures"},
                       {"screenplay by",      "David Franzoni"},
                       {"directed by",        "Ridley Scott"},
                       {"produced by",        "Douglas Wick"},
                       {"actors",             {{"Russell Crowe", "Maximus Decimus Meridius"}, {"Joaquin Phoenix", "Commodus"}, {"Connie Nielsen", "Lucilla"}}}};

    db["Green Mile"] = {{"country",            "USA"},
                        {"date",               1999},
                        {"production company", "Castle Rock Entertainment"},
                        {"screenplay by",      "Frank Darabont"},
                        {"directed by",        "Frank Darabont"},
                        {"produced by",        "Frank Darabont"},
                        {"actors",             {{"Tom Hanks", "Paul Edgecomb"}, {"David Morse", "Brutus Brutal Howell"}, {"Bonnie Hunt", "Jan Edgecomb"}}}};

    db["Forrest Gump"] = {{"country",            "USA"},
                          {"date",               1994},
                          {"production company", "The Tisch Company"},
                          {"screenplay by",      "Eric Roth"},
                          {"directed by",        "Robert Zemeckis"},
                          {"produced by",        "Steve Starkey"},
                          {"actors",             {{"Tom Hanks", "Forrest Gump"}, {"Robin Wright", "Jenny Curran"}, {"Gary Sinise", "Lieutenant Dan Taylor"}}}};

    db["The Godfather"] = {{"country",            "USA"},
                           {"date",               1972},
                           {"production company", "Paramount Pictures"},
                           {"screenplay by",      "Francis Ford Coppola"},
                           {"directed by",        "Francis Ford Coppola"},
                           {"produced by",        "Albert S. Ruddy"},
                           {"actors",             {{"Marlon Brando", "Vito Corleone"}, {"Al Pacino", "Michael Corleone"}, {"James Caan", "Sonny"}}}};

    std::ofstream file("films.json");
    file << db;
    file.close();

}

int main() {
    //fillDb();
    std::string name;
    std::cout << "Enter actor's name: " << std::endl;
    std::cin >> name;

    std::ifstream inFile("films.json");
    nlohmann::json db;
    inFile >> db;
    for (auto&[key, val]: db.items()) {
        for (auto&[inkey, inval]: val.find("actors")->items())
            if (((std::string) inkey).find(name) != std::string::npos) {
                std::cout << key << ": " << inkey << " - " << inval << std::endl;
            }
    }
    return 0;
}
