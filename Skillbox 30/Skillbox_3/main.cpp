#include <iostream>
#include <cpr/cpr.h>

void doGet(std::map<std::string, std::string> *map) {
    std::string url = "httpbin.org/get?";
    std::map<std::string, std::string>::iterator it;
    for (it = map->begin(); it != map->end(); it++) {
        if (it != map->begin()) url.append("&");
        url.append(it->first).append("=").append(it->second);
    }
    cpr::Response r = cpr::Get(cpr::Url(url));
    std::cout << r.text;
}

void doPost(std::map<std::string, std::string> *map) {
    std::map<std::string, std::string>::iterator it;
    cpr::Payload p{{}};
    for (it = map->begin(); it != map->end(); it++) {
        p.Add(cpr::Pair(it->first, it->second));
    }
    cpr::Response r = cpr::Post(cpr::Url("httpbin.org/post"),   p);
    std::cout << r.text;
}


int main() {
    std::map<std::string, std::string> args;
    std::string command, value;

    while (command != "post" && command != "get") {
        std::cout << "Enter your command: " << std::endl;
        std::cin >> command;
        if (command != "post" && command != "get") {
            std::cout << "Enter value for this argument: " << std::endl;
            std::cin >> value;
            args.insert(std::make_pair(command, value));
        }
    }
    if (command == "get") {
        doGet(&args);
    } else {
        doPost(&args);
    }
    return 0;
}
