#include <iostream>
#include "lz78.hpp"

template <typename T>
std::ostream &operator <<(std::ostream &stream, const std::vector<T> &v){
    for (const auto &i : v){
        stream << i << " ";
    }
    return stream;
}

int main() {

    std::vector<std::string> s = {"22", "1", "a", "c", "a", "b", "a"};

    auto encode = lz78_Encode(s);

    for (auto &i: encode) {
        std::cout << std::get<0>(i) << " " << std::get<1>(i) << "\n"; 
    }

    std::vector<std::string> decode = lz78_Decode(encode);
    std::cout << decode << "\n";

    return 0;
}