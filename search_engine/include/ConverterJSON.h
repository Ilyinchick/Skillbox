#include <string>
#include <vector>
#include "nlohmann/json.hpp"

class ConverterJSON {

public:

    const std::string CONFIG_PATH = R"(C:\Users\ailyi\CLionProjects\Skillbox\search_engine\manage\config.json)";
    const std::string REQUESTS_PATH = R"(C:\Users\ailyi\CLionProjects\Skillbox\search_engine\manage\requests.json)";
    const std::string ANSWERS_PATH = R"(C:\Users\ailyi\CLionProjects\Skillbox\search_engine\manage\answers.json)";

    ConverterJSON() = default;

/**
* Метод получения содержимого файлов
* @return Возвращает список с содержимым файлов перечисленных
* в config.json
*/
    std::vector<std::string> GetTextDocuments();

/**
* Метод считывает поле max_responses для определения предельного
* количества ответов на один запрос
* @return
*/
    int GetResponsesLimit();

/**
* Метод получения запросов из файла requests.json
* @return возвращает список запросов из файла requests.json
*/
    std::vector<std::string> GetRequests();

/**
* Положить в файл answers.json результаты поисковых запросов
*/
    void putAnswers(std::vector<std::vector<std::pair<int, float>>> answers);

    void createAnswers();

private:
    static std::string getDoc(const std::string &path);

    static void testConfigJson(const std::string &path);

    static void testRequestsJson(const std::string &path);

    static nlohmann::json getJson(const std::string& path);

    nlohmann::json getConfigJson();

    nlohmann::json getRequestsJson();

};
