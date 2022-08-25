#include "../include/InvertredIndex.h"
#include "../include/ConverterJSON.h"

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
    if (str.find(word) != std::string::npos && ( str.find(word) == 0) || str[(str.find(word) - 1)] == ' ') {
        return 1 + countWordsInStr(word, str.substr(str.find(word) + word.length(), str.length()));
    } else return 0;
}

void InvertedIndex::UpdateDocumentBase(std::vector<std::string> _docs) {
    docs = std::move(_docs);
    freq_dictionary.clear();

    for (auto& word: getWordsBaseFromDoc(docs)) {
        freq_dictionary.insert(std::make_pair(word, GetWordCount(word)));
    }
}


std::map<std::string, std::vector<Entry>> InvertedIndex::getDictionary() {
    return freq_dictionary;
}



