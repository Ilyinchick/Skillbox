#include "../include/ConverterJSON.h"
#include "../include/fs_exception.h"
#include "../include/InvertredIndex.h"


int main() {
    std::vector<std::vector<std::pair<int, float>>> vec;
    auto inverted = new InvertedIndex();
    auto converter = new ConverterJSON();
    inverted->UpdateDocumentBase(converter->GetTextDocuments());
    for (auto& word: inverted->getDictionary()) {
        std::cout << word.first << " ";
    }

    return 0;
}
