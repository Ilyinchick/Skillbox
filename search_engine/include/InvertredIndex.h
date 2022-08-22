#pragma once

#include <vector>
#include <string>
#include <map>
#include <set>

struct Entry {
    int doc_id, count;

    bool operator==(const Entry &other) const {
        return (doc_id == other.doc_id &&
                count == other.count);
    }
};

class InvertedIndex {

public:
    InvertedIndex() = default;

    /**
    * Обновить или заполнить базу документов, по которой будем совершать поиск
    * @param texts_input содержимое документов
    */
    void UpdateDocumentBase();


    /*
     * Метод определяет количество вхождений слова word в загруженной базе документов
    * @param word слово, частоту вхождений которого необходимо определить
    * @return возвращает подготовленный список с частотой слов
     */
    std::vector<Entry> GetWordCount(const std::string &word);


    void printWords();

private:

    std::vector<std::string> docs; // список содержимого документов
    std::map<std::string, std::vector<Entry>> freq_dictionary; // частотный
    std::set<std::string> wordsBase;

    void updateDocs();

    void updateWordsBase();

    int countWordsInStr(const std::string& word, const std::string& str);


};