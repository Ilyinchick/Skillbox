#include <iostream>
#include <vector>


template<typename S1, typename S2>
struct Some {
    S1 first;
    S2 second;

    Some(S1 _first, S2 _second) {
        first = _first;
        second = _second;
    }
};

template<typename S1, typename S2>
void add(std::vector<Some<S1, S2>> &vec, Some<S1, S2> el) {
    vec.push_back(el);
}

template<typename S1, typename S2>
void remove(std::vector<Some<S1, S2>> &vec, S1 el) {
    std::vector<Some<S1, S2>> varVec;
    for (Some<S1, S2> s: vec) {
        if (s.first != el) varVec.push_back(s);
    }
    vec = varVec;
}

template<typename S1, typename S2>
void print(std::vector<Some<S1, S2>> &vec) {
    for (Some<S1, S2> s: vec) {
        std::cout << s.first << " - " << s.second << std::endl;
    }
    std::cout << std::endl;
}

template<typename S1, typename S2>
void find(std::vector<Some<S1, S2>> &vec, S1 el) {
    for (Some<S1, S2> s: vec) {
        if (s.first == el) std::cout << s.second << std::endl;
    }
}



int main() {

    // int
    std::vector<Some<int, double>> vec;
    add(vec, Some<int, double>(1, 10));
    add(vec, Some<int, double>(2, 20.2));
    add(vec, Some<int, double>(3, 30));
    add(vec, Some<int,double >(3, 40));
    print(vec);
    remove(vec, 1);
    print(vec);
    find(vec, 3);

    // double
    std::vector<Some<double, float>> vec2;
    add(vec2, Some<double, float>(1.0, 10.3));
    add(vec2, Some<double, float>(2.0, 20.4));
    add(vec2, Some<double, float>(3.0, 30.5));
    add(vec2, Some<double, float>(3.0, 40.12));
    print(vec2);
    remove(vec2, 1.0);
    print(vec2);
    find(vec2, 3.0);

    // std::string
    std::vector<Some<std::string, std::string>> vec3;
    add(vec3, Some<std::string, std::string>("_1", "10+"));
    add(vec3, Some<std::string, std::string>("_2", "20+"));
    add(vec3, Some<std::string, std::string>("_3", "30-"));
    add(vec3, Some<std::string, std::string>("_3", "40_word"));
    print(vec3);
    remove(vec3, (std::string)"_1");
    print(vec3);
    find(vec3, (std::string)"_3");
    return 0;
}
