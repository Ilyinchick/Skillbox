#include <iostream>

bool substr(char* a, char* b);

int main() {
    char* a = "String";
    char* b = "ing";
    std::cout << substr(a, b) << std::endl;
    return 0;
}

bool substr(char* a, char* b) {
    int i = 0;
    while (*(a+i) != '\0') {
        int j = 0;
        while ( *(b+j) != '\0') {
            if ( *(a+i+j) != *(b+j)) {
                break;
            };
            j++;
        }
        if (*(b+j) == '\0') return true;
        i++;
    }
    return false;
}
