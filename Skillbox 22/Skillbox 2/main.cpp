#include <iostream>
#include <map>

int main() {
    std::map<std::string, std::string> oMap;
    int counter = 0;
    std::string str;
    while (true) {
        std::cout << "Enter your command: " << std::endl;
        std::cin >> str;
        if (str == "exit") break;
        else if (str == "Next") {
            if (oMap.empty()) {
                std::cout << "Queue is empty" << std::endl;
            } else {
                std::cout << oMap.begin()->second << std::endl;
                oMap.erase(oMap.begin()->first);
            }
        } else  {
            oMap.insert(std::make_pair(str[0] + std::to_string(counter), str));
            counter++;
        }
    }
    return 0;
}
