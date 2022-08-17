#include <string>

class ConverterJSON {
public:
    std::string getDoc(const std::string& path);

    void testConfigJson(const std::string& path);

    void testRequestsJson(const std::string& path);
};
