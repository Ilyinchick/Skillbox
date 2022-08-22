#include "../include/InvertredIndex.h"
#include "../include/ConverterJSON.h"

void InvertedIndex::updateDocs() {
    auto converter = new ConverterJSON();
    docs = converter->GetTextDocuments();
    delete converter;
}

std::vector<Entry> InvertedIndex::GetWordCount(const std::string &word) {
    std::vector<Entry> vector;
    for (int i = 0; i < docs.size(); i++) {
        std::string data = docs[i];
        for (char &c: data) c = (char) tolower(c);
        Entry entry = {i, countWordsInStr(word, data)};
        if (entry.count > 0) vector.push_back(entry);
    }
    return vector;
}

int InvertedIndex::countWordsInStr(const std::string &word, const std::string &str) {
    if (str.find(word) != std::string::npos) {
        return 1 + countWordsInStr(word, str.substr(str.find(word) + word.length(), str.length()));
    } else return 0;
}

void InvertedIndex::UpdateDocumentBase() {
    updateDocs();
    updateWordsBase();

}

void InvertedIndex::updateWordsBase() {
    wordsBase.clear();

    for (auto &str: docs) {
        std::string word;
        for (auto &c: str) {
            word.append(&c);
        }
        std::cout << word;
    }
//        for (int i = 0; i < str.length(); i++) {
//            if (str[i] != ' ' && str[i] != '\n') {
//                word.append(&str[i]);
//            } else {
//                if (word.length() != 0) {
//                    std::cout << "insert " << word << std::endl;
//                    wordsBase.insert(word);
//                    word.clear();
//                }
//            }
//        }
}


void InvertedIndex::printWords() {
    for (auto &word: wordsBase) {
        std::cout << word << std::endl;
    }
}


