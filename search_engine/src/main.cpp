#include <iostream>
#include "../include/ConverterJSON.h"
#include "../include/fs_exception.h"

const std::string PATH = R"(C:\Users\ailyi\CLionProjects\Skillbox\search_engine\example1.txt)";

int main() {
    auto atw = new ConverterJSON();

    try {
        atw->testJson(R"(C:\Users\ailyi\CLionProjects\Skillbox\search_engine\manage\config.json)");
    }
    catch (FileNotFoundException ex) {
        std::cout << ex.what() << std::endl;
    }
    catch (EmptyFileException ex) {
        std::cout << ex.what() << std::endl;
    }
    catch (NoConfigFieldException ex) {
        std::cout << ex.what() << std::endl;
    }
    catch (ConfigFieldIsEmptyException ex) {
        std::cout << ex.what() << std::endl;
    }

    return 0;
}
