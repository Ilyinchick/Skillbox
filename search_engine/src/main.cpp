#include <iostream>
#include "../include/ConverterJSON.h"
#include "../include/fs_exception.h"

const std::string CONFIG_FILE_PATH = R"(C:\Users\ailyi\CLionProjects\Skillbox\search_engine\manage\config.json)";
const std::string REQUESTS_FILE_PATH = R"(C:\Users\ailyi\CLionProjects\Skillbox\search_engine\manage\requests.json)";

int main() {
    auto atw = new ConverterJSON();

    try {
        atw->testRequestsJson(REQUESTS_FILE_PATH);
    }
    catch (FileNotFoundException& ex) {
        std::cout << ex.what() << std::endl;
    }
    catch (EmptyFileException& ex) {
        std::cout << ex.what() << std::endl;
    }
    catch (NoConfigFieldException& ex) {
        std::cout << ex.what() << std::endl;
    }
    catch (ConfigFieldIsEmptyException& ex) {
        std::cout << ex.what() << std::endl;
    }
    catch (IncorrectVersionJsonException& ex) {
        std::cout << ex.what() << std::endl;
    }
    catch (NoRequestsFieldException& ex) {
        std::cout << ex.what() << std::endl;
    }
    catch(EmptyRequestsFieldException& ex) {
        std::cout << ex.what() << std::endl;
    }
    return 0;
}
