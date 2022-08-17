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
