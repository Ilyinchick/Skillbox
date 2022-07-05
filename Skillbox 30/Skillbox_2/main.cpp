#include <iostream>
#include <cpr/cpr.h>

int main() {
    std::string name = "name";
    cpr::Response r = cpr::Get(cpr::Url("httpbin.org/html"), cpr::Header( {{"Accept", "text/html"}}));
    for (int i = r.text.find("<h1>") + 4; i < r.text.find("</h1>"); i++) {
        std::cout << r.text[i];
    }
    return 0;
}
