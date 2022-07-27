#include <iostream>
#include <vector>
#include <memory>
#include <unordered_set>
#include <filesystem>

namespace fs = std::filesystem;

void task1() {
    for (auto i: {1, 2, 3, 4, 5}) {
        std::cout << i << std::endl;
    }
}

void task2() {
    auto filter = [](std::vector<int> &list) {
        std::unordered_set<int> set;
        std::vector<int> var;
        for (auto i: list) {
            if (set.count(i) == 0) {
                set.insert(i);
                var.push_back(i);
            }
        }
        list = var;
        return std::make_unique<std::vector<int>>(list);
    };

    std::vector<int> list = {1, 1, 2, 3, 1, 3, 5, 6, 8, 2, 7, 8, 2, 6, 4, 6};
    std::unique_ptr<std::vector<int>> uniqueVec = filter(list);
    for (auto it: *uniqueVec) {
        std::cout << it << " ";
    }
}

void task3() {
    std::filesystem::path p;
    auto recursiveGetFileNamesByExtension =
            [](std::filesystem::path path,
               const std::string extension) {
                std::vector<std::string> vec;
                for (auto item: fs::recursive_directory_iterator(path)) {
                    if (item.is_regular_file())
                        if (item.path().extension() == extension)
                            vec.push_back(item.path().string());
                }
                return vec;
            };

    for (auto it: recursiveGetFileNamesByExtension("D:\\Games", ".exe")) {
        std::cout << it << std::endl;
    }
}


int main() {
    task1();
    return 0;
}
