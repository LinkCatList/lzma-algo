#include <iostream>
#include "lz78.hpp"

int main() {

    std::string s;
    std::cin >> s;

    auto ans = lz78(s);

    for (auto &i: ans) {
        std::cout << std::get<0>(i) << " " << std::get<1>(i) << "\n"; 
    }
    return 0;
}