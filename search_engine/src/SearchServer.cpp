#include "../include/SearchServer.h"

std::vector<std::vector<RelativeIndex>> SearchServer::search(const std::vector<std::string> &queries_input) {

    std::vector<std::vector<RelativeIndex>> answers;

    for (auto &query: queries_input) {
        std::vector<RelativeIndex> vec = getRelativeVectorForQuery(query);
        // if this query's relative is not null
        // if (!vec.empty())
        answers.push_back(vec);
    }

    for (auto& vecs: answers) {
        bubbleSortByRelevance(vecs);
    }
    return answers;
}

std::vector<std::string> SearchServer::getWordsFromString(const std::string &str) {
    std::vector<std::string> words;

    std::string word;
    for (auto &c: str) {
        if ((c == ' ' || c == '\n') && word.length() != 0) {
            words.push_back(word);
            word.clear();
            continue;
        }
        word += (char) tolower(c);
    }
    if (word.length() != 0) words.push_back(word);

    return words;
}

std::vector<RelativeIndex> SearchServer::getRelativeVectorForQuery(const std::string &query) {
    std::vector<RelativeIndex> indexes;
    for (int i = 0; i < _index.getDocs().size(); i++) {
        RelativeIndex idx = getIndexForQueryForDoc(query, i);
        // if rank is not null for this doc
        if (idx.rank > 0)
            indexes.push_back(idx);
    }
    return indexes;
}


RelativeIndex SearchServer::getIndexForQueryForDoc(const std::string &query, const int &doc_id) {
    RelativeIndex index;

    std::vector<std::string> words = getWordsFromString(query);

    // init array with zeros
    float rank[words.size()];
    for (auto &f: rank) f = 0;


    for (int i = 0; i < words.size(); i++) {

        if (_index.getDictionary().count(words[i]) > 0) {    // if word is found
            int totalCount = 0;
            for (auto &entry: _index.getDictionary().find(words[i])->second) {
                totalCount += entry.count;
                if (entry.doc_id == doc_id) rank[i] += (float) entry.count;
            }

            if (totalCount != 0) rank[i] /= (float) totalCount;

        } else {    //  if no such word in dictionary
            rank[i] = 0;
        }
    }

    float queryRank = 0.f;
    for (auto i: rank) {
            queryRank += i;
    }
    index.doc_id = doc_id;
    index.rank = queryRank;

    return index;
}

void SearchServer::bubbleSortByRelevance(std::vector<RelativeIndex>& vector) {
    if (vector.size() < 2) return;
    for (int i = 0; i < vector.size() - 1; i++) {
        for (int j = 0; j < vector.size() - 1; j++) {
            if (vector[j].rank < vector[j+1].rank) {
                std::swap(vector[j], vector[j+1]);
            }
        }
    }
}


