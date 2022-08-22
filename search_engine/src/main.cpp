#include "../include/ConverterJSON.h"
#include "../include/fs_exception.h"
#include "../include/InvertredIndex.h"


int main() {
    auto example = new InvertedIndex();
    example->UpdateDocumentBase();
    //example->printWords();
    return 0;
}
