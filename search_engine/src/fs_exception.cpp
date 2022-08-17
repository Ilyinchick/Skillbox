#include "fs_exception.h"

const char *fs_exception::what() const noexcept {
    return "File system exception";
}

const char *FileNotFoundException::what() const noexcept {
    return "File not found!";
}

const char *EmptyFileException::what() const noexcept {
    return "File is empty!";
}

const char *NoConfigFieldException::what() const noexcept {
    return "No \"config\" field!";
}

const char *ConfigFieldIsEmptyException::what() const noexcept {
    return "\"Config\" field is empty!";
}
