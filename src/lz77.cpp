#include <iostream>
#include "lz77.hpp"

int main() {

    std::string s;
    std::cin >> s;

    auto ans = lz77(s);

    for (auto &i: ans) {
        std::cout << std::get<0>(i) << " " << std::get<1>(i) << " " << std::get<2>(i) << "\n"; 
    }
    return 0;
}