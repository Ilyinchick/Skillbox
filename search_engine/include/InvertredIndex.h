#pragma once

#include <vector>
#include <string>
#include <map>
#include <set>
#include <thread>
#include <mutex>
#include <iostream>
#include <assert.h>

static std::mutex locker;
static std::set<std::string> wordsBase;

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
    void UpdateDocumentBase(std::vector<std::string> docs);


    /*
     * Метод определяет количество вхождений слова word в загруженной базе документов
    * @param word слово, частоту вхождений которого необходимо определить
    * @return возвращает подготовленный список с частотой слов
     */
    std::vector<Entry> GetWordCount(const std::string &word);

    std::map<std::string, std::vector<Entry>> getDictionary();

    int countWordsInStr(const std::string& word, const std::string& str);

    std::vector<std::string> getDocs();



private:

    std::map<std::string, std::vector<Entry>> freq_dictionary; // частотный словарь
    std::vector<std::string> docs;


    static std::set<std::string> getWordsBaseFromDoc(const std::vector<std::string>& data) {
        std::vector<std::thread> threads;
        for (auto& str: data) {
            threads.push_back(std::thread(getWordsFromFile, std::ref(str)));
        }
        for (auto& thr: threads) {
            thr.join();
        }
        return wordsBase;
    }

    static void getWordsFromFile(const std::string& str) {
        std::string word;
        for (auto &c: str) {
            if ((c == ' ' || c == '\n') && word.length() != 0) {
                locker.lock();
                wordsBase.insert(word);
                locker.unlock();
                word.clear();
                continue;
            }
            word += (char)tolower(c);
        }
        if (word.length() != 0) {
            locker.lock();
            wordsBase.insert(word);
            locker.unlock();
        }
    }


};