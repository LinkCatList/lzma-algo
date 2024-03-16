#include <iostream>
#include "lz78.hpp"

int main() {

    std::vector<std::string> s = {"a", "b", "a", "c", "a", "b", "a"};

    auto encode = lz78_Encode(s);

    for (auto &i: encode) {
        std::cout << std::get<0>(i) << " " << std::get<1>(i) << "\n"; 
    }

    std::string decode = lz78_Decode(encode);
    std::cout << decode << "\n";

    return 0;
}