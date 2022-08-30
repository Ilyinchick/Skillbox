#include "../include/ConverterJSON.h"
#include "../include/fs_exception.h"
#include "../include/InvertredIndex.h"
#include "../include/SearchServer.h"

#include <thread>



int main() {
    ConverterJSON converter;
    InvertedIndex index;

    converter.testFilesForValid();
    index.UpdateDocumentBase(converter.GetTextDocuments());

    SearchServer server(index);

//    for (auto wt: index.getDictionary()) {
//        std::cout << wt.first << ":" << std::endl;
//        for (auto data: wt.second) {
//            std::cout << data.doc_id << " - " << data.count << std::endl;
//        }
//    }

    auto answers = server.search(converter.GetRequests());

    converter.putAnswers(answers);

    return 0;
}
